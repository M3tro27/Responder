#include "technika_status_window.h"

// Rozložení a vzhled
Technika_status_window::Technika_status_window(QWidget *parent)
    : QFrame{parent}
{
    hlayout = new QHBoxLayout(this);
    vlayout = new QVBoxLayout;

    label_obrazek = new QLabel(this);
    label_nazev = new QLabel(this);
    label_vznak = new QLabel(this);
    label_RZ = new QLabel(this);

    hlayout->addWidget(label_obrazek);
    label_obrazek->setFixedWidth(this->width()/2);

    hlayout->setAlignment(Qt::AlignTop);
    hlayout->addLayout(vlayout);

    vlayout->addWidget(label_nazev);
    label_nazev->setStyleSheet("color: white;"
                               "background-color: #0C0C12;"
                               "font: bold 20px;");

    vlayout->addWidget(label_vznak);
    label_vznak->setStyleSheet("color: #636363;"
                               "background-color: #0C0C12;"
                               "font-size: 15px;");

    vlayout->addWidget(label_RZ);
    label_RZ->setStyleSheet("color: #636363;"
                            "background-color: #0C0C12;"
                            "font-size: 15px;");

    vlayout->setAlignment(Qt::AlignTop);
    setLayout(hlayout);
}

// Nevyužitá funkce, v budoucnu teoreticky označování zda-li je technika v provozu / při výjezdu jestli vyjela atd
void Technika_status_window::setColor(QString color)
{
    setStyleSheet("background-color: " + color + ";");
    label_nazev->setStyleSheet(label_nazev->styleSheet() + "background-color: " + color + ";");
    label_vznak->setStyleSheet(label_vznak->styleSheet() + "background-color: " + color + ";" + "color: black");
    label_RZ->setStyleSheet(label_RZ->styleSheet() + "background-color: " + color + ";" + "color: black");
}

// Nastavení údajů widgety
void Technika_status_window::setUdaje(QString nazev, QString vznak, QString RZ, QString image_path)
{
    label_nazev->setText(nazev);
    label_vznak->setText(vznak);
    label_RZ->setText(RZ);

    QPixmap image;
    bool valid = image.load(image_path);
    if(valid){
        image = image.scaledToWidth(label_obrazek->width(), Qt::SmoothTransformation);
        label_obrazek->setPixmap(image);
    }
}
