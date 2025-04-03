#include "appconfiguration.h"
#include "logutil.h"
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>

AppConfiguration::AppConfiguration()
    : m_serverIp(DEFAULT_SERVER_IPS)
    , m_lastOpenPath("")
    , m_lastSavePath("")
    , m_lastSelectResource("")
    , m_lastConnectType(DEFAULT_CONNECT_TYPE)
    , m_lastAnySharePath(DEFAULT_ANYSHARE_PATH)
{
    // 获取应用程序目录
    appDir = QCoreApplication::applicationDirPath();
    configPath = appDir + "/config.json";
}

void AppConfiguration::LoadConfig()
{
    QFile file(configPath);
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "无法打开配置文件:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if(doc.isNull()){
        qCritical() << "配置文件JSON解析失败:" << configPath;
        return;
    }

    QJsonObject root = doc.object();

    QJsonArray serverIPArray = root.value("ServerIP").toArray();
    m_serverIp.clear();
    for(const QJsonValue &val : serverIPArray){
        m_serverIp.append(val.toString());
    }

    m_lastOpenPath = root.value("LastOpenPath").toString();
    m_lastSavePath = root.value("LastSavePath").toString();
    m_lastSelectResource = root.value("LastSelectResource").toString();
    if(m_lastSavePath.isEmpty()){
        m_lastSavePath = appDir + "/" + DEFAULT_SAVE_PATH;
    }

    m_lastConnectType = root.value("LastConnectType").toString();
    if(m_lastConnectType.isEmpty()){
        m_lastConnectType = DEFAULT_CONNECT_TYPE;
    }

    m_lastAnySharePath = root.value("LastAnySharePath").toString();
    if(m_lastAnySharePath.isEmpty()){
        m_lastAnySharePath = DEFAULT_ANYSHARE_PATH;
    }

}

void AppConfiguration::SaveConfig()
{
    QJsonObject root;
    
    // 保存服务器IP列表
    QJsonArray serverIPArray;
    for(const QString& ip : m_serverIp) {
        serverIPArray.append(ip);
    }
    root["ServerIP"] = serverIPArray;
    
    // 保存其他配置
    root["LastOpenPath"] = m_lastOpenPath;
    root["LastSavePath"] = m_lastSavePath;
    root["LastSelectResource"] = m_lastSelectResource;
    root["LastConnectType"] = m_lastConnectType;
    root["LastAnySharePath"] = m_lastAnySharePath;

    QJsonDocument doc(root);
    QByteArray jsonData = doc.toJson();

    QFile file(configPath);
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "无法打开配置文件进行写入:" << file.errorString();
        return;
    }

    file.write(jsonData);
    file.close();
}

