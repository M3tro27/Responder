#include "vyjezd.h"

// Parsování zprávy, input je vzorově vždy stejný
/* Ukázkový příklad:
 * VYJEZD PRO: 1V, 2V, III.st. 19.07.2023 22:18:00, P-Trava, Bykovice; P travy a keru
 */
Vyjezd::Vyjezd(QString zprava)
{
    QList<QString> stupen_datum_cas;
    QList<QString> mo;
    zprava.remove(0,11); // Odstranění "VYJEZD PRO: " z inputu
    QList<QString>zprava_list = zprava.split(";");
    bool datum_cas_nalez = false;

    popis_mo = zprava_list[1].trimmed(); // Za středníkem vždy popis mimořádné události
    zprava_list.removeAt(1);

    zprava = zprava_list[0]; // Uložení zprávy do proměný
    zprava_list = zprava.split(",");

    // Ukládání techniky dokud string neobsahuje dvojtečku - stupeň, datum a čas
    for (const auto& string : zprava_list){
        QString trimmstring = string.trimmed();

        if (trimmstring.contains(":")){
            stupen_datum_cas = trimmstring.split(" ");
            datum_cas_nalez = true;
            continue;
        }

        if (!datum_cas_nalez) {
            vozidla.append(trimmstring);
            } else {
            mo.append(trimmstring);
        }
    }

    // pokud list obsahuje tři prvky - v SMS definován i stupeň, když ne zůstává defaultní
    if (stupen_datum_cas.size() == 3) {
        stupen = stupen_datum_cas[0];
        datum = stupen_datum_cas[1];
        cas = stupen_datum_cas[2];
    } else {
        datum = stupen_datum_cas[0];
        cas = stupen_datum_cas[1];
    }

    // Nejkritičtější část SMS, ne vždy je naprosto konstatní
    // Když v SMS není určená přesná adresa (strom na silnici, požár lesa atd), neobsahuje moc údajů
    udalost = mo[0];
    obec = mo[1];
    if(mo.size() == 3){
        popis_mista = mo[2];
    }
    // Když ano, většinou obsahuje víc informací
    else if (mo.size() > 3) {
        adresa = mo[2];

        for (int i = 3; i < mo.length(); i++){
            popis_mista = popis_mista + ", " +mo[i];
        }
    }
}


