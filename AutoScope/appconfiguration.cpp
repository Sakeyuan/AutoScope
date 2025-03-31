#include "appconfiguration.h"

const QString AppConfiguration::DEFAULT_SAVE_PATH = "Resources";
const QStringList AppConfiguration::DEFAULT_SERVER_IPS = {"10.1.5.220"};

AppConfiguration::AppConfiguration()
{

}

void AppConfiguration::LoadConfig()
{

}

AppConfiguration *AppConfiguration::getInstance()
{
    static AppConfiguration instance;
    return &instance;
}
