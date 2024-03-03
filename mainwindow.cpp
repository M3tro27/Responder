#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-color: #0C0C12;");

    //Label udalosti
    ui->labelUdalost->setStyleSheet("background-color: yellow");
    ui->labelUdalost->setText("Nastavte jednotku!");

    //Label lokace
    ui->labelLokace->setStyleSheet("background-color: #B70000");

    // Labely dodatecne
    ui->label_datum->setStyleSheet("background-color: white");
    ui->label_cas->setStyleSheet("background-color: white");
    ui->label_poznamka->setStyleSheet("background-color: white");
    ui->label_popis->setStyleSheet("background-color: white");


    //Side Bar
    ui->verticalWidget->setStyleSheet("background-color: #0F0F0F");
    ui->verticalWidget->hide();
    ui->centralwidget->installEventFilter(this);

        //Vyvtvor jednotku button
    ui->zalozjednotkuButton->setStyleSheet("background-color: white");

        //Uprav jednotku button
    ui->upravjednotkuButton->setStyleSheet("background-color: white");

        //Smaz jednotku button
    ui->smazjednotkuButton->setStyleSheet("background-color: white");

        //Exit button icon
    ui->exitButton->setStyleSheet("background-color: red");


    //Odecet lcdNumber
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->display("00:00");
    ui->lcdNumber->setStyleSheet("color: white; background-color: black");

    //Mapa quickWidgetMap
    ui->quickWidgetMap->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));
    ui->quickWidgetMap->show();

    /* Zkouška na propojení Cpp s QML - nefunčkní
    QObject::connect(this,
                     SIGNAL(setCenterPosition(QVariant,QVariant)),
                     ui->quickWidgetMap->rootObject(),
                     SLOT(setCenterPosition(QVariant,QVariant)));
    QObject::connect(this,
                     SIGNAL(setLocationMarking(QVariant,QVariant)),
                     ui->quickWidgetMap->rootObject(),
                     SLOT(setLocationMarking(QVariant,QVariant)));

    emit setCenterPosition(49.29019, 16.57822);
    emit setLocationMarking(49.29019, 16.57822);
    */

    // Jedntoka layout verticalWidget_jednotka
    ui->verticalWidget_jednotka->hide();
        // Jednotka lineEdit_jednotka
    ui->lineEdit_jednotka->setStyleSheet("background-color: white");
        // Kategorie comboBox_kategorie
    ui->comboBox_kategorie->setStyleSheet("background-color: white");
    ui->comboBox_kategorie->addItem("JPO I");
    ui->comboBox_kategorie->addItem("JPO II");
    ui->comboBox_kategorie->addItem("JPO III");
    ui->comboBox_kategorie->addItem("JPO IV");
    ui->comboBox_kategorie->addItem("JPO V");
    ui->comboBox_kategorie->addItem("JPO VI");
        //Pocet druzstev comboBox_druzstva
    ui->comboBox_druzstva->setStyleSheet("background-color: white");
    ui->comboBox_druzstva->addItem("1");
    ui->comboBox_druzstva->addItem("2");
    ui->comboBox_druzstva->hide();
        // Label Adresa label
    ui->label->setStyleSheet("color: white");
        // Ulice lineEdit_ulice
    ui->lineEdit_ulice->setStyleSheet("background-color: white");
        // Obec lineEdit_obec
    ui->lineEdit_obec->setStyleSheet("background-color: white");
        // Stat lineEdit_stat
    ui->lineEdit_stat->setStyleSheet("background-color: white");

            // Technika verticalWidget_technika
    ui->verticalWidget_technika->hide();
                // Nazev lineEdit_technika_nazev
    ui->lineEdit_technika_nazev->setStyleSheet("background-color: white");
                // Zkratka lineEdit_technika_zkratka
    ui->lineEdit_technika_zkratka->setStyleSheet("background-color: white");
                // Volaci znak lineEdit_technika_vznak
    ui->lineEdit_technika_vznak->setStyleSheet("background-color: white");
                // RZ lineEdit_technika_RZ
    ui->lineEdit_technika_RZ->setStyleSheet("background-color: white");
                // Pridat obrazek pushButton_technika_obrazek
    ui->pushButton_technika_obrazek->setStyleSheet("background-color: white");
                // Potvrdit button pushButton_technika_potvrdit
    ui->pushButton_technika_potvrdit->setStyleSheet("background-color: white");
                // Zrusit button pushButton_technika_zrusit
    ui->pushButton_technika_zrusit->setStyleSheet("background-color: red");

        // PSC lineEdit_PSC
    ui->lineEdit_PSC->setStyleSheet("background-color: white");

        // Pridat techniku pushButton_technika
    ui->pushButton_technika->setStyleSheet("background-color: white");
        // Odstranit techniku pushButton_odstranit_techniku
    ui->pushButton_odstranit_techniku->setStyleSheet("background-color: white");
    ui->pushButton_odstranit_techniku->setDisabled(true);
        // Upravit techniku pushButton_upravit_techniku
    ui->pushButton_technika_upravit->setStyleSheet("background-color: white");
    ui->pushButton_technika_upravit->hide();

    // Clenove verticalWidget_clenove
    ui->verticalWidget_clenove->hide();
    ui->pushButton_clenove_obrazek->setStyleSheet("background-color: white");

    ui->lineEdit_clenove_jmeno->setStyleSheet("background-color: white");
    ui->lineEdit_clenove_prijmeni->setStyleSheet("background-color: white");
    ui->checkBox_clenove_velitel->setStyleSheet("color: white");
    ui->checkBox_clenove_strojnik->setStyleSheet("color: white");
    ui->pushButton_clenove_potvrdit->setStyleSheet("background-color: white");
    ui->pushButton_clenove_upravit->setStyleSheet("background-color: white");
    ui->pushButton_clenove_upravit->hide();

    ui->pushButton_clenove_zrusit->setStyleSheet("background-color: red");

            // layout gridLayout_technika
        // Pridat clena pushButton_clenove
    ui->pushButton_clenove->setStyleSheet("background-color: white");
    ui->pushButton_odstranit_clena->setStyleSheet("background-color: white");
    ui->pushButton_odstranit_clena->setDisabled(true);



        // Povrdit pushButton_potvrdit
    ui->pushButton_potvrdit->setStyleSheet("background-color: white");
        // Zrusit pushButton_zrusit
    ui->pushButton_zrusit->setStyleSheet("background-color: red");


        //listWidget_technika
    ui->listWidget_technika->setStyleSheet("background-color: white");

        // listWidget_clenove
    ui->listWidget_clenove->setStyleSheet("background-color: white");

    MainWindow::on_startup();

    //Audio - Bell
    bell = new QMediaPlayer;
    audio_output = new QAudioOutput;

    bell->setAudioOutput(audio_output);
    bell->setSource(QUrl("qrc:/Bell sound.mp3"));

    audio_output->setVolume(50);

    //Timer pro LCD a Bell sound
    QObject::connect(&odecet,
                     &QTimer::timeout,
                     this,
                     [&](){

                         initialSeconds--;
                         // LCD pouze zobrazuje znaky, pro zobrazení času ve formátu MM:SS nutný tento kód - využit ChatGPTv3
                         ui->lcdNumber->display(QString("%1:%2").arg(initialSeconds / 60, 2, 10, QLatin1Char('0'))
                                                    .arg(initialSeconds % 60, 2, 10, QLatin1Char('0')));
                         if (initialSeconds == 0) {
                             odecet.stop();
                             bell->play();
                         }
                     });

    odecet.setInterval(1000);

    // Dekódování zkratek - v budoucnu funkce na načítání .csv zejména pro obce a ulice, výjezdové SMS neobsahují diakritiku
    Udalost_zkratky.insert("P", "Požár");
    Udalost_zkratky.insert("NB", "Nízké budovy");
    Udalost_zkratky.insert("VB", "Výškové budovy");
    Udalost_zkratky.insert("DP", "Dopravní prostředek");
    Udalost_zkratky.insert("TP", "Technická pomoc");
    Udalost_zkratky.insert("Strom", "Odstranění stromu");
    Udalost_zkratky.insert("Hmyz", "Likvidace hmyzu");
    Udalost_zkratky.insert("Cerpani", "Čerpání vody");
    Udalost_zkratky.insert("UNL", "Únik nebezpečných látek");
    Udalost_zkratky.insert("Vzduch", "Do ovzduší");
    Udalost_zkratky.insert("Voda", "Do vody");
    Udalost_zkratky.insert("Puda", "Do půdy");
    Udalost_zkratky.insert("ZOZ", "Záchrana osob a zvířat");
    Udalost_zkratky.insert("Prostor", "Uzavřený prostor");
    Udalost_zkratky.insert("DN", "Dopravní nehoda");
    Udalost_zkratky.insert("Trava", "Polní porost, tráva");

    Obce.insert("Ceska", "Česká");
    Obce.insert("Kurim", "Kuřim");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Funkce po startupu pro oddělení a zpřehlednění
void MainWindow::on_startup(){
    // Načtení configu ze souboru
    if (QFile::exists(ConfigFileName)){
        // Jednotka
        QString jmeno, kategorie, ulice, obec, stat, PSC;

        // Technika
        QString nazev, zkratka, vznak, RZ, image_path;

        // Clenove
        QString clen_jmeno, prijmeni, clen_image_path;
        bool velitel, strojnik;

        QFile ConfigFile(ConfigFileName);
        if (ConfigFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&ConfigFile);

            while (! in.atEnd()){
                QString line = in.readLine();
                if (line.contains("<Jmeno>")) {
                    jmeno = in.readLine().trimmed();
                }
                else if (line.contains("<Kategorie>")) {
                    kategorie = in.readLine().trimmed();
                }
                else if (line.contains("<Ulice>")) {
                    ulice = in.readLine().trimmed();
                }
                else if (line.contains("<Obec>")) {
                    obec = in.readLine().trimmed();
                }
                else if (line.contains("<Stat>")) {
                    stat = in.readLine().trimmed();
                }
                else if (line.contains("<PSC>")) {
                    PSC = in.readLine().trimmed();
                }

                else if (line.contains("<Technika>")){
                    while (line != "\n"){
                        line = in.readLine();
                        if (line.contains("<Nazev>")){
                            nazev = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<Zkratka>")){
                            zkratka = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<VZnak>")){
                            vznak = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<RZ>")){
                            RZ = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<Obrazek>")){
                            image_path = in.readLine().trimmed();
                        }
                        Technika_vector.push_back(std::make_unique<Technika>(nazev, zkratka, vznak, RZ, image_path));
                        break;
                    }
                }

                else if (line.contains("<Clen>")){
                    while (line != "\n"){
                        line = in.readLine();
                        if (line.contains("<Jmeno>")){
                            clen_jmeno = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<Prijmeni>")){
                            prijmeni = in.readLine().trimmed();
                            line = in.readLine();
                        }
                        if (line.contains("<Velitel>")){
                            if (in.readLine() == "1")
                                velitel = true;
                            else
                                velitel = false;
                            line = in.readLine();
                        }
                        if (line.contains("<Strojnik>")){
                            if (in.readLine() == "1")
                                strojnik = true;
                            else
                                strojnik = false;
                            line = in.readLine();
                        }
                        if (line.contains("<Obrazek>")){
                            clen_image_path = in.readLine().trimmed();
                        }
                        Clenove_vector.push_back(std::make_unique<Clen>(ui->listWidget_clenove, clen_jmeno, prijmeni, clen_image_path, velitel, strojnik));
                        break;
                    }
                }
            }
        }
        jednotka = std::make_unique<Jednotka>(jmeno, kategorie, ulice, obec, stat, PSC);
        LCDSet(jednotka->kategorie);
        Clenove_window_set();
    }
}


void MainWindow::on_exitButton_clicked()
{
    QCoreApplication::quit();
}

// Menu button
void MainWindow::on_toggleButton_clicked()
{
    if (ui->verticalWidget->isHidden()){
        ui->verticalWidget->show();
    }
    else {
        ui->verticalWidget->hide();
    }
}

void MainWindow::on_zalozjednotkuButton_clicked()
{
    ui->verticalWidget_jednotka->show();
}


void MainWindow::on_pushButton_zrusit_clicked()
{
    JednotkaWindowCleanUp();
    TechnikaWindowCleaUp();
    ClenWindowCleanUp();
}

// Zobrazení comboboxu družstva u vybraných kategorií JPO, pro JPO I - HZS ČR možnost přidat speciální combobox s kategorií stanic
void MainWindow::on_comboBox_kategorie_activated(int index)
{
    if (index == 1 || index == 2){
        ui->comboBox_druzstva->setCurrentIndex(-1);
        ui->comboBox_druzstva->show();
    }
    else{
        ui->comboBox_druzstva->setCurrentIndex(-1);
        ui->comboBox_druzstva->hide();
    }
}

// Založení jednotky, vytvoření objektu, uložení configu
void MainWindow::on_pushButton_potvrdit_clicked()
{
    QString kategorie;
    if (ui->comboBox_druzstva->currentIndex() == -1)
        kategorie = ui->comboBox_kategorie->currentText();
    else
        kategorie = ui->comboBox_kategorie->currentText() + "/" + ui->comboBox_druzstva->currentText();

    if (jednotka) {
        jednotka.reset();
    }
    jednotka = std::make_unique<Jednotka>(ui->lineEdit_jednotka->text(),
                      kategorie,
                      ui->lineEdit_ulice->text(),
                      ui->lineEdit_obec->text(),
                      ui->lineEdit_stat->text(),
                      ui->lineEdit_PSC->text());
    LCDSet(jednotka->kategorie);
    JednotkaWindowCleanUp();

    for (const auto& Technika_objekt  : Technika_vector){
        Technika_objekt->Ulozit_techniku(ConfigFileName);
    }
    TechnikaWindowCleaUp();

    for (const auto& Clen_objekt : Clenove_vector){
        Clen_objekt->Ulozit_clena(ConfigFileName);
    }
    ClenWindowCleanUp();

    Clenove_window_set();
}

// Smazání jednotky, techniky, členů, configu a vynulování UI
void MainWindow::on_smazjednotkuButton_clicked()
{
    jednotka.reset();
    Technika_vector.clear();
    Clenove_vector.clear();

    Clenove_window_set();

    QFile::remove(ConfigFileName);
    JednotkaWindowCleanUp();

    ui->lcdNumber->display("00:00");
    ui->labelUdalost->setText("Nastavte jednotku!");
    ui->labelLokace->clear();
    ui->label_datum->clear();
    ui->label_cas->clear();
    ui->label_popis->clear();
    ui->label_poznamka->clear();
}

// Úprava jednotky - zobrazení configu
void MainWindow::on_upravjednotkuButton_clicked()
{
    ui->lineEdit_jednotka->setText(jednotka->jmeno);

    // Kategorie
    if (jednotka->kategorie == "JPO I") {
        ui->comboBox_kategorie->setCurrentIndex(0);
        ui->comboBox_druzstva->hide();
    }
    else if (jednotka->kategorie == "JPO II/1") {
        ui->comboBox_kategorie->setCurrentIndex(1);
        ui->comboBox_druzstva->setCurrentIndex(0);
        ui->comboBox_druzstva->show();
    }
    else if (jednotka->kategorie == "JPO II/2") {
        ui->comboBox_kategorie->setCurrentIndex(1);
        ui->comboBox_druzstva->setCurrentIndex(1);
        ui->comboBox_druzstva->show();
    }
    else if (jednotka->kategorie == "JPO III/1") {
        ui->comboBox_kategorie->setCurrentIndex(2);
        ui->comboBox_druzstva->setCurrentIndex(0);
        ui->comboBox_druzstva->show();
    }
    else if (jednotka->kategorie == "JPO III/2") {
        ui->comboBox_kategorie->setCurrentIndex(2);
        ui->comboBox_druzstva->setCurrentIndex(1);
        ui->comboBox_druzstva->show();
    }
    else if (jednotka->kategorie == "JPO IV") {
        ui->comboBox_kategorie->setCurrentIndex(3);
        ui->comboBox_druzstva->hide();
    }
    else if (jednotka->kategorie == "JPO V") {
        ui->comboBox_kategorie->setCurrentIndex(4);
        ui->comboBox_druzstva->hide();
    }
    else if (jednotka->kategorie == "JPO VI") {
        ui->comboBox_kategorie->setCurrentIndex(5);
        ui->comboBox_druzstva->hide();
    }

    ui->lineEdit_ulice->setText(jednotka->ulice);
    ui->lineEdit_obec->setText(jednotka->obec);
    ui->lineEdit_stat->setText(jednotka->stat);
    ui->lineEdit_PSC->setText(jednotka->PSC);

    for (auto& Technika_objekt : Technika_vector){
        ui->listWidget_technika->addItem(Technika_objekt->nazev);
    }

    for (auto& Clen_objekt : Clenove_vector){
        ui->listWidget_clenove->addItem(Clen_objekt->Clen_widget_item);
    }

    LCDSet(jednotka->kategorie);
    ui->verticalWidget_jednotka->show();

}

void MainWindow::on_pushButton_technika_clicked()
{
    ClenWindowCleanUp();
    ui->verticalWidget_technika->show();
}

// Vynulování UI
void MainWindow::JednotkaWindowCleanUp(){
    ui->verticalWidget_jednotka->hide();
    ui->lineEdit_jednotka->clear();
    ui->comboBox_kategorie->setCurrentIndex(-1);
    ui->comboBox_druzstva->hide();
    ui->comboBox_druzstva->setCurrentIndex(-1);
    ui->lineEdit_ulice->clear();
    ui->lineEdit_obec->clear();
    ui->lineEdit_stat->clear();
    ui->lineEdit_PSC->clear();

    ui->listWidget_technika->clear();
}

void MainWindow::TechnikaWindowCleaUp(){
    ui->verticalWidget_technika->hide();
    ui->lineEdit_technika_nazev->clear();
    ui->lineEdit_technika_zkratka->clear();
    ui->label_technika_obrazek->clear();
    ui->lineEdit_technika_vznak->clear();
    ui->lineEdit_technika_RZ->clear();
    ui->pushButton_technika_upravit->hide();
    ui->pushButton_technika_potvrdit->show();
    filename.clear();
}

void MainWindow::ClenWindowCleanUp() {
    ui->verticalWidget_clenove->hide();
    ui->lineEdit_clenove_jmeno->clear();
    ui->lineEdit_clenove_prijmeni->clear();
    ui->checkBox_clenove_velitel->setChecked(false);
    ui->checkBox_clenove_strojnik->setChecked(false);
    ui->label_clenove_obrazek->clear();
    ui->pushButton_clenove_upravit->hide();
    ui->pushButton_clenove_potvrdit->show();
    filename.clear();
}


void MainWindow::on_pushButton_technika_zrusit_clicked()
{
    TechnikaWindowCleaUp();
}

// Nahrání obrázku pro techniku - stejné jako u členů, teoreticky by šlo užitím QObject::connect připojit na jednu funkci - nezkoušel jsem
void MainWindow::on_pushButton_technika_obrazek_clicked()
{
    filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *jpeg"));

    if(QString::compare(filename, QString()) != 0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            image = image.scaledToWidth(ui->label_technika_obrazek->width(), Qt::SmoothTransformation);
            ui->label_technika_obrazek->setPixmap(QPixmap::fromImage(image));
        }
    }
}

// Přidání techniky a vytvoření objektu
void MainWindow::on_pushButton_technika_potvrdit_clicked()
{
    Technika_vector.push_back(std::make_unique<Technika>(ui->lineEdit_technika_nazev->text(),
                                                                    ui->lineEdit_technika_zkratka->text(),
                                                                    ui->lineEdit_technika_vznak->text(),
                                                                    ui->lineEdit_technika_RZ->text(),
                                                                    filename));
    ui->listWidget_technika->addItem(ui->lineEdit_technika_nazev->text());
    ui->listWidget_technika->sortItems();
    TechnikaWindowCleaUp();
}


// Zobrazení okna techniky po kliknutí na objekt v Listu
void MainWindow::on_listWidget_technika_itemClicked(QListWidgetItem *item)
{
    ClenWindowCleanUp();
    for (auto& Technika_objekt  : Technika_vector){
        if (item->text() == Technika_objekt->nazev){
            ui->lineEdit_technika_nazev->setText(Technika_objekt->nazev);
            ui->lineEdit_technika_vznak->setText(Technika_objekt->vznak);
            ui->lineEdit_technika_zkratka->setText(Technika_objekt->zkratka);
            ui->lineEdit_technika_RZ->setText(Technika_objekt->RZ);

            memory = ui->lineEdit_technika_nazev->text();

            QPixmap image;
            bool valid = image.load(Technika_objekt->image_path);

            if(valid){
                image = image.scaledToWidth(ui->label_technika_obrazek->width(), Qt::SmoothTransformation);
                ui->label_technika_obrazek->setPixmap(image);
            }

            // Widget na zobrazení a přidání je stejný, pouze se mění tlačítko
            ui->pushButton_technika_potvrdit->hide();
            ui->pushButton_technika_upravit->show();
            ui->verticalWidget_technika->show();

        }
    }
    ui->pushButton_odstranit_techniku->setDisabled(false);
}

// Odstranění techniky
void MainWindow::on_pushButton_odstranit_techniku_clicked()
{
    if (ui->listWidget_technika->currentItem() == nullptr) {
        return;
    }

    QString itemName = ui->listWidget_technika->currentItem()->text();

    for (auto it = Technika_vector.begin(); it != Technika_vector.end();) {
        if ((*it)->nazev == itemName) {
            it = Technika_vector.erase(it);
            break;
        } else {
            ++it;
        }
    }

    delete ui->listWidget_technika->takeItem(ui->listWidget_technika->currentRow());
    TechnikaWindowCleaUp();
}

// Zpřístupnění odstranění pouze při označení techniky v listu
void MainWindow::on_listWidget_technika_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (ui->listWidget_technika->currentItem())
        ui->pushButton_odstranit_techniku->setEnabled(true);
    else
        ui->pushButton_odstranit_techniku->setEnabled(false);
}

// Úprava objektu techniky
void MainWindow::on_pushButton_technika_upravit_clicked()
{
    for (auto& Technika_objekt : Technika_vector){
        if (Technika_objekt->nazev == memory) {
            Technika_objekt->Set_udaje(ui->lineEdit_technika_nazev->text(),
                                       ui->lineEdit_technika_zkratka->text(),
                                       ui->lineEdit_technika_vznak->text(),
                                       ui->lineEdit_technika_RZ->text(),
                                       filename);
            break;
        }
    }
    ui->listWidget_technika->currentItem()->setText(ui->lineEdit_technika_nazev->text());
    TechnikaWindowCleaUp();
}
// Technika je starší než členové, u členů jsem využil trochu jinačí postup viz. jednotlivé classy

// Funkce u členů obdobné jako u techniky
void MainWindow::on_pushButton_clenove_clicked()
{
    TechnikaWindowCleaUp();
    ui->verticalWidget_clenove->show();
}


void MainWindow::on_pushButton_clenove_zrusit_clicked()
{
    ui->verticalWidget_clenove->hide();
    ClenWindowCleanUp();
}


void MainWindow::on_pushButton_clenove_obrazek_clicked()
{
    filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *jpeg"));

    if(QString::compare(filename, QString()) != 0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            image = image.scaledToWidth(ui->label_clenove_obrazek->width(), Qt::SmoothTransformation);
            ui->label_clenove_obrazek->setPixmap(QPixmap::fromImage(image));
        }
    }
}


void MainWindow::on_pushButton_clenove_potvrdit_clicked()
{
    Clenove_vector.push_back(std::make_unique<Clen>(ui->listWidget_clenove,
                                                            ui->lineEdit_clenove_jmeno->text(),
                                                            ui->lineEdit_clenove_prijmeni->text(),
                                                            filename,
                                                            ui->checkBox_clenove_velitel->isChecked(),
                                                            ui->checkBox_clenove_strojnik->isChecked()));

    ui->listWidget_clenove->sortItems();

    ClenWindowCleanUp();
}


void MainWindow::on_listWidget_clenove_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (ui->listWidget_clenove->currentItem())
        ui->pushButton_odstranit_clena->setEnabled(true);
    else
        ui->pushButton_odstranit_clena->setEnabled(false);
}


void MainWindow::on_listWidget_clenove_itemClicked(QListWidgetItem *item) {
    TechnikaWindowCleaUp();

    for (auto& Clen_objekt : Clenove_vector) {
        if (item->text() == Clen_objekt->Clen_widget_item->text()) {
            ui->lineEdit_clenove_jmeno->setText(Clen_objekt->jmeno);
            ui->lineEdit_clenove_prijmeni->setText(Clen_objekt->prijmeni);
            ui->checkBox_clenove_velitel->setChecked(Clen_objekt->velitel);
            ui->checkBox_clenove_strojnik->setChecked(Clen_objekt->strojnik);

            Clen_memory = Clen_objekt->Clen_widget_item;

            QPixmap image;
            bool valid = image.load(Clen_objekt->image_path);

            if(valid){
                image = image.scaledToWidth(ui->label_clenove_obrazek->width(), Qt::SmoothTransformation);
                ui->label_clenove_obrazek->setPixmap(image);
            }

            ui->pushButton_clenove_potvrdit->hide();
            ui->pushButton_clenove_upravit->show();
            ui->verticalWidget_clenove->show();
        }
    }


    /* Starý kód před úpravou
    TechnikaWindowCleaUp();
    for (auto& Clen_objekt  :Clenove_vector){
        if (item->text() == Clen_objekt->jmeno + " " + Clen_objekt->prijmeni){
            ui->lineEdit_clenove_jmeno->setText(Clen_objekt->jmeno);
            ui->lineEdit_clenove_prijmeni->setText(Clen_objekt->prijmeni);
            ui->checkBox_clenove_velitel->setChecked(Clen_objekt->velitel);
            ui->checkBox_clenove_strojnik->setChecked(Clen_objekt->strojnik);

            memory = ui->lineEdit_clenove_jmeno->text() + " " + ui->lineEdit_clenove_prijmeni->text();

            QPixmap image;
            bool valid = image.load(Clen_objekt->image_path);

            if(valid){
                image = image.scaledToWidth(ui->label_clenove_obrazek->width(), Qt::SmoothTransformation);
                ui->label_clenove_obrazek->setPixmap(image);
            }

            ui->pushButton_clenove_potvrdit->hide();
            ui->pushButton_clenove_upravit->show();
            ui->verticalWidget_clenove->show();

        }
    }

    ui->pushButton_odstranit_clena->setDisabled(false);
    */
}


void MainWindow::on_pushButton_odstranit_clena_clicked()
{
    QString jmenoprijmeni = ui->listWidget_clenove->currentItem()->text();

    // Experiment s jiným způsobem odstranění
    Clenove_vector.erase(std::remove_if(Clenove_vector.begin(),
                                        Clenove_vector.end(),
                                        [&jmenoprijmeni](const std::unique_ptr<Clen>& clen)
                                        {return (clen->Clen_widget_item->text() == jmenoprijmeni);}),
                         Clenove_vector.end());

    ClenWindowCleanUp();
}

// Nastavení LCD
void MainWindow::LCDSet(QString kategorie)
{
    if (kategorie == "JPO I" || kategorie == "JPO IV"){
        initialSeconds = 2 * 60;
    } else if (kategorie.contains("JPO II/")){
        initialSeconds = 5 * 60;
    } else {
        initialSeconds = 10 * 60;
    }

    ui->lcdNumber->display(QString("%1:%2").arg(initialSeconds / 60, 2, 10, QLatin1Char('0'))
                               .arg(initialSeconds % 60, 2, 10, QLatin1Char('0')));
}

//Mazání widget z layoutu je v Qt problematické - funkce pro vymazání layoutu
void MainWindow::Layout_clear(QLayout *layout) {
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        QWidget *widget = child->widget();

        if (widget) {
            layout->removeWidget(widget);
            widget->hide();
        }
    }
}

// Nastavení okénem s členy
void MainWindow::Clenove_window_set()
{
    Layout_clear(ui->horizontalLayout_velitele_show);
    Layout_clear(ui->horizontalLayout_strojnici_show);
    Layout_clear(ui->horizontalLayout_hasici_show);

    for (auto& Clen_objekt : Clenove_vector) {
        if (Clen_objekt->velitel == true) {
            ui->horizontalLayout_velitele_show->addWidget(Clen_objekt->clen_window.get());
            Clen_objekt->clen_window->show();
        } else if (Clen_objekt->strojnik == true && Clen_objekt->velitel == false) {
            ui->horizontalLayout_strojnici_show->addWidget(Clen_objekt->clen_window.get());
            Clen_objekt->clen_window->show();
        } else {
            ui->horizontalLayout_hasici_show->addWidget(Clen_objekt->clen_window.get());
            Clen_objekt->clen_window->show();
        }
    }

    ui->horizontalLayout_velitele_show->addStretch();
    ui->horizontalLayout_strojnici_show->addStretch();
    ui->horizontalLayout_hasici_show->addStretch();

}

// Defaultní text labelů v UI
void MainWindow::LabelyUdalosti_default()
{
    ui->labelUdalost->setText("Žádný výjezd");
    ui->labelLokace->setText("Dejte si kafe");
    ui->label_datum->setText(" Datum: ");
    ui->label_cas->setText(" Čas: ");
    ui->label_poznamka->setText(" Poznámka: ");
    ui->label_popis->setText(" Popis: ");

}

// Volání nahrazení události podle mapy
QString MainWindow::Nahrazeni_udalost() {
    QList<QString> udalost = vyjezd->udalost.split("-");

    return Udalost_zkratky.value(udalost[0]) + " " + Udalost_zkratky.value(udalost[1]);
}

// Vymazání výjezdu, vrácení do defaultního UI
void MainWindow::Vyjezd_deletion() {

    LabelyUdalosti_default();

    QFile::remove(vyjezdy_path);

    Layout_clear(ui->verticalLayout_technika_show);

    is_vyjezd = false;
    vyjezd.reset();

    LCDSet(jednotka->kategorie);
    Clenove_window_set();

    delete gong;
    delete tts;

}

// Nastavení UI
void MainWindow::Config_UI_change(bool fileExists)
{
    // Zobrazení tlačítek podle toho jestli config existuje
    ui->zalozjednotkuButton->setDisabled(fileExists);
    ui->upravjednotkuButton->setEnabled(fileExists);
    ui->smazjednotkuButton->setEnabled(fileExists);

    if (fileExists && !is_vyjezd){
        LabelyUdalosti_default();

        //Simulace pripojeni aplikace - funkce mimo_sluzbu
        for (auto &Clen_objekt : Clenove_vector) {
            if (QFile::exists(Clen_objekt->prijmeni + "_" + Clen_objekt->jmeno + ".txt")) {
                QFile pripojeni(Clen_objekt->prijmeni + "_" + Clen_objekt->jmeno + ".txt");

                if (pripojeni.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&pripojeni);
                    if (in.readLine() == "nejedu") {
                        Clen_objekt->Set_status("mimo_sluzbu");
                    } else { Clen_objekt->Set_status("ve_sluzbe"); }
                    pripojeni.close();
                }
            } else { Clen_objekt->Set_status("nepripojeno"); } // Simulace pripojeni aplikace - zarizeni nepripojeno
        }
    }
}

// Funkce přehrání audia při výjezdu
void MainWindow::Audio() {
    gong = new QMediaPlayer;

    gong->setAudioOutput(audio_output);
    gong->setSource(QUrl("qrc:/Gong sound.mp3"));
    gong->play();

    QObject::connect(gong,
                     &QMediaPlayer::mediaStatusChanged,
                     this,
                     [=](QMediaPlayer::MediaStatus status) {
                         if (status == QMediaPlayer::EndOfMedia) {
                             TTS_Audio();
                         }
                     });
}

// Pro větší přehlednost - Text to speech oddělen do solo funkce
void MainWindow::TTS_Audio() {
    tts = new QTextToSpeech;

    tts->setEngine("winrt"); // Nastavení enginu na Windows.Media.SpeechSynthesis Namespace
    tts->setLocale(QLocale::Czech); // Jazyk

    QList<QString> phrases; // Funkce say je asynchronní - nutnost vytvořit List a až při TTS stavu Ready čtení dalšího
    int currentIndex = 0;
    phrases << "Vaší jednotce byl vyhlášen požární poplach";
    if (Nahrazeni_udalost() == "") {
        phrases << vyjezd->udalost;
    } else { phrases << Nahrazeni_udalost(); }

    if (Obce.value(vyjezd->obec) == "") {
        phrases << vyjezd->obec;
    } else { phrases << Obce.value(vyjezd->obec); }


    if (vyjezd->stupen != "I.st.") {
        if (vyjezd->stupen == "II.st.") { phrases << "Druhý stupeň"; }
        else if (vyjezd->stupen == "III.st.") { phrases << "Třetí stupeň"; }
        else { phrases << "Neznámý stupeň"; }
    }

    phrases << "Vyjíždí";

    for (const QString &vozidlo : vyjezd->vozidla) {
        for (auto& Technika_objekt : Technika_vector) {
            if (vozidlo == Technika_objekt->zkratka) {
                phrases << Technika_objekt->nazev;
            }
        }
    }

    QObject::connect(tts,
                     &QTextToSpeech::stateChanged,
                     this,
                     [=](QTextToSpeech::State state) mutable {
                         if (state == QTextToSpeech::Ready) {
                             currentIndex++;
                             if (currentIndex < phrases.size()) {
                                tts->say(phrases[currentIndex]);
                             } else {
                                 QObject::disconnect(tts,
                                                     &QTextToSpeech::stateChanged,
                                                     this,
                                                     nullptr);
                             }
                         }
                     });
    tts->say(phrases[currentIndex]);
}

// Iniciace výjezdu
void MainWindow::Iniciace_vyjezdu(QString zprava) {
    vyjezd = std::make_unique<Vyjezd>(zprava); // Vytvoření objektu

    // Nastavení labelů
    ui->labelUdalost->setText(vyjezd->stupen + " " + vyjezd->udalost);
    ui->labelLokace->setText(vyjezd->obec + " " + vyjezd->adresa);
    ui->label_datum->setText(ui->label_datum->text() + vyjezd->datum);
    ui->label_cas->setText(ui->label_cas->text() + vyjezd->cas);
    ui->label_popis->setText(ui->label_popis->text() + vyjezd->popis_mista);
    ui->label_poznamka->setText(ui->label_poznamka->text() + vyjezd->popis_mo);

    // Zobrazení techniky
    for (const QString &vozidlo : vyjezd->vozidla) {
        for (auto& Technika_objekt : Technika_vector) {
            if (vozidlo == Technika_objekt->zkratka) {
                ui->verticalLayout_technika_show->addWidget(Technika_objekt->technika_window.get());
                Technika_objekt->technika_window->show();
            }
        }
    }

    odecet.start();
    Audio();

    // Simulace pripojeni aplikace - simulace vyjezdu
    for (auto &Clen_objekt : Clenove_vector) {
        if (Clen_objekt->Get_status() == "ve_sluzbe") {
            Clen_objekt->Set_status("neodpovezeno");
        }
    }
    QTimer *simulace = new QTimer;
    QObject::connect(simulace,
                     &QTimer::timeout,
                     this,
                     [&](){
                         int randomClen = std::rand() % Clenove_vector.size();
                         if (Clenove_vector[randomClen]->Get_status() == "neodpovezeno") {
                             if (std::rand() % 4 < 3) { Clenove_vector[randomClen]->Set_status("jedu"); }
                             else { Clenove_vector[randomClen]->Set_status("nejedu"); }
                         }
                     });
    simulace->setInterval(std::rand() % 501 + 500);
    simulace->start();
}

// Upravení objektu člena
void MainWindow::on_pushButton_clenove_upravit_clicked() {
    for (auto &Clen_objekt : Clenove_vector) {
        if (Clen_objekt->Clen_widget_item->text() == Clen_memory->text()) {
            Clen_objekt->Set_udaje(ui->lineEdit_clenove_jmeno->text(),
                                   ui->lineEdit_clenove_prijmeni->text(),
                                   filename,
                                   ui->checkBox_clenove_velitel->isChecked(),
                                   ui->checkBox_clenove_strojnik->isChecked());
            ui->listWidget_clenove->currentItem()->setText(Clen_objekt->Clen_widget_item->text());
            break;
        }
    }
    ClenWindowCleanUp();

    /* Starý kód
    for (auto& Clen_objekt : Clenove_vector){
        if (Clen_objekt->jmeno + " " + Clen_objekt->prijmeni == memory){
            Clen_objekt->jmeno = ui->lineEdit_clenove_jmeno->text();
            Clen_objekt->prijmeni = ui->lineEdit_clenove_prijmeni->text();
            Clen_objekt->velitel = ui->checkBox_clenove_velitel->isChecked();
            Clen_objekt->strojnik = ui->checkBox_clenove_strojnik->isChecked();
            Clen_objekt->image_path = filename;
            break;
        }
    }
    ui->listWidget_clenove->currentItem()->setText(ui->lineEdit_clenove_jmeno->text() + " " + ui->lineEdit_clenove_prijmeni->text());
    ClenWindowCleanUp();
*/
}

// Event filtry pro detekování kláves a myši
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // Schování Menu při kliknutí mimo
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!ui->verticalWidget->geometry().contains(mouseEvent->pos())) {
            ui->verticalWidget->hide();
            ui->verticalWidget_technika->hide();
        }
    }

    // Zrušení výjezdu při stisknutí ESC
    if (is_vyjezd == true && event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            Vyjezd_deletion();
            odecet.stop();
        }
    }
    return QMainWindow::eventFilter(obj, event);
}
