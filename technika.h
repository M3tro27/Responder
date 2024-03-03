#ifndef TECHNIKA_H
#define TECHNIKA_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "technika_status_window.h"

class Technika
{
public:
    QString nazev, zkratka, vznak, RZ, obrazek, image_path;
    std::unique_ptr<Technika_status_window> technika_window; // Status widgeta techniky

    Technika(QString nazev, QString zkratka, QString vznak, QString RZ, QString image_path);
    void Ulozit_techniku(QString ConfigFileName);
    void Create_window();
    void Set_udaje(QString nazev, QString zkratka, QString vznak, QString RZ, QString image_path);

};

#endif // TECHNIKA_H
