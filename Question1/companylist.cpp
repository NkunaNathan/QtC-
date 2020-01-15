#include <QMetaProperty>
#include "profit.h"
#include "companylist.h"
#include<QtAlgorithms>

CompanyList::CompanyList(){

}

void CompanyList::addCompany (Company *c){
    list.append (c);
    qSort(list);
}


QList <Company *> CompanyList::getList() const
{
    return list;
}

CompanyList::~CompanyList (){
    qDeleteAll(list);
}
