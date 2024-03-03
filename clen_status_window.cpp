#include "clen_status_window.h"

// Rozložení widgety
Clen_status_window::Clen_status_window(QWidget *parent)
    : QFrame{parent}
{
    vlayout = new QVBoxLayout(this);

    label_obrazek = new QLabel(this);
    label_jmeno = new QLabel(this);
    label_prijmeni = new QLabel(this);

    vlayout->addWidget(label_obrazek);
    vlayout->addWidget(label_prijmeni);
    vlayout->addWidget(label_jmeno);

    setLayout(vlayout);
}

// Nastavení barvy - overloaded funkce, bez inputu defaultní barva, jinak barvu upraví podle inputu
void Clen_status_window::setColor(QString color) {
    setStyleSheet("background-color: " + color + ";");
    label_jmeno->setStyleSheet("background-color: " + color + ";"
                                                              "color: black;"
                                                              "font-size: 12px;");
    label_prijmeni->setStyleSheet("background-color: " + color + ";"
                                                                 "color: black;"
                                                                 "font: bold 15px;");
}

void Clen_status_window::setColor() {
    setStyleSheet("background-color: #0C0C12;");
    label_prijmeni->setStyleSheet("color: white;"
                                  "background-color: #0C0C12;"
                                  "font: bold 15px;");
    label_jmeno->setStyleSheet("color: #636363;"
                               "background-color: #0C0C12;"
                               "font-size: 12px;");
}

// Nastavení údaje ve widgete
void Clen_status_window::setUdaje(QString jmeno, QString prijmeni, QString obrazek)
{
    label_jmeno->setText(jmeno);
    label_prijmeni->setText(prijmeni);

    QPixmap image;
    bool valid = image.load(obrazek);
    if(valid){
        image = image.scaled(75, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label_obrazek->setPixmap(image);
    }
}
