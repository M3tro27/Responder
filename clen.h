#ifndef CLEN_H
#define CLEN_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QListWidgetItem>

#include "clen_status_window.h"

class Clen
{
public:
    QString jmeno, prijmeni, image_path;
    bool velitel, strojnik;
    std::unique_ptr<Clen_status_window> clen_window; // Objekt pro widget člena, který se zobrazuje v UI
    QListWidgetItem *Clen_widget_item; // Objekt widget listu - přidává se do listu v UI, experiment s fungováním - lepší než u techniky, nestihl jsem předělat

    Clen(QListWidget *parent, QString jmeno, QString prijmeni, QString image_path, bool velitel, bool strojnik);
    ~Clen();
    void Ulozit_clena(QString ConfigFileName);
    void Create_window();
    void Set_udaje(QString jmeno, QString prijmeni, QString image_path, bool velitel, bool strojnik);
    void Set_status(QString status);
    QString Get_status();

private:
    QString stat;
    QListWidget *parent; // Pointer na list do kterého přidávám Widget Item
};

#endif // CLEN_H
