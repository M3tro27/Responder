#include "clen.h"

//Popisky k jednotlivých proměným v headeru
Clen::Clen(QListWidget *parent, QString jmeno, QString prijmeni, QString image_path, bool velitel, bool strojnik)
    : clen_window(std::make_unique<Clen_status_window>(nullptr))
    , Clen_widget_item(new QListWidgetItem)
    , parent(parent) {
    /*clen_window = std::make_unique<Clen_status_window>(nullptr);
    Clen_widget_item = new QListWidgetItem;
    this->parent = parent; */
    Set_udaje(jmeno, prijmeni, image_path, velitel, strojnik);
}

// Při smazání objektu vymaže položku z listu
Clen::~Clen() {
    parent->removeItemWidget(Clen_widget_item);
    delete Clen_widget_item;
}

// Uložení dat do configu
void Clen::Ulozit_clena(QString ConfigFileName) {
    QFile ConfigFile(ConfigFileName);

    if (ConfigFile.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&ConfigFile);
        stream << "\n" << "<Clen>" << "\n";
        stream << "<Jmeno>" << "\n" << jmeno << "\n";
        stream << "<Prijmeni>" << "\n" << prijmeni << "\n";
        stream << "<Velitel>" << "\n" << velitel << "\n";
        stream << "<Strojnik>" << "\n" << strojnik << "\n";
        stream << "<Obrazek>" << "\n" << image_path << "\n";
        stream.flush();
    }
}

// Vytvoří status window
void Clen::Create_window() {
    clen_window = std::make_unique<Clen_status_window>(nullptr);
}

// Setter, pro hromadné nastavení všech údajů
void Clen::Set_udaje(QString jmeno, QString prijmeni, QString image_path, bool velitel, bool strojnik) {
    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    if (image_path == "") { this->image_path = ":/firefighter.jpg"; } else {
        this->image_path = image_path; }
    this->velitel = velitel;
    this->strojnik = strojnik;
    Clen_widget_item->setText(prijmeni + " " + jmeno);
    parent->addItem(Clen_widget_item);

    clen_window->setUdaje(this->jmeno, this->prijmeni, this->image_path);
}

// Nastavení statusu
void Clen::Set_status(QString status) {
    stat = status;
    if (status == "ve_sluzbe") { clen_window->setColor(); }
    else if (status == "mimo_sluzbu" || status == "nejedu") { clen_window->setColor("red"); }
    else if (status == "nepripojeno" || status == "neodpovezeno") { clen_window->setColor("yellow"); }
    else if (status == "jedu") { clen_window->setColor("green");}
}

// Getter statusu
QString Clen::Get_status() {
    return stat;
}
