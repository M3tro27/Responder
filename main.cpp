#include "mainwindow.h"
#include "jednotka.h"

#include <QApplication>
#include <QTimer>
#include <QFile>
#include <QStandardPaths>

#include <windows.h>

QString responder_path = QDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)).filePath("Responder User Data");
QString ConfigFileName = responder_path + "/config.txt";
QString vyjezdy_path = responder_path + "/Výjezdy/vyjezd.txt";

bool is_vyjezd = false;

// Detekování výjezdu
void Vyjezd_detector(MainWindow* w) {
    if (is_vyjezd) {
        return;
    }

    if (QFile::exists(vyjezdy_path)) {
        is_vyjezd = true;
        QFile SMS(vyjezdy_path);

        if (SMS.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&SMS);
            QString zprava = in.readAll();
            SMS.close();
            w->Iniciace_vyjezdu(zprava);
        }
    }
}

// Funkce timeru pro detekování výjezdu a změny UI - experiment s umístěním mimo MainWindow.cpp
void TimerTimeOut(MainWindow* w) {
    Vyjezd_detector(w);
    w->Config_UI_change(QFileInfo::exists(ConfigFileName));

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTimer* timer = new QTimer();

    QObject::connect(timer,
                     &QTimer::timeout,
                     &w,
                     [&w]() { TimerTimeOut(&w); });

    timer->start(500);

    QDir directory(responder_path);

    // Založení User data
    if (!directory.exists()) {
        directory.mkpath(".");
        directory.mkdir("Výjezdy");
        directory.mkdir("Archiv");
    }

    w.showFullScreen();
    return a.exec();
}
