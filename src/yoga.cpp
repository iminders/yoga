#include "yoga.h"
#include "ui_yoga.h"

Yoga::Yoga(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Yoga)
{
    ui->setupUi(this);
}

Yoga::~Yoga()
{
    delete ui;
}

