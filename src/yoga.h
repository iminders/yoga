#ifndef YOGA_H
#define YOGA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Yoga;
}
QT_END_NAMESPACE

class Yoga : public QMainWindow
{
    Q_OBJECT

public:
    Yoga(QWidget *parent = nullptr);
    ~Yoga();

private:
    Ui::Yoga *ui;
};
#endif // YOGA_H
