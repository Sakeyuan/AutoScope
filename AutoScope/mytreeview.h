#ifndef MYTREEVIEW_H
#define MYTREEVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QItemSelection>

/**
 * @brief 自定义树形视图类
 */
class MyTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit MyTreeView(QWidget *parent = nullptr);
    ~MyTreeView();

    /**
     * @brief 添加根节点
     * @param text 节点文本
     * @return 节点对象
     */
    QStandardItem* addRoot(const QString& text);

    /**
     * @brief 添加子节点
     * @param parent 父节点
     * @param text 节点文本
     * @return 节点对象
     */
    QStandardItem* addChild(QStandardItem* parent, const QString& text);

    /**
     * @brief 添加子节点
     * @param parentText 父节点文本
     * @param text 节点文本
     * @return 节点对象
     */
    QStandardItem* addChild(const QString& parentText, const QString& text);

    /**
     * @brief 清空所有节点
     */
    void Clear();

    /**
     * @brief 获取根节点
     * @return 根节点对象
     */
    QStandardItem* getRoot() const;

    /**
     * @brief 获取所有子节点
     * @param 父节点
     * @param 结果容器
     */
    void getAllChildren(QStandardItem* parent,QList<QStandardItem*>&result) const;

    /**
     * @brief 获取所有子节点
     * @return 子节点列表
     */
    QList<QStandardItem*>getAllNodes() const;

    /**
     * @brief 根据文本查找节点
     * @param text 节点文本
     * @return 节点对象
     */
    QStandardItem* findItem(const QString& text) const;

    /**
     * @brief 删除节点
     * @param item 要删除的节点
     */
    void removeItem(QStandardItem* item);

    /**
     * @brief 设置节点文本
     * @param item 节点对象
     * @param text 新文本
     */
    void setItemText(QStandardItem* item, const QString& text);

    /**
     * @brief 获取节点文本
     * @param item 节点对象
     * @return 节点文本
     */
    QString getItemText(QStandardItem* item) const;

    /**
     * @brief 获取选中节点
     * @return 选中节点对象
     */
    QStandardItem* getSelectedItem() const;

    /**
     * @brief 展开所有节点
     */
    void expandAll();

    /**
     * @brief 折叠所有节点
     */
    void collapseAll();

    void setItemTag(QStandardItem* item, const QVariant& tag);

    QVariant getItemTag(QStandardItem* item) const;
signals:
    /**
     * @brief 节点选择改变信号
     * @param item 选中的节点
     */
    void SelectionChanged(QStandardItem* item);

    /**
     * @brief 节点双击信号
     * @param item 双击的节点
     */
    void itemDoubleClicked(QStandardItem* item);

private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void onDoubleClicked(const QModelIndex& index);

private:
    QStandardItemModel* model;  // 数据模型
    QStandardItem* rootItem;    // 根节点
};

#endif // MYTREEVIEW_H 
