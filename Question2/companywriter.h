#ifndef COMPANYWRITER_H
#define COMPANYWRITER_H
#include <QStringList>
#include "profit.h"
#include "nonprofit.h"

class CompanyWriter
{
public:
    CompanyWriter(QList<Profit*> p);
    CompanyWriter(QList<NonProfit*> np);
    QStringList displayDataL();
    QStringList displayDataR();
    void writeToNonProfitFile(QStringList ls) const;
    void writeToProfiteFile (QStringList pl) const;
private:
    QList<Profit*> profitList;
    QList<NonProfit*> nonProfitList;
};

#endif // COMPANYWRITER_H
