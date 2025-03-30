#include "msgboxhelper.h"


#include <QMessageBox>
#include <QString>
#include <QWidget>


QMessageBox::StandardButton MsgBoxHelper::showInfo(const QString &title, const QString &message, QWidget *parent)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    return static_cast<QMessageBox::StandardButton>(msgBox.exec());
}

QMessageBox::StandardButton MsgBoxHelper::showWarning(const QString &title, const QString &message, QWidget *parent)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return static_cast<QMessageBox::StandardButton>(msgBox.exec());
}

QMessageBox::StandardButton MsgBoxHelper::showCritical(const QString &title, const QString &message, QWidget *parent)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setStandardButtons(QMessageBox::Ok);
    return static_cast<QMessageBox::StandardButton>(msgBox.exec());
}

QMessageBox::StandardButton MsgBoxHelper::showQuestion(const QString &title, const QString &message,
                                                       QMessageBox::StandardButtons buttons, QWidget *parent)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(buttons);
    return static_cast<QMessageBox::StandardButton>(msgBox.exec());
}
