#ifndef PROFIT_H
#define PROFIT_H
#include "company.h"
#include <QtAlgorithms>

class Profit: public Company
{
public:
//    Profit();
    Profit(QString n, QDate d, int e);
    void setName(QString n);
    QString getName () const;
    void setDate(QDate d);
    QDate getDate () const;
    void setEmployees(int e);
    int getEmployees () const;
    bool getCharitable ()const;
//    void addProfitList(Profit* pl);
//    QList<Profit *> getprofitList()const;
    QString toString ()const;
//    void setCharitable(bool c);

protected:
//    QList<Profit*> profitList;
private:
    QString name;
    QDate date;
    int employees;
//    bool charitable;
};

#endif // PROFIT_H
