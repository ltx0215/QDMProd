#ifndef TPTREEVIEW_H
#define TPTREEVIEW_H

#include <QWidget>
#include <QTreeView>
#include <QMenu>
#include <QMouseEvent>

/**
 * @brief The tpTreeView class
 * 功能：树形视图，全部图片整理过程中使用
 */
class tpTreeView : public QTreeView
{
    Q_OBJECT

public:
    tpTreeView(QWidget* parent = NULL);

    /**
     * @brief createMenu
     * 功能：创建右键菜单
     * 参数：无
     * 返回：无
     */
    void createMenu();

protected:
    /**
     * @brief mousePressEvent
     * 功能：响应按键按下事件
     * 参数：鼠标事件
     * 返回：无
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief mousePressEvent
     * 功能：响应按键释放事件
     * 参数：鼠标事件
     * 返回：无
     */
    void mouseReleaseEvent(QMouseEvent *event);

public slots:

    /**
     * @brief onAdd
     * 功能：给项添加材料
     * 参数：无
     * 返回：无
     */
    void onAdd();

    /**
     * @brief onDel
     * 功能：删除该项的材料
     * 参数：无
     * 返回：无
     */
    void onDel();

    /**
     * @brief onAddItem
     * 功能：添加一项
     * 参数：无
     * 返回：无
     */
    void onAddItem();

    /**
     * @brief onDelItem
     * 功能：删除一项
     * 参数：无
     * 返回：无
     */
    void onDelItem();

private:
    QMenu *menu;
    Qt::MouseButton mouseBtn;
};

#endif // TPTREEVIEW_H
