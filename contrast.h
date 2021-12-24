#ifndef CONTRAST_H
#define CONTRAST_H

#include <iostream>
#include <vector>
#include "data.h"
#include "least_square_method.h"
using namespace std;
class contrast {
public:
	contrast(class data& data,class lsm& lsm);
	~contrast();
	double f_org(double x);
	double f_res(double x);
	double get_err() { return err; };
	void result(class data data);
	friend ostream& operator<<(ostream& stream, const contrast& c);
private:
	double x_min, x_max;
	int m_n;
	vector<double> x_random, y_org, y_lsm,a_org,a_res;
	double cal_err();
	double err;
};
#endif // !CONTRAST_H