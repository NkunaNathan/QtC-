#include "companylist.h"
#include <QMetaObject>
#include <QMetaProperty>
#include <QFile>
#include <QTextStream>
#include<typeinfo>
#include<QtAlgorithms>

CompanyList::CompanyList()
{
}

void CompanyList::addCompany (Company *p){
    //QTextStream cout(stdout);
    QString cp ="Profit";
//    QString cnp = "NonProfit";
    const QMetaObject* meta = p->metaObject ();
    if(meta->className () == cp){
        Profit *ocp;
        ocp = dynamic_cast<Profit*>(p);
        profitList.append (ocp);
//        qSort(profitList);
        //cout << meta->className ();
    }else{
        NonProfit *ocnp;
        ocnp = dynamic_cast<NonProfit*>(p);
        nonProfitList.append (ocnp);
//        qSort(nonProfitList);
        //cout << meta->className ();
//    }else{
//        //cout << "I dont understand what is happening here";
//        return;
    }
}

QList<NonProfit*> CompanyList::getNonProfitList ()const{
    return nonProfitList;
}

QList<Profit*> CompanyList::getProfitList () const{
    return profitList;
}

CompanyList::~CompanyList (){
    qDeleteAll(profitList);
    qDeleteAll(nonProfitList);
}

