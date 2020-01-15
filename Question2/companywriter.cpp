#include "companywriter.h"
#include <QMetaProperty>
#include<QTextStream>
#include <QFile>
#include<QString>

CompanyWriter::CompanyWriter(QList<Profit *> p):profitList(p)
{
}

CompanyWriter::CompanyWriter(QList<NonProfit *> np):nonProfitList(np){

}


QStringList CompanyWriter::displayDataL (){

     QStringList pResults;
     QString profitResults;

    for (int i = 0; i < profitList.size (); i++){
        profitResults = "";
        const QMetaObject *meta = profitList.at (i)->metaObject ();
        for(int j = 1; j < meta->propertyCount (); j++){
            const QMetaProperty prof = meta->property (j);
            QString name = prof.name ();
            QVariant value = prof.read (profitList.at (i));
            QString pv = value.toString ();
            profitResults += QString(name + ": " + pv + "; ");
        }
        pResults << profitResults;
        qSort(pResults.begin (), pResults.end());
    }
    writeToProfiteFile (pResults);
    return pResults;
}

QStringList CompanyWriter::displayDataR (){

    QStringList npResults;
    QString nonProfitResults;
    for (int i = 0; i < nonProfitList.size (); i++){
        nonProfitResults = " ";
        const QMetaObject *meta = nonProfitList.at (i)->metaObject ();
        for (int j = 1; j < meta->propertyCount (); j++){
            const QMetaProperty nppro = meta->property (j);
            QString names = nppro.name ();
            QVariant npValues = nppro.read (nonProfitList.at (i));
            QString npValue = npValues.toString ();
            nonProfitResults += QString(names + ": " + npValue + "; ");
        }
        npResults << nonProfitResults;
        qSort(npResults.begin (), npResults.end());
    }
    writeToNonProfitFile (npResults);
    return npResults;
}

void CompanyWriter::writeToNonProfitFile (QStringList ls) const{
    QStringList npQlResults = ls;
    QFile nonprofitFile("nonprofit.txt");
    if(!nonprofitFile.open (QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream toNonProfiteFile(&nonprofitFile);

    foreach (QString nplist, npQlResults) {
        toNonProfiteFile << nplist << "\n";
    }
    nonprofitFile.close ();
}

void CompanyWriter::writeToProfiteFile (QStringList pl) const{
    QStringList pQlResults = pl;
    QFile profiteFile("profit.txt");
    if(!profiteFile.open (QIODevice::WriteOnly | QIODevice::Text))
       return;
    QTextStream toProfitFile(&profiteFile);

    foreach (QString plist, pQlResults) {
        toProfitFile << plist << "\n";
    }
    profiteFile.close ();
}
