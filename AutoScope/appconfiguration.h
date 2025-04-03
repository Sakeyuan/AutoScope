#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H
#include <QString>
#include <QVector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class AppConfiguration
{
public:
    static AppConfiguration& Get(){
        static AppConfiguration m_appConfiguration;
        return m_appConfiguration;
    }

    void LoadConfig();
    void SaveConfig();

    QStringList serverIp() const { return m_serverIp; }
    void setServerIp(const QStringList& ips){ m_serverIp = ips; }

    QString lastSavePath() const { return m_lastSavePath; }
    void setLastSavePath(const QString& path) { m_lastSavePath = path; }

    QString lastOpenPath() const { return m_lastOpenPath; }
    void setLastOpenPath(const QString& path) { m_lastOpenPath = path; }

    QString lastSelectResource() const { return m_lastSelectResource; }
    void setLastSelectResource(const QString& resource){ m_lastSelectResource = resource; }

    QString lastConnctType() const { return m_lastConnectType; }
    void setLastConnectType(const QString& type) { m_lastConnectType = type; }

    QString lastAnySharePath() const { return m_lastAnySharePath; }
    void setLastAnySharePath(const QString& path) { m_lastAnySharePath = path; }

private:
    AppConfiguration();
    ~AppConfiguration() = default;

    AppConfiguration(const AppConfiguration&) = delete;
    AppConfiguration& operator=(const AppConfiguration&) = delete;
    AppConfiguration(AppConfiguration&&) = delete;
    AppConfiguration& operator=(AppConfiguration&&) = delete;

    const QString DEFAULT_SAVE_PATH = "Resources";
    const QString DEFAULT_ANYSHARE_PATH = "AnyShare://PDM可靠性治理库/12、可靠性测试/2、硬件白盒/白盒测试图片存储";
    const QString DEFAULT_CONNECT_TYPE = "USB";
    const QStringList DEFAULT_SERVER_IPS = {"10.1.5.220"};

    QString appDir;
    QString configPath;
    QStringList m_serverIp;
    QString m_lastOpenPath;
    QString m_lastSavePath;
    QString m_lastSelectResource;
    QString m_lastConnectType;
    QString m_lastAnySharePath;

};

#endif // APPCONFIGURATION_H
