#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QSharedPointer>
#include <QFileDialog>
#include <QObject>
#include <QListWidget>
#include <QList>
#include <QKeyEvent>
#include <QLayoutItem>
#include <QTimer>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTextToSpeech>
#include <QMap>
#include <QCloseEvent>
#include <QGroupBox>
#include <QWidget>
#include <QUrl>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QVariant>

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <windows.h>

#include "jednotka.h"
#include "technika.h"
#include "clen.h"
#include "technika_status_window.h"
#include "clen_status_window.h"
#include "vyjezd.h"

extern QString ConfigFileName;
extern QString vyjezdy_path;
extern bool is_vyjezd;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Config_UI_change(bool fileExists);
    void Iniciace_vyjezdu(QString zprava);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

    void on_exitButton_clicked();

    void on_toggleButton_clicked();

    void on_zalozjednotkuButton_clicked();

    void on_pushButton_zrusit_clicked();

    void on_comboBox_kategorie_activated(int index);

    void on_pushButton_potvrdit_clicked();

    void on_smazjednotkuButton_clicked();

    void on_upravjednotkuButton_clicked();

    void on_pushButton_technika_clicked();

    void on_pushButton_technika_zrusit_clicked();

    void on_pushButton_technika_obrazek_clicked();

    void on_pushButton_technika_potvrdit_clicked();

    void on_listWidget_technika_itemClicked(QListWidgetItem *item);

    void on_pushButton_odstranit_techniku_clicked();

    void on_listWidget_technika_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_technika_upravit_clicked();

    void on_pushButton_clenove_clicked();

    void on_pushButton_clenove_zrusit_clicked();

    void on_pushButton_clenove_obrazek_clicked();

    void on_pushButton_clenove_potvrdit_clicked();

    void on_listWidget_clenove_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_clenove_itemClicked(QListWidgetItem *item);

    void on_pushButton_odstranit_clena_clicked();

    void on_pushButton_clenove_upravit_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    std::unique_ptr<Jednotka> jednotka;
    std::unique_ptr<Vyjezd> vyjezd;
    //std::unique_ptr<Technika> technika;
    QString filename;
    std::vector<std::unique_ptr<Technika>> Technika_vector;
    std::vector<std::unique_ptr<Clen>> Clenove_vector;
    QString memory;
    QTimer odecet;
    QMediaPlayer *bell;
    QMediaPlayer *gong;
    QAudioOutput *audio_output;
    QTextToSpeech *tts;
    QListWidgetItem *Clen_memory;
    int initialSeconds;
    QMap<QString, QString> Udalost_zkratky;
    QMap<QString, QString> Obce;


    void on_startup();
    void Uloz_technika();
    void JednotkaWindowCleanUp();
    void TechnikaWindowCleaUp();
    void ClenWindowCleanUp();
    void LCDSet(QString kategorie);
    void Layout_clear(QLayout *layout);
    void Clenove_window_set();
    void LabelyUdalosti_default();
    QString Nahrazeni_udalost();
    void Vyjezd_deletion();
    void Audio();
    void TTS_Audio();

signals:
    //void setCenterPosition(QVariant,QVariant);
    //void setLocationMarking(QVariant,QVariant);

};
#endif // MAINWINDOW_H
