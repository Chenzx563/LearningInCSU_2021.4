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
	m_y=org.get_y_noise();//��ȡ�������Ĳ���
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
    // ����A����
    Eigen::MatrixXd A(m_x.size(), m_n + 1);
    for (unsigned int i = 0; i < m_x.size(); ++i) {  // �������е�
        for (int n = m_n, dex = 0; n >= 1; --n, ++dex) {  // ����N��1��
            A(i, dex) = pow(m_x[i], n);
        }
        A(i, m_n) = 1;  //
    }
    // ����B����
    Eigen::MatrixXd B(m_y.size(), 1);
    for (unsigned int i = 0; i < m_y.size(); ++i) {
        B(i, 0) = m_y[i];
    }
    // ��������W
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

