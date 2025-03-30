#ifndef AUTOSCOPE_H
#define AUTOSCOPE_H

#include <QLabel>
#include <QMainWindow>
#include <QSplitter>
#include <QFileInfo>
#include "mytreeview.h"
#include "ProjectNode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AutoScope; }
QT_END_NAMESPACE

/**
 * @brief 主窗口类，实现波图助手的主要功能
 */
class AutoScope : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针
     */
    AutoScope(QWidget *parent = nullptr);
    ~AutoScope();

private:
    /**
     * @brief 初始化界面组件
     */
    void initializeComponent();

    void loadProjectDirectory(QString folderPath,QStandardItem* item);

private slots:
    /**
     * @brief 加载项目按钮点击事件处理
     */
    void onLoadProjectClicked();

    /**
     * @brief 树形视图选择改变事件
     * @param item 选中的节点
     */
    void onTreeViewSelectionChanged(QStandardItem* item);

    /**
     * @brief 树形视图双击事件
     * @param item 双击的节点
     */
    void onTreeViewDoubleClicked(QStandardItem* item);

private:
    Ui::AutoScope *ui;        // 界面对象指针
    QSplitter* mainSpliter;   // 主分割器
    MyTreeView* treeView;     // 自定义树形视图
};

#endif // AUTOSCOPE_H
