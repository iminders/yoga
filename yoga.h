#ifndef YOGA_H
#define YOGA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class yoga; }
QT_END_NAMESPACE

class yoga : public QMainWindow
{
    Q_OBJECT

public:
    yoga(QWidget *parent = nullptr);
    ~yoga();

private:
    Ui::yoga *ui;
};
#endif // YOGA_H
