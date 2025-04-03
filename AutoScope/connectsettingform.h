#ifndef CONNECTSETTINGFORM_H
#define CONNECTSETTINGFORM_H

#include <QWidget>

namespace Ui {
class connectsettingform;
}

class connectsettingform : public QWidget
{
    Q_OBJECT

public:
    explicit connectsettingform(QWidget *parent = nullptr);
    ~connectsettingform();

private:
    Ui::connectsettingform *ui;
};

#endif // CONNECTSETTINGFORM_H
