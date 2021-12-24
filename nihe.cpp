#include <iostream>
#include <vector>
#include<fstream>
#include <windows.h>
#include <time.h> 
#include "data.h"
#include "least_square_method.h"
#include "contrast.h"

void menu()
{
    
    cout <<"\n\n"<< "                                                               **********************************************" << endl;
    cout << "                                                               **           欢迎使用最小二乘系统           **" << endl;
    cout << "                                                               **                  菜 单                   **" << endl;
    cout << "                                                               **            (a)基本过程体验               **" << endl;
    cout << "                                                               **            (b)输入真实数据               **" << endl;
    cout << "                                                               **            (c)保存输入数据               **" << endl;
    cout << "                                                               **            (d)显示函数数据               **" << endl;
    cout << "                                                               **            (e)最小二乘拟合               **" << endl;
    cout << "                                                               **            (f)参数拟合结果评价           **" << endl;
    cout << "                                                               **            (g)出图                       **" << endl;
    cout << "                                                               **            (h)退出系统                   **" << endl;
    cout << "                                                               **********************************************" << endl;
    cout << "                                                                           请选择相应的操作 a~h" << endl;
}
//退出页面 
void exit()
{
    system("cls");
    cout << "\t\t\t\t\t\t**********************************************" << endl;
    cout << "\t\t\t\t\t\t**              感谢使用本系统              **" << endl;
    cout << "\t\t\t\t\t\t**                 谢谢老师                 **" << endl;
    cout << "\t\t\t\t\t\t**                   再见                   **" << endl;
    cout << "\t\t\t\t\t\t**********************************************" << endl;
    cout << "\t\t\t\t\t\t按任意键关闭本页面..." << endl;
    cout << "";
    getchar();
    getchar();
}

int main()
{
    system("color B4");
    //登录 密码
    char name[10];
    string key;
    time_t tt;
    struct tm lt;
    time(&tt); //获取 Unix 时间戳。
    localtime_s(&lt,&tt);
    string org;
    int t = 0;//控制登录的进行
    string key1 = "1234", key2 = "2468", key3 = "1111";
    while (t == 0)
    {
        static int ch = 0;
        while (t==0) {
        L1:cout << endl;
            system("cls");
            cout << "\n\t\t\t\t\t\t****************【多项式参数辨识系统】******************" << endl;
            cout << "\t\t\t\t\t\t**                请选择进入方式                      **\n";
            cout << "\t\t\t\t\t\t**                1.注册新用户                        **\n";
            cout << "\t\t\t\t\t\t**                2.直接登录                          **\n";
            cout << "\t\t\t\t\t\t**                3.退出系统                          **\n";
            cin >> ch;

            if (ch == 1) {
                system("cls");
                ofstream ofs;
                string af, af1;
                cout << "请输入你的用户名" << endl;
                cin >> af;
                ofs.open("ZHANG.txt", ios_base::app);
                ofs <<af << " ";
            L2:cout << endl;
                cout << "请输入你的密码" << endl;
                cin >> af;
                cout << "请再次输入密码：" << endl;
                cin >> af1;
                if (af == af1) {
                    ofs << af << endl;
                    cout << "设置成功！按任意键返回登录界面" << endl;
                    system("pause");
                    goto L1;
                }
                else {
                    cout << "输入错误！请重设密码" << endl;
                    goto L2;
                }
            }
            if (ch == 3) {
                exit(0);
            }
            if (ch == 2) {
                system("cls");
                cout << "本次登录时间：" << lt.tm_year + 1900 << '\\' << lt.tm_mon + 1 << '\\' << lt.tm_mday << ' ' <<
                    lt.tm_hour << ':' << lt.tm_min << ':' << lt.tm_sec << endl;
                cout << "\n\t\t\t\t\t\t****************【内部登录】******************" << endl;
                cout << "\t\t\t\t\t\t            用户名："; cin >> name;
                cout << "\t\t\t\t\t\t            密码："; cin >> key;

                //设置三套内置的账号密码以存储初始化好的内置文件 
                
                
                
                if (strcmp("ad1", name) == 0 && key == key1)  t = 1, org = "ad1";
                else if (strcmp("ad2", name) == 0 && key == key2)  t = 1, org = "ad2";
                else if (strcmp("ad3", name) == 0 && key == key3)  t = 1, org = "ad3";
                

                else
                {
                    cout << "\n\t\t\t\t\t\t***************用户名或密码错误***************\n";
                    cout << "\t\t\t\t\t\t**                0.退出系统                **\n";
                    cout << "\t\t\t\t\t\t**                1.重新登陆                **\n";
                    cout << "\t\t\t\t\t\t**                2.忘记密码                **\n";
                    cout << "\t\t\t\t\t\t                  请选择：";
                    int choice_land;
                    cin >> choice_land;
                    if (choice_land == 0)
                    {
                        exit();
                        return 0;
                    }
                    else if (choice_land == 1) t = 0, system("cls"); //继续进行登录 
                    else if (choice_land == 2) {
                        t = 0;
                        cout << "请输入您的用户名：" << endl;
                        cin >> name;
                        string str;
                        if (strcmp("ad1", name) == 0) {
                            cout << "请回答ad1的密保问题： 你的母校名称：" << endl;
                            cin >> str;
                            if (str == "CSU") {
                                cout << "请输入修改后的密码" << endl;
                                cin >> key1;
                            }
                            else {
                                cout << "回答错误，现退出系统！" << endl;
                                exit(0);
                            }
                        }
                        if (strcmp("ad2", name) == 0) {
                            cout << "请回答ad2的密保问题： 你的母校名称：" << endl;
                            cin >> str;
                            if (str == "THU") {
                                cout << "请输入修改后的密码" << endl;
                                cin >> key2;
                            }
                            else {
                                cout << "回答错误，现退出系统！" << endl;
                                exit(0);
                            }
                        }
                        if (strcmp("ad3", name) == 0) {
                            cout << "请回答ad3的密保问题： 你的母校名称：" << endl;
                            cin >> str;
                            if (str == "LJU") {
                                cout << "请输入修改后的密码" << endl;
                                cin >> key3;
                            }
                            else {
                                cout << "回答错误，现退出系统！" << endl;
                                exit(0);
                            }
                        }

                        system("cls");
                    }
                    else
                    {
                        cout << "\t\t\t\t出现错误" << endl;
                        exit(); //直接退出程序 
                        return 1;
                    }
                }
            }
        }
    }
    cout << "\t\t\t\t******************登录成功********************\n" << endl;
    string paths;
    class data m_data;
    lsm m_lsm;
    while (1) {
        system("cls");
        cout << "本次登录时间：" << lt.tm_year + 1900 << '\\' << lt.tm_mon + 1 << '\\' << lt.tm_mday << ' ' <<
            lt.tm_hour << ':' << lt.tm_min << ':' << lt.tm_sec << endl;
        menu();
        char c = getchar();
        if (c == 'a') {
            m_data.in_x_n_a();
            m_data.d();
            m_lsm=lsm(m_data);
            contrast m_contrast(m_data, m_lsm);
            cout << m_contrast;
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
        if (c == 'b') {
            m_data.in_x_n_a();

            m_data.d();
            cout << "数据已经输入" << endl;
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
        if (c == 'c') {
            cout << "请输入保存函数名称:";
            cin >> paths;
            m_data.path = paths;
            m_data.orgin = org;
            m_lsm = lsm(m_data);
            contrast m_contrast(m_data, m_lsm);
            m_contrast.result(m_data);
            m_data.save();

            cout << "数据已经保存" << endl;
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
        if (c == 'd') {
            cout << "请输入函数名称" << endl;
            string str;
            cin >> str;
            m_data.show();
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
        if (c == 'e') {
            cout << "请输入函数名称:";
            cin >> paths;
            m_data.path=paths;
            m_data.poly();
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }

        if (c == 'f') {
            cout << "请输入函数名称:";
            cin >> paths;
            m_data.path = paths;
            m_data.out();
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
        if (c == 'g') {
            m_data.showP();
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }

        if (c == 'h') {
            exit();
            return 0;
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
        }
    }
    
    return 0;
}

