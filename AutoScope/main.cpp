#include "autoscope.h"
#include "logutil.h"
#include "appconfiguration.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    qRegisterMetaType<ProjectNode>("ProjectNode");

    QApplication a(argc, argv);

    // 安装日志消息处理
    LogUtil::Get().installMessageHandler();

    auto& config = AppConfiguration::Get();
    config.LoadConfig();

    AutoScope w;
    w.show();
    int ret = a.exec();

    config.SaveConfig();
    // 卸载日志消息处理
    LogUtil::Get().uninstallMessageHandler();

    return ret;
}
