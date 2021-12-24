#include <iostream>
#include <fstream>
#include<string>
#include "data.h"
#include<Python.h>
#include<vector>
#include <iomanip>

//存之前处理掉
data::data()
{
}

data::~data()
{
}

int data::save()
{
	ofstream outFile;
	outFile.open(orgin+path+ "1.txt",'w');	//打开文件
	int i;
	outFile << "函数次数：";
	outFile << n;
	outFile << "   系数(从低次项到高此项）：";
	for (vector<double>::iterator it = a_org.begin(); it != a_org.end(); it++) {
		outFile << (*it) << "  ";
	}
	outFile.close();
	outFile.open(orgin + path + "2.txt");
	for (i = 0; i < 50; i++)
	{
		//写入数据
		outFile << x[i]<<endl;
	}
	outFile.close();
	outFile.open(orgin + path + "3.txt");
	for (i = 0; i < 50; i++)
	{
		//写入数据
		outFile << y_org[i] << endl;
	}
	outFile.close();
	outFile.open(orgin + path + "4.txt");
	for (i = 0; i < 50; i++)
	{
		//写入数据
		outFile << y_noise[i] << endl;
	}
	outFile.close();

	outFile.open(orgin + path + "5.txt");
	outFile << n<<endl;
	for (vector<double>::iterator it = a_org.begin(); it != a_org.end(); it++) {
		outFile << (*it) << endl;
	}
	outFile.close();
	//<< "  " << y_org[i]<<" "<< y_noise[i]
	//关闭文件
	a_org.clear();
	x.clear();
	y_org.clear();
	y_noise.clear();
	return 0;
}

void data::in_x_n_a()
{
	cout << "请输入自变量上下限" << endl;
	cin >> x_max >> x_min;
	cout << "请输入次数" << endl;
	cin >> n;
	name = to_string(n) + "次多项式";
	for (int i = 0; i <= n; i++) {
		cout << "请输入真实的" << i << "次系数" << endl;
		double an;
		cin >> an;
		a_org.push_back(an);
	}
}
void data::d() {
	double len = (x_max - x_min) / ((double)NUM + 1.0);//步长
	double x_tmp = x_min;
	default_random_engine e;
	uniform_real_distribution<double> u(-0.3, +0.3);
	//cout << "生成的有序数字是：" << endl;
	for (int i = 0; i < 50; i++) {
		x_tmp += len;
		x.push_back(x_tmp);
		y_org.push_back(cal(x_tmp));
		y_noise.push_back(y_org[i] + u(e));
		
	}
}

void data::show()
{
	ifstream inFile;
	ifstream in2,in3,in4;
	char*str2=new char[21];
	char* str3 = new char[21];
	char* str4 = new char[21];
	inFile.open(orgin + path + "1.txt");
	if (!inFile.is_open())
	{
		cerr << "Can't open this file for output:\n";
		return;
	}
	in2.open(orgin + path + "2.txt");
	in3.open(orgin + path + "3.txt");
	in4.open(orgin + path + "4.txt");
	char* strr = new char[255];
	inFile.getline(strr, 255);
	cout << strr;
	cout << endl;
	delete[]strr;
	strr = NULL;
	inFile.close();
	cout << "     x           y           y'" << endl;
	for (int i = 0; i < 50; i++) {
		in2.getline(str2, 20);
		in3.getline(str3, 20);
		in4.getline(str4, 20);
		cout << setw(12) << setprecision(3)<<str2 << setw(12) << setprecision(3) << str3 << setw(12) << setprecision(3) << str4 << endl;
	}
	delete[]str2;
	str2 = NULL;
	delete[]str3;
	str3 = NULL;
	delete[]str4;
	str4 = NULL;
	in2.close();
	in3.close();
	in4.close();
}//read_line(char *filename, int n, char *buf, int buf_len)

void data::showP() {
	Py_Initialize();
	PyRun_SimpleString("import matplotlib.pyplot as plt");
	PyRun_SimpleString("b=input('Please input the name of the function:')");
	PyRun_SimpleString("p=[]");
	PyRun_SimpleString("q=[]");
	PyRun_SimpleString("r=[]");
	PyRun_SimpleString("f = open(f'ad1{b}{2}.txt','r')");
	PyRun_SimpleString("for i in f:	p.insert(0,float(i))");
	PyRun_SimpleString("f2 = open(f'ad1{b}{3}.txt','r')");
	PyRun_SimpleString("for i in f2:	q.insert(0,float(i))");
	PyRun_SimpleString("f3 = open(f'ad1{b}{4}.txt','r')");
	PyRun_SimpleString("for i in f3:	r.insert(0,float(i))");
	PyRun_SimpleString("fig, ax1 = plt.subplots()");/*调用python文件*/
	PyRun_SimpleString("ax2 = ax1.twinx()");/*调用python文件*/
	PyRun_SimpleString("ax1.plot(p, q, 'g-',label = 'Swdown')");/*调用python文件*/
	PyRun_SimpleString("ax2.plot(p, r, 'b-',label = 'Swdow')");/*调用python文件*/
	PyRun_SimpleString("ax1.set_xlabel('x data')");/*调用python文件*/
	PyRun_SimpleString("ax1.set_ylabel('y_org data', color='g')");/*调用python文件*/
	PyRun_SimpleString("ax2.set_ylabel('y_noise data', color='b')");/*调用python文件*/
	PyRun_SimpleString("plt.show()"); /*调用python文件*/
	
}

double data::cal(double x)
{
	double ret = 0.0;
	for (int i = 0; i <= n; i++) {
		ret += (a_org[i] * pow(x, i));
	}
	return ret;
}

void data::poly() {
	ifstream ifs;
	ifs.open(orgin + path + "5.txt");
	if (!ifs.is_open()) {
		cout << "打开失败！" << endl;
		return;
	}
	char* str = new char[10];
	ifs.getline(str, 10);
	cout << "拟合最优化次数：" << str;
	cout << "\n拟合多项式为：  ";
	ifs.getline(str, 10);
	cout << str;
	for (int i = 1; i <= get_n(); i++) {
		ifs.getline(str, 10);
		cout <<'+'<< str <<"*x^"<<i;
	}
	cout << endl;
	str = NULL;
	delete[]str;

}

void data::finding() {
	ifstream ifs1,ifs2,ifs3;
	ifs1.open(orgin + path + "2.txt");
	ifs2.open(orgin + path + "3.txt");
	ifs3.open(orgin + path + "4.txt");
	
	if (!ifs1.is_open()) {
		cout << "打开失败！" << endl;
		return;
	}
	x.clear(), y_org.clear(), y_noise.clear();
	char* str1 = new char[20];
	char* str2 = new char[20];
	char* str3 = new char[20];
	for (int i = 0; i < 50; i++) {
		ifs1.getline(str1, 20);
		ifs2.getline(str2, 20);
		ifs3.getline(str3, 20);
		
	}
	ifs1.close();
	ifs2.close();
	ifs3.close();
	str1 = NULL;
	str2 = NULL;
	str3 = NULL;
	delete[]str1;
	delete[]str2;
	delete[]str3;
}

void data::read()
{
	ifstream inFile;
	inFile.open(orgin + path+"5.txt");	//打开文件
	int i;
	double tmp;
	inFile >> n ;
	for ( i = 0; i <= n; i++) {
		inFile >> tmp;
		a_org.push_back(tmp);
	}
	for (i = 0; i < 50; i++)
	{
		//写入数据
		inFile >> tmp;
		x.push_back(tmp);
		inFile >> tmp;
		y_org.push_back(tmp);
		inFile >> tmp;
		y_noise.push_back(tmp);
	}
	//关闭文件
	inFile.close();
}
void data::out() {
	ifstream ifs;
	ifs.open(orgin + path + "6.txt");
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	char* str = new char[255];
	ifs.getline(str, 255);
	cout << str ;
	ifs.close(); 
	str = NULL;
	delete[]str;
	
}