#ifndef LSM
#define LSM
//https://blog.csdn.net/shuzfan/article/details/52367329
//
#include <vector>
#include "data.h"
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
using namespace std;
class lsm {
public:
	lsm() {};
	lsm(class data org);
	~lsm();
	vector<double> get_a_res() { return a_res; }
private:
	vector<double> m_y,m_x,a_res;
	int m_n;
	void cal();
};


#endif // !LSM

