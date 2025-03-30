#include "mytreeview.h"

MyTreeView::MyTreeView(QWidget *parent)
    : QTreeView(parent)
    , model(new QStandardItemModel(this))
    , rootItem(nullptr)
{
    // 设置模型
    setModel(model);
    
    // 隐藏表头
    setHeaderHidden(true);
    
    // 隐藏行号
    setRootIsDecorated(false);
    setAnimated(false);
    setSortingEnabled(false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    // 连接信号
    connect(selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MyTreeView::onSelectionChanged);
    connect(this, &QTreeView::doubleClicked,
            this, &MyTreeView::onDoubleClicked);
}

MyTreeView::~MyTreeView()
{
}

QStandardItem* MyTreeView::addRoot(const QString& text)
{
    // 清空现有数据
    model->clear();
    
    // 创建根节点
    rootItem = new QStandardItem();
    rootItem->setData(text, Qt::DisplayRole);  // 使用setData设置显示文本
    rootItem->setEditable(false);  // 设置为不可编辑
    model->appendRow(rootItem);
    
    // 展开根节点
    expand(rootItem->index());
    
    return rootItem;
}

QStandardItem* MyTreeView::addChild(QStandardItem* parent, const QString& text)
{
    if (!parent) return nullptr;
    
    QStandardItem* child = new QStandardItem();
    child->setData(text, Qt::DisplayRole);  // 使用setData设置显示文本
    child->setEditable(false);  // 设置为不可编辑
    parent->appendRow(child);
    return child;
}

QStandardItem* MyTreeView::addChild(const QString& parentText, const QString& text)
{
    QStandardItem* parent = findItem(parentText);
    if (!parent) return nullptr;
    
    return addChild(parent, text);
}

void MyTreeView::Clear()
{
    // 清空模型数据
    model->clear();
    
    // 重置根节点指针
    rootItem = nullptr;
    
    // 重置选择
    clearSelection();
    
    // 折叠所有节点
    collapseAll();
}

QStandardItem* MyTreeView::getRoot() const
{
    return rootItem;
}

void MyTreeView::getAllChildren(QStandardItem *parent, QList<QStandardItem *> &result) const
{
    if(!parent) return;

    int count = parent->rowCount();
    for (int i = 0; i < count; ++i) {
        QStandardItem* child = parent->child(i);
        result.append(child);
        getAllChildren(child,result);
    }
}

QList<QStandardItem *> MyTreeView::getAllNodes() const
{
    QList<QStandardItem*>allNodes;
    if(rootItem){
        allNodes.append(rootItem);
        getAllChildren(rootItem,allNodes);
    }
    return allNodes;
}

QStandardItem* MyTreeView::findItem(const QString& text) const
{
    QList<QStandardItem*> items = model->findItems(text, Qt::MatchRecursive);
    return items.isEmpty() ? nullptr : items.first();
}

void MyTreeView::removeItem(QStandardItem* item)
{
    if (!item) return;
    
    QStandardItem* parent = item->parent();
    if (parent) {
        parent->removeRow(item->row());
    } else {
        model->removeRow(item->row());
    }
}

void MyTreeView::setItemText(QStandardItem* item, const QString& text)
{
    if (item) {
        item->setText(text);
    }
}

QString MyTreeView::getItemText(QStandardItem* item) const
{
    return item ? item->text() : QString();
}

QStandardItem* MyTreeView::getSelectedItem() const
{
    QModelIndex index = currentIndex();
    return model->itemFromIndex(index);
}

void MyTreeView::expandAll()
{
    QTreeView::expandAll();
}

void MyTreeView::collapseAll()
{
    QTreeView::collapseAll();
}

void MyTreeView::setItemTag(QStandardItem *item, const QVariant &tag)
{
    if(item){
        item->setData(tag,Qt::UserRole);
    }
}

QVariant MyTreeView::getItemTag(QStandardItem *item) const
{
    if(!item) return QVariant();
    return item->data(Qt::UserRole);
}

void MyTreeView::onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected);
    if (!selected.isEmpty()) {
        QModelIndex index = selected.first().topLeft();
        QStandardItem* item = model->itemFromIndex(index);
        emit SelectionChanged(item);
    }
}

void MyTreeView::onDoubleClicked(const QModelIndex& index)
{
    QStandardItem* item = model->itemFromIndex(index);
    emit itemDoubleClicked(item);
} 
