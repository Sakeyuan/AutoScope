#ifndef PROJECTNODE_H
#define PROJECTNODE_H

#include <QString>
#include <QFileInfo>
#include <QDateTime>

class ProjectNode {
public:
    ProjectNode() = default;
    explicit ProjectNode(QString name,QString path,bool isDir)
        : name(name),path(path),isDir(isDir){
        lastModified = QFileInfo(path).lastModified();
    }

    // **Getter 方法**
    QString getName() const { return name; }
    QString getPath() const { return path; }
    bool isDirectory() const { return isDir; }
    QDateTime getLastModified() const { return lastModified; }

    void setName(const QString& newName) { name = newName; }
    void setIsDir(bool directory) { isDir = directory; }
    void setLastModified(const QDateTime& modifiedTime) { lastModified = modifiedTime; }

private:
    QString name;
    QString path;
    bool isDir;
    QDateTime lastModified;
};

Q_DECLARE_METATYPE(ProjectNode)

#endif // PROJECTNODE_H
