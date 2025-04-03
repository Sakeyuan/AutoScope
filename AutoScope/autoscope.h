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

class AutoScope : public QMainWindow
{
    Q_OBJECT

public:
    AutoScope(QWidget *parent = nullptr);
    ~AutoScope();

private:
    void initializeComponent();

    void loadProjectDirectory(const QString& folderPath,QStandardItem* item);

private slots:
    void onLoadProjectClicked();
    void onTreeViewSelectionChanged(QStandardItem* item);
    void onTreeViewDoubleClicked(QStandardItem* item);
    void onConnectSettingActTriggered();
    void onPathSettingActTriggered();

private:
    Ui::AutoScope *ui;        // 界面对象指针
    QSplitter* mainSpliter;   // 主分割器
    MyTreeView* treeView;     // 自定义树形视图
};

#endif // AUTOSCOPE_H
