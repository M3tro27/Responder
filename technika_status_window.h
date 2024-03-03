#ifndef TECHNIKA_STATUS_WINDOW_H
#define TECHNIKA_STATUS_WINDOW_H

#include <QWidget>
#include <QFrame>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class Technika_status_window : public QFrame
{
    Q_OBJECT
public:
    explicit Technika_status_window(QWidget *parent = nullptr);

    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QLabel *label_obrazek, *label_nazev, *label_vznak, *label_RZ;

    void setColor(QString color);
    void setUdaje(QString nazev, QString vznak, QString RZ, QString image_path);

signals:
};

#endif // TECHNIKA_STATUS_WINDOW_H
