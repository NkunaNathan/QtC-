#include "profit.h"

//Profit::Profit(){
//    name = QString();
//    date = QDate::currentDate();
//    employees = 0;
//}

Profit::Profit(QString n, QDate d, int e):
    name(n), date(d), employees(e)
{
}

void Profit::setName (QString n){
    name = n;
}

QString Profit::getName ()const{
    return name;
}

void Profit::setDate (QDate d){
    date = d;
}

QDate Profit::getDate () const{
    return date;
}

void Profit::setEmployees (int e){
    employees = e;
}

int Profit::getEmployees() const{
    return employees;
}

bool Profit::getCharitable ()const{
    return false;
}

//void Profit::setCharitable(bool c){
//    charitable = c;
//}

//void Profit::addProfitList (Profit *pl){
//    profitList.append (pl);
//}
//QList<Profit*> Profit::getprofitList ()const{
//    return profitList;
//}

QString Profit::toString ()const{

    return QString(name + "\t" + date.toString("dd MMMM yyyy") + "\t" + "%1").arg (employees);
}
