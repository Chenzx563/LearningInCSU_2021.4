#include <vector>
#include <string>
#include <iostream>
#include<fstream>
#include "least_square_method.h"
using namespace std;
lsm::lsm(class data org)
{
    ofstream ofs;
    ofs.open(org.path + "6.txt");
	m_x=org.get_x();
	m_y=org.get_y_noise();//获取有噪声的参数
	m_n=org.get_n();
    cal();
    ofs<<m_n<< endl;
    for (int i = 0; i <= m_n; i++) {
        ofs << a_res[i] << endl;
    }
    ofs.close();
}

void lsm::cal()
{
    // 创建A矩阵
    Eigen::MatrixXd A(m_x.size(), m_n + 1);
    for (unsigned int i = 0; i < m_x.size(); ++i) {  // 遍历所有点
        for (int n = m_n, dex = 0; n >= 1; --n, ++dex) {  // 遍历N到1阶
            A(i, dex) = pow(m_x[i], n);
        }
        A(i, m_n) = 1;  //
    }
    // 创建B矩阵
    Eigen::MatrixXd B(m_y.size(), 1);
    for (unsigned int i = 0; i < m_y.size(); ++i) {
        B(i, 0) = m_y[i];
    }
    // 创建矩阵W
    Eigen::MatrixXd W;
    W = (A.transpose() * A).inverse() * A.transpose() * B;
    for (int i = 0; i <= m_n; i++) {
        a_res.push_back(W(i));
    }
   	return;
}


lsm::~lsm()
{
}

