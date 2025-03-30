#include "autoscope.h"
#include "ui_autoscope.h"
#include "msgboxhelper.h"

#include <QFileDialog>
#include <QDebug>
#include <QDir>

AutoScope::AutoScope(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoScope)
    , treeView(new MyTreeView(this))
{
    ui->setupUi(this);
    this->setWindowTitle("波图助手");
    this->initializeComponent();
}

AutoScope::~AutoScope()
{
    delete ui;
}

void AutoScope::initializeComponent()
{
    mainSpliter = new QSplitter(Qt::Horizontal,this);
    mainSpliter->addWidget(treeView);
    mainSpliter->addWidget(ui->videoLabel);
    mainSpliter->setStretchFactor(0, 1);  // 设置index = 0的为1份
    mainSpliter->setStretchFactor(1, 2);  // 设置index = 2的为2份
    setCentralWidget(mainSpliter);

    // 连接信号
    connect(ui->loadProjectAction, &QAction::triggered, this, &AutoScope::onLoadProjectClicked);
    connect(treeView, &MyTreeView::SelectionChanged, this, &AutoScope::onTreeViewSelectionChanged);
    connect(treeView, &MyTreeView::itemDoubleClicked, this, &AutoScope::onTreeViewDoubleClicked);
}

void AutoScope::loadProjectDirectory(QString folderPath,QStandardItem* item)
{
    if(folderPath.isEmpty()){
        MsgBoxHelper::showWarning("打开项目","目录不能为空: " + folderPath);
        return;
    }
    QFileInfo fileInfo(folderPath);
    if(!fileInfo.exists()){
        MsgBoxHelper::showWarning("打开项目","目录不存在: " + folderPath);
        return;
    }

    ProjectNode projectInfo(fileInfo.fileName(), folderPath, fileInfo.isDir());
    QDir dir(folderPath);
    QStringList filters;
    filters << ".xlsx";
    QStringList files = dir.entryList(filters,QDir::Files);
    foreach(const QString& file , files){

    }
}

void AutoScope::onLoadProjectClicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this,"选择一个项目文件夹","");
    if(!folderPath.isEmpty()){
        treeView->Clear();
        QFileInfo fileInfo(folderPath);
        ProjectNode projectInfo(fileInfo.fileName(), folderPath, fileInfo.isDir());
        QStandardItem* rootItem = treeView->addRoot(folderPath);
        treeView->setItemTag(rootItem,QVariant::fromValue(projectInfo));
        loadProjectDirectory(folderPath,rootItem);
    }
}

void AutoScope::onTreeViewSelectionChanged(QStandardItem* item)
{
    if (item) {
        // 处理节点选择改变事件
        QString text = treeView->getItemText(item);
        // TODO: 添加你的处理逻辑
    }
}

void AutoScope::onTreeViewDoubleClicked(QStandardItem* item)
{
    if (item) {
        // 处理节点双击事件
        QString text = treeView->getItemText(item);
        // TODO: 添加你的处理逻辑
    }
}

