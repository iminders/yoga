#include "net/network.h"
#include "yoga.h"
#include <Eigen/Dense>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <iostream>

using Eigen::MatrixXd;
using net::Network;

static std::string
ToString(const Eigen::MatrixXd &mat)
{
    std::stringstream ss;
    ss << mat;
    return ss.str();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Yoga w;

    MatrixXd m(2, 2);

    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = 8;
    m(1, 1) = m(1, 0) + m(0, 1);
    QLabel lab;
    lab.setParent(&w);
    lab.setAlignment(Qt::AlignCenter);
    lab.setGeometry(200, 200, 400, 400);
    lab.setStyleSheet("QLabel{font:30px;color:red;background-color:rgb(f9,f9,f9);}");

    QString qstr = QString::fromStdString(ToString(m));
    lab.setText(qstr);
    //程序运行后，文本框显示
    lab.show();
    Network testNet;
    std::cout << "num_layers:" << testNet.num_layers() << "\n";
    w.show();
    return a.exec();
}
