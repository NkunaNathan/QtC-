#include "companylistreview.h"
#include <QMetaProperty>
#include <QTextStream>
#include<QFile>

CompanyListReview::CompanyListReview(QList<Company*> l):list(l)
{
}

QStringList CompanyListReview::displayList (){
    QStringList result;
    QString buildResult;
    for (int i=0; i <list.size(); ++i){
        buildResult = "";
        buildResult+= list.at(i)->toString();
        result << buildResult;
        qSort(result.begin (), result.end()); // , Qt::DescendingOrder

    }
    save(result);
    return result;
}

void CompanyListReview::save (QStringList l) {
    QFile outf("backup.txt");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);
    QStringList strlst = l ;
    foreach (QString str, strlst) {
        outstr << str <<"\n";
    }
    outf.close();
}
