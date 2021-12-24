#include<fstream>
#include <iostream>
#include <string>
#include "contrast.h"
#include "data.h"
#include "least_square_method.h"
using namespace std;
contrast::contrast(class data& data, class lsm& lsm)
{
	x_min = data.get_x_min();
	x_max = data.get_x_max();
	a_org = data.get_a();
	a_res = lsm.get_a_res();
	m_n = data.get_n();
	for (int i = 0; i < 50; i++) {
		x_random.push_back(x_min + 1.0 * rand() / RAND_MAX * (x_max - x_min));
		y_org.push_back(f_org(x_random[i]));
		y_lsm.push_back(f_res(x_random[i]));
	}
	err = cal_err();
}

void contrast::result(class data data) {
	ofstream ofs;
	ofs.open(data.orgin+data.path + "6.txt");
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	ofs <<"拟合为" <<m_n << "次多项式  拟合后的多项式为:";
	
	for (vector<double>::iterator it = a_res.begin(); it != a_res.end();it++) {
		static int i = 0;
		if (i != 0) { ofs << "+" << (*it) << "x^" << i; }
		else
			ofs << (*it);
		i++;
	}
	ofs << "\t均方差为" << err;
	ofs.close();
}


contrast::~contrast()
{
}

double contrast::f_org(double x)
{
	double ret = 0.0;
	for (int i = 0; i <= m_n; i++) {
		ret = ret + pow(x, (double)i)*a_org[i];
	}
	return ret;
}
double contrast::f_res(double x)
{
	double ret = 0.0;
	for (int i = 0; i <= m_n; i++) {
		ret = ret + pow(x, (double)i) * a_res[i];
	}
	return ret;
}

double contrast::cal_err()
{
	double ret = 0.0;
	for (int i = 0; i <= m_n; i++) {
		ret += pow((y_lsm[i] - y_org[i]), 2.0);
	}
	ret /= (double)m_n;
	return ret;
}

ostream& operator<<(ostream& stream, const contrast& c)
{
	stream << c.m_n << "次多项式  拟合后的表达式为:";
	stream << c.a_res[0];
	for (int i = 1; i <= c.m_n; i++) {
		stream <<'+' <<c.a_res[i] << "*x^"<<i;
	}
	stream << "均方差为" << c.err<<endl;
	return stream;
}
