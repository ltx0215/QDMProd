#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QTabWidget>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief setWindowRegion
     * 功能：设置主窗口大小
     * 参数：无
     * 返回：无
     */
    void setWindowRegion();

    /**
     * @brief setupMenu
     * 功能：设置菜单
     * 参数：无
     * 返回：无
     */
    void setupMenu();

    /**
     * @brief setupMenuBar
     * 功能：设置工具栏
     * 参数：无
     * 返回：无
     */
    void setupToolBar();

    /**
     * @brief setupStatusBar
     * 功能：设置状态栏
     * 参数：无
     * 返回：无
     */
    void setupStatusBar();

    /**
     * @brief createChildWindow
     * 功能：子窗口创建
     * 参数：无
     * 返回：无
     */
    void createChildWindow();

    /**
     * @brief createActions
     * 功能：创建菜单、工具栏响应函数
     * 参数：无
     * 返回：无
     */
    void createActions();

private slots:

    /**
     * @brief actionFileOpen
     * 功能：打开文件
     * 参数：无
     * 返回：无
     */
    void actionFileOpen(bool);

    /**
     * @brief actionPrint
     * 功能：打印
     * 参数：无
     * 返回：无
     */
    void actionPrint(bool);

    /**
     * @brief actionExit
     * 功能：退出
     * 参数：无
     * 返回：无
     */
    void actionExit(bool);

private:
    int w;
    int h;
    QMenu* menu;
    QToolBar *toolbar;
    QAction* acFileOpen;
    QAction* acPrint;
    QAction* acExit;
    QTabWidget* childTab;
    QStatusBar* statusbar;
};

#endif // MAINWINDOW_H
