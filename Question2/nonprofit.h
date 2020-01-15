#ifndef NONPROFIT_H
#define NONPROFIT_H
#include <QObject>
#include "company.h"

class NonProfit:public Company
{
//    public QObject,
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(int employees READ getEmployees WRITE setEmployees)
    Q_PROPERTY(bool charitable READ getCharitable WRITE setCharitable)
public:

//    NonProfit();
    NonProfit(QString n, QDate d, int e, bool c);
    void setName(QString n);
    QString getName () const;
    void setDate(QDate d);
    QDate getDate () const;
    void setEmployees(int e);
    int getEmployees () const;
    void setCharitable(bool c);
    bool getCharitable() const;
    QString toString () const;

private:

    QString name;
    QDate date;
    int employees;
    bool charitable;
//    QList <NonProfit> nonprofitlist;
};

#endif // NONPROFIT_H
