#include "xnet/network.h"
#include "yoga.h"
#include <Eigen/Dense>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <iostream>

using namespace xnet;

typedef Eigen::MatrixXd Matrix;
typedef Eigen::VectorXd Vector;

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

    Matrix x = Matrix::Random(400, 3);
    Matrix y = Matrix::Random(2, 3);
    Network net;
    Layer *layer1 = new Convolutional<ReLU>(20, 20, 1, 3, 5, 5);
    Layer *layer2 = new MaxPooling<ReLU>(16, 16, 3, 3, 3);
    Layer *layer3 = new FullyConnected<Identity>(5 * 5 * 3, 2);
    net.add_layer(layer1);
    net.add_layer(layer2);
    net.add_layer(layer3);
    net.set_output(new RegressionMSE());
    net.init(0, 0.01, 123);
    Matrix pred = net.predict(x);
    std::cout << pred << "\n";

    QLabel lab;
    lab.setParent(&w);
    lab.setAlignment(Qt::AlignCenter);
    lab.setGeometry(100, 100, 500, 500);
    lab.setStyleSheet("QLabel{font:20px;color:red;background-color:rgb(f9,f9,f9);}");

    Matrix m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = 8;
    m(1, 1) = m(1, 0) + m(0, 1);
    QString qstr = QString::fromStdString(ToString(pred));
    lab.setText(qstr);
    //程序运行后，文本框显示
    lab.show();
    std::cout << "num_layers:" << net.num_layers() << "\n";
    w.show();
    return a.exec();
}
