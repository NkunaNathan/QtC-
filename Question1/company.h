#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include<QList>
#include<QStringList>
#include <QDate>
#include<QObject>
//#include <QMetaProperty>
class Company
{
public:
    virtual QString getName() const = 0;
    virtual QDate getDate() const = 0;
    virtual int getEmployees() const = 0;
    virtual QString toString() const = 0;
    virtual bool getCharitable() const = 0;
    virtual ~Company(){}
};

#endif // COMPANY_H
