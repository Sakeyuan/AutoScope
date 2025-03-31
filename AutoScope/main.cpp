#include "autoscope.h"
#include "logutil.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<ProjectNode>("ProjectNode");

    QApplication a(argc, argv);

    // 安装日志消息处理
    LogUtil::Get().installMessageHandler();

    AutoScope w;
    w.show();
    int ret = a.exec();

    // 卸载日志消息处理
    LogUtil::Get().uninstallMessageHandler();

    return ret;
}
