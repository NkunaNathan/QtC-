#ifndef NONPROFIT_H
#define NONPROFIT_H
#include <QtAlgorithms>
#include "company.h"

class NonProfit: public Company
{
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
    bool getCharitable ()const;
//    void addNonProfitList(NonProfit *npl);
//    QList<NonProfit *> getNonProfit()const;
    QString toString ()const;

protected:
//    QList<NonProfit*> nonProfitList;
private:
    QString name;
    QDate date;
    int employees;
    bool charitable;
};

#endif // NONPROFIT_H
