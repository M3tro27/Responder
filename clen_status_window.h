#ifndef CLEN_STATUS_WINDOW_H
#define CLEN_STATUS_WINDOW_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>

class Clen_status_window : public QFrame
{
    Q_OBJECT
public:
    explicit Clen_status_window(QWidget *parent = nullptr);

    QVBoxLayout *vlayout;
    QLabel *label_obrazek, *label_jmeno, *label_prijmeni;

    void setColor(QString color);
    void setColor();
    void setUdaje(QString jmeno, QString prijmeni, QString obrazek);

signals:
};

#endif // CLEN_STATUS_WINDOW_H
