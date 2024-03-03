#include <Qstring>
#ifndef JEDNOTKA_H
#define JEDNOTKA_H

extern QString ConfigFileName;

class Jednotka
{
public:
    QString jmeno;
    QString kategorie;
    QString ulice;
    QString obec;
    QString stat;
    QString PSC;

    Jednotka(QString jmeno, QString kategorie, QString ulice, QString obec, QString stat, QString PSC);
    void Ulozit();
};

#endif // JEDNOTKA_H
