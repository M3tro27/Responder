#include "technika.h"

Technika::Technika(QString nazev, QString zkratka, QString vznak, QString RZ, QString image_path) {
    Create_window();
    Set_udaje(nazev, zkratka, vznak, RZ, image_path);
}

// Uložení techniky do configu
void Technika::Ulozit_techniku(QString ConfigFileName) {
    QFile ConfigFile(ConfigFileName);

    if (ConfigFile.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&ConfigFile);
        stream << "\n" << "<Technika>" << "\n";
        stream << "<Nazev>" << "\n" << this->nazev << "\n";
        stream << "<Zkratka>" << "\n" << this->zkratka << "\n";
        stream << "<VZnak>" << "\n" << this->vznak << "\n";
        stream << "<RZ>" << "\n" << this->RZ << "\n";
        stream << "<Obrazek>" << "\n" << this->image_path << "\n";
        stream.flush();
    }
}

// Vytvoření status widgety
void Technika::Create_window() {
    technika_window = std::make_unique<Technika_status_window>(nullptr);
}

// Hromadné nastavení údajů
void Technika::Set_udaje(QString nazev, QString zkratka, QString vznak, QString RZ, QString image_path) {
    this->nazev = nazev;
    this->zkratka = zkratka;
    this->vznak = vznak;
    this->RZ = RZ;
    if (image_path == "") { this->image_path = ":/firetruck.png"; } else {
        this->image_path = image_path; }

    technika_window->setUdaje(nazev, vznak, RZ, image_path);
}

