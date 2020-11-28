//4_2.cpp
#include <iostream>
using namespace std;

class Point	//Point 类的声明
{
public:	//外部接口
	Point(int xx=0, int yy=0) {X=xx;Y=yy; cout<<"Point constructor called"<<endl;}	//构造函数
	Point(Point &p);	//拷贝构造函数
	int GetX() {return X;}
	int GetY() {return Y;}
private:	//私有数据
	int X,Y;
};


Point:: Point(Point &p){
    X=p.X;
	Y=p.Y;
	cout<<"copy constructor called"<<endl;
}

//形参为Point类对象的函数
void fun1(Point p)
{	cout<<p.GetX()<<endl;
}
//返回值为Point类对象的函数
Point fun2()
{
	Point A(1,2);   //Point constructor called
	return A;
}

int main(int argc, char const *argv[])
{
	Point A(4,5);	//第一个对象A
	Point B(A);                  //情况一，用A初始化B。第一次调用拷贝构造函数
    // B = A;
    // Point C = A;
	// cout<<B.GetX()<<endl;
	// fun1(B);  //情况二，对象B作为fun1的实参。第二次调用拷贝构造函数
	B = fun2();  //情况三，函数的返回值是类对象，函数返回时，调用拷贝构造函数
	// cout<<B.GetX()<<endl;

    return 0;
}
