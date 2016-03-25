#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QMenuBar>
#include <QKeySequence>
#include <QDockWidget>

#include <QFileDialog>
#include <QDebug>
#include "tptreeview.h"

#include "def.h"
#include "mainwindow.h"
#include "tpfileanalasis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    w = 0;
    h = 0;

    setWindowRegion();
    createActions();
    setupMenu();
    setupToolBar();
    setupStatusBar();
    createChildWindow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setWindowRegion()
{
    QDesktopWidget* desktop = QApplication::desktop();
    w = desktop->width();
    h = desktop->height();
    showMaximized();
}

void MainWindow::setupMenu()
{
    menu = menuBar()->addMenu(MENUFILE);
    menu->addAction(acFileOpen);
    menu->addAction(acPrint);
    menu->addAction(acExit);
}

void MainWindow::setupToolBar()
{
    toolbar = addToolBar(TBFILE);
    toolbar->addAction(acFileOpen);
    toolbar->addAction(acPrint);
}

void MainWindow::setupStatusBar()
{
    statusbar = statusBar();
}

void MainWindow::createChildWindow()
{
    int tabL = 0;
    int tabT = 0;
    int tabW = 0;
    int tabH = 0;

    //TODO
    /*
     * +6可能在其他电脑上效果不好，后期改进
     */
    tabT += menu->height() + toolbar->height() + 6;
    tabW = QApplication::desktop()->availableGeometry().width();
    tabH = QApplication::desktop()->availableGeometry().height();
    tabH -= statusbar->height();

    childTab = new QTabWidget(this);
    childTab->setGeometry(tabL, tabT, tabW, tabH);
}

void MainWindow::actionFileOpen(bool b)
{
    QString fName = QFileDialog::getOpenFileName(this, DLGNAME, TMPROOT, TMPTYPE);
    if(fName.isNull() || fName.length() == 0)
        return;
    tpFileAnalasis tf;
    tf.setTpFileName(fName);
    tpTreeView *tree = tf.analasisTpFile();
    tree->setParent(this);
    childTab->addTab(tree, TABPICCOLLECT);
    childTab->show();
}

void MainWindow::actionPrint(bool b)
{

}

void MainWindow::actionExit(bool b)
{

}

void MainWindow::createActions()
{
    acFileOpen = new QAction(QIcon(ICONOPEN),OPENFILE, this);
    acFileOpen->setShortcut(QKeySequence(QUICKOPENFILE));
    acFileOpen->setStatusTip(OPENFILETIP);
    connect(acFileOpen, SIGNAL(triggered(bool)), this, SLOT(actionFileOpen(bool)));

    acPrint = new QAction(QIcon(ICONPRINT),PRINT, this);
    acPrint->setShortcut(QKeySequence(QUICKPRINT));
    acPrint->setStatusTip(PRINTTIP);
    connect(acPrint, SIGNAL(triggered(bool)), this, SLOT(actionPrint(bool)));

    acExit = new QAction(EXIT, this);
    acExit->setShortcut(QKeySequence(QUICKEXIT));
    acExit->setStatusTip(EXITTIP);
    connect(acExit, SIGNAL(triggered(bool)), this, SLOT(actionExit(bool)));
}
