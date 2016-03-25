#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QVector>

#include <QDebug>

#include "def.h"
#include "tpfileanalasis.h"

QString tpFileAnalasis::fName = "";

tpFileAnalasis::tpFileAnalasis(QObject *parent) : QObject(parent)
{

}

void tpFileAnalasis::saveTpFile()
{

}

tpTreeView* tpFileAnalasis::analasisTpFile()
{
    tpTreeView* tree = new tpTreeView();
    QVector<ns> map;
    QStandardItemModel* model = new QStandardItemModel(tree);
    QStandardItem *curitem = NULL;
    int curweight = 0;

    QString node;
    QFile file(fName);
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::about(NULL, DLGTITLE, FILENOTEXIST);
        delete tree;
        tree = NULL;
        return NULL;
    }

    QTextStream in(&file);
    node = in.readLine();
    if(node.startsWith(TAB))
    {
        QMessageBox::about(NULL, DLGTITLE, FILECORRUCPT);
        delete tree;
        tree = NULL;
        return NULL;
    }

    map.clear();
    ns nsItem;
    nsItem.nodename = node;
    nsItem.nodeweight = 0;
    map.append(nsItem);

    do{
        node = in.readLine();
        int weight = computeWeight(node);
        node = node.trimmed();
        nsItem.nodename = node;
        nsItem.nodeweight = weight;
        map.append(nsItem);
    }while(!in.atEnd());

    file.close();

    QVector<ns>::iterator mi;
    for(mi = map.begin(); mi != map.end(); mi++)
    {
        int tmpw = mi->nodeweight;
        QStandardItem* item = new QStandardItem(mi->nodename);
        item->setEditable(false);
        if(tmpw == 0)
        {
            curweight = tmpw;
            curitem = item;
            model->appendRow(item);
        }
        else if(tmpw > curweight)
        {
            curitem->appendRow(item);
            curitem = item;
            curweight = tmpw;
        }
        else if(tmpw <= curweight)
        {
            QStandardItem* pitem = getAncestorNode(curweight - tmpw + 1, curitem);
            pitem->appendRow(item);
            curitem = item;
            curweight = tmpw;
        }
    }

    model->setHeaderData(0, Qt::Horizontal, TREETITLE);
    tree->setModel(model);
    return tree;
}

int tpFileAnalasis::computeWeight(QString str)
{
    int weight = 0;
    while(str.startsWith(TAB))
    {
        weight++;
        str = str.right(str.length() - 1);
    }
    return weight;
}

QStandardItem* tpFileAnalasis::getAncestorNode(int generation, QStandardItem *item)
{
    QStandardItem* ancestor = item;
    for(int i=0; i<generation; i++)
    {
        ancestor = ancestor->parent();
    }
    return ancestor;
}
