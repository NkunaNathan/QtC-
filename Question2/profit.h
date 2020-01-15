#ifndef PROFIT_H
#define PROFIT_H
#include <QObject>
#include"company.h"

class Profit: public Company
{
//     public QObject,
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(int employees READ getEmployees WRITE setEmployees)
public:
//    Profit();
    Profit(QString n, QDate d, int e);
    void setName(QString n);
    QString getName () const;
    void setDate(QDate d);
    QDate getDate () const;
    void setEmployees(int e);
    int getEmployees () const;
    QString toString () const;
    bool getCharitable () const;

private:

    QString name;
    QDate date;
    int employees;
//    QList<Profit> profitlist;
};

#endif // PROFIT_H
