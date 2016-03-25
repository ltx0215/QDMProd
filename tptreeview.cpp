#include <QApplication>
#include <QCursor>

#include <QDebug>

#include "def.h"
#include "tptreeview.h"

tpTreeView::tpTreeView(QWidget* parent):QTreeView(parent)
{
    createMenu();
}

void tpTreeView::createMenu()
{
    menu = new QMenu(this);

    menu->addAction(QString(TRADD), this, SLOT(onAdd()));
    menu->addAction(QString(TRDEL), this, SLOT(onDel()));
    menu->addAction(QString(TRADDITEM), this, SLOT(onAddItem()));
    menu->addAction(QString(TRDELITEM), this, SLOT(onDelItem()));
}

void tpTreeView::mousePressEvent(QMouseEvent *event)
{
    QTreeView::mousePressEvent(event);
}

void tpTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
    }
    else if(Qt::RightButton == event->button())
    {
        QString itemname = model()->data(currentIndex()).toString();
        if(itemname.isNull() || itemname.isEmpty() || itemname.length() == 0)
        {

        }
        else
        {
            menu->exec(QCursor::pos());
        }
    }
    else;
    QTreeView::mouseReleaseEvent(event);
}

void tpTreeView::onAdd()
{

}

void tpTreeView::onAddItem()
{

}

void tpTreeView::onDel()
{

}

void tpTreeView::onDelItem()
{

}
