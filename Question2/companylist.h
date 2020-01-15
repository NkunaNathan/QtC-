#ifndef COMPANYLIST_H
#define COMPANYLIST_H
#include <QStringList>
#include<QtAlgorithms>

#include "profit.h"
#include "nonprofit.h"
#include "company.h"

class CompanyWriter;

class CompanyList
{
public:
    CompanyList();
    ~CompanyList();
    void addCompany(Company *p);
    QList<Profit *> getProfitList() const;
//    void addNonProfitCompany(NonProfit *np);
    QList<NonProfit *> getNonProfitList() const;
private:
    QList<NonProfit*> nonProfitList;
    QList<Profit*> profitList;
};

#endif // COMPANYLIST_H
