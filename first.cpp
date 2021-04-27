#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;
class Person{
public:
    Person(string name, int age){
        this->m_Name=name,this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v1;
    for(int i=0;i<100;i++)  
        v1.push_back(i);
    for_each(v1.begin(),v1.end(),myPrint);   
    cout<<endl;
    /*
        for(vector<int>::iterator it = v.begin();it!=v.end();it++){
            cout << *it <<endl;
        }
    */
    v1.push_back(5);
    v1.insert(v1.begin()+1,5);
    for_each(v1.begin(),v1.end(),myPrint);   
    cout<<endl;
    sort(v1.begin(),v1.end());
    for_each(v1.begin(),v1.end(),myPrint);   
    cout<<endl;
}

int main(){
    test01();
    return 0;
}
