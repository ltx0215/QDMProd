#ifndef TPFILEANALASIS_H
#define TPFILEANALASIS_H

#include <QObject>
#include <QStandardItem>

#include "tptreeview.h"

typedef struct nodeStruct{
    QString nodename;
    int     nodeweight;
}ns;

/**
 * @brief The tpFileAnalasis class
 * 功能：分析模板文件，产生树形节点信息
 */
class tpFileAnalasis : public QObject
{
    Q_OBJECT
public:
    explicit tpFileAnalasis(QObject *parent = 0);

    /**
     * @brief setTpFileName
     * 功能：设置模板文件名字
     * 参数：name 文件名
     * 返回：无
     */
    inline void setTpFileName(QString name)
    {
        fName = name;
    }

    /**
     * @brief saveTpFile
     * 功能：保存修改后的模板文件
     * 参数：无
     * 返回：无
     */
    void saveTpFile();

    /**
     * @brief analasisTpFile
     * 功能：分析模板文件，并返回树形视图
     * 参数：无
     * 返回：树形视图
     */
    tpTreeView *analasisTpFile();

    /**
     * @brief computeWeight
     * 功能：计算树节点的权值，权值为tab的个数
     * 参数：从模板中获取的节点名称
     * 返回：权值
     */
    int computeWeight(QString str);

    /**
     * @brief getAncestorNode
     * 功能：获取祖先节点
     * 参数：祖先代数；参照节点
     * 返回：祖先节点
     */
    QStandardItem* getAncestorNode(int, QStandardItem*);

private:

    static QString fName;

signals:

public slots:
};

#endif // TPFILEANALASIS_H
