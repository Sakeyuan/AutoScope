#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H
#include <QString>
#include <QVector>


class AppConfiguration
{
public:

    AppConfiguration(const AppConfiguration&) = delete;
    AppConfiguration& operator=(const AppConfiguration&) = delete;
    static AppConfiguration* getInstance();
private:
    AppConfiguration();

    static const QString DEFAULT_SAVE_PATH;
    static const QStringList DEFAULT_SERVER_IPS;
    QStringList _serverIp;
    QStringList m_serverIp;
    QString m_lastOpenPath;
    QString m_lastSavePath;
    QString m_lastSelectResource;

public:
    QStringList serverIp() const { return m_serverIp; }
    void setServerIp(const QStringList& ips){ m_serverIp = ips; }

    QString lastSavePath() const { return m_lastSavePath; }
    void setLastSavePath(const QString& path) { m_lastSavePath = path; }

    QString lastOpenPath() const { return m_lastOpenPath; }
    void setLastOpenPath(const QString& path) { m_lastOpenPath = path; }

    QString lastSelectResource() const { return m_lastSelectResource; };
    void setLastSelectResource(const QString& resource){ m_lastSelectResource = resource; }

};

#endif // APPCONFIGURATION_H
