#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include <random>
constexpr int NUM = 50;
using namespace std;
class data{
public:
	string orgin;
	string path;
	data();
	~data();
	int save();
	void in_x_n_a();
	void d();
	void showP();
	void show();
	void finding();
	void poly();
	void out();
	vector<double> get_x() { return x; }
	vector<double> get_y_org() { return y_org; }
	vector<double> get_y_noise() { return y_noise; }
	vector<double> get_a() { return a_org; }
	int get_n(void) { return n; }
	double get_x_min() { return x_min; }
	double get_x_max() { return x_max; }
	void read();
private:
	vector<double> a_org;
	int n;//´ÎÊý
	string name;
	double x_max=1 , x_min=0;
	vector<double> x,y_org,y_noise;
	double cal(double x);
	
};
#endif // !DATA_H

