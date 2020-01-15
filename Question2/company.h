#ifndef COMPANY_H
#define COMPANY_H
#include<QList>
#include<QDate>
#include <QObject>

class Company : public QObject
{
    Q_OBJECT
public:
//    Company();
    virtual QString getName() const = 0;
    virtual QDate getDate() const = 0;
    virtual int getEmployees() const = 0;
    virtual QString toString() const = 0;
    virtual bool getCharitable() const = 0;
    virtual ~Company(){}
};

#endif // COMPANY_H
