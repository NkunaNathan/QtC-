#ifndef COMPANYLISTREVIEW_H
#define COMPANYLISTREVIEW_H
#include"QStringList"
#include"company.h"
#include "QStringList"

class CompanyListReview
{
public:
    CompanyListReview(QList<Company *> l);
    QStringList displayList();
    void save(QStringList l);
private:
    QList<Company*> list;
};

#endif // COMPANYLISTREVIEW_H
