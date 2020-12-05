/*
 * @Author: Vincent-syr
 * @Date: 2020-12-05 21:57:19
 * @LastEditTime: 2020-12-05 22:17:58
 * @Description: https://zhuanlan.zhihu.com/p/72356532
 */

#include <iostream>
#include <algorithm>
using namespace std;



template<typename T1, typename T2>
class Test
{
public:
	Test(T1 i,T2 j):a(i),b(j){cout<<"class template"<<endl;}
private:
	T1 a;
	T2 b;
};
 
template<>
class Test<int , char>
{
public:
	Test(int i, char j):a(i),b(j){cout<<"all class template"<<endl;}
private:
	int a;
	char b;
};
 
template <typename T2>
class Test<char, T2>
{
public:
	Test(char i, T2 j):a(i),b(j){cout<<"partial class template"<<endl;}
private:
	char a;
	T2 b;
};


int main() {
    Test<double , double> t1(0.1,0.2);
    Test<int , char> t2(1,'A');
    Test<char, bool> t3('A',true);
    return 0;
}
