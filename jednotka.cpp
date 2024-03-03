#include "jednotka.h"
#include <QFile>
#include <QTextStream>
#include <QString>

Jednotka::Jednotka(QString jmeno, QString kategorie, QString ulice, QString obec, QString stat, QString PSC) {
    this->jmeno = jmeno;
    this->kategorie = kategorie;
    this->ulice = ulice;
    this->obec = obec;
    this->stat = stat;
    this->PSC = PSC;
    Ulozit();


}

// Uložení jednotky do configu
void Jednotka::Ulozit(){
    // Vytvor config soubor
    QFile ConfigFile(ConfigFileName);
    if (ConfigFile.exists())
        QFile::remove(ConfigFileName);

    // Uloz do configu
    if (ConfigFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&ConfigFile);
        stream << "<Jednotka>" << '\n';
        stream << "<Jmeno>" << '\n' << this->jmeno << "\n";
        stream << "<Kategorie>" << '\n' << this->kategorie << "\n";
        stream << "<Ulice>" << '\n' << this->ulice << "\n";
        stream << "<Obec>" << '\n' << this->obec << "\n";
        stream << "<Stat>" << '\n' << this->stat << "\n";
        stream << "<PSC>" << '\n' << this->PSC << "\n";
        stream.flush();
        ConfigFile.close();
    }
}
