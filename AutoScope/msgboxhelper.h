#ifndef MSGBOXHELPER_H
#define MSGBOXHELPER_H

#include <QMessageBox>
#include <QString>
#include <QWidget>

class MsgBoxHelper
{
public:
    MsgBoxHelper() = delete;
    static QMessageBox::StandardButton showInfo(const QString &title, const QString &message, QWidget *parent = nullptr);
    static QMessageBox::StandardButton showWarning(const QString &title, const QString &message, QWidget *parent = nullptr);
    static QMessageBox::StandardButton showCritical(const QString &title, const QString &message, QWidget *parent = nullptr);
    static QMessageBox::StandardButton showQuestion(const QString &title, const QString &message,
                                                    QMessageBox::StandardButtons buttons = QMessageBox::Yes | QMessageBox::No,
                                                    QWidget *parent = nullptr);

};

#endif // MSGBOXHELPER_H
