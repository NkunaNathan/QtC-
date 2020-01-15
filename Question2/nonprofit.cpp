#include "nonprofit.h"
//#include "company.h"

//NonProfit::NonProfit()
//{
//    name = QString();
//    date = QDate::currentDate();
//    employees = int();
//    charitable = false;
//}

NonProfit::NonProfit(QString n, QDate d, int e, bool c)
    : name(n), date(d), employees(e), charitable(c){

}

void NonProfit::setName (QString n){
    name = n;
}

QString NonProfit::getName () const{
    return name;
}

void NonProfit::setDate (QDate d){
    date = d;
}

QDate NonProfit::getDate () const{
    return date;
}

void NonProfit::setEmployees (int e){
    employees = e;
}

int NonProfit::getEmployees () const{
    return employees;
}

void NonProfit::setCharitable (bool c){
    charitable = c;
}

bool NonProfit::getCharitable () const{
    return charitable;
}

QString NonProfit::toString() const{
    QString c = charitable ? "charitable" : "Not Charitable";
    return QString(name + "\t" +  date.toString("dd MMMM yyyy")  + "\t" + " %1" + "\t" +  c).arg (employees);
}
