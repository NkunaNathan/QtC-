#ifndef COMPANYLIST_H
#define COMPANYLIST_H
//#include<QString>
//#include<QList>
#include<QStringList>
#include "company.h"
#include "profit.h"
#include "nonprofit.h"
#include <QtAlgorithms>
//#include "companylistreview.h"
class CompanyListReview;

class CompanyList
{
public:
    CompanyList();
    ~CompanyList();
    void addCompany(Company* c);
    QList<Company *> getList() const;

private:
    QList<Company*> list;
};

#endif // COMPANYLIST_H
