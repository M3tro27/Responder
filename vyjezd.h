#ifndef VYJEZD_H
#define VYJEZD_H

#include <QList>
#include <QString>
#include <QDebug>

class Vyjezd
{
public:
    QList<QString> vozidla;
    QString stupen = "I.st." /* defaultní hodnota pro výjezd */, datum, cas, udalost, obec, adresa, popis_mista, popis_mo;

    Vyjezd(QString zprava);
};

#endif // VYJEZD_H
