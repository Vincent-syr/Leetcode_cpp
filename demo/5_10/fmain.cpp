#include <iostream>
#include "point.h"

using namespace std;

int main()
{
	Point A(4,5);
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY();
	A.GetC();	//使用对象名调用静态函数成员
	Point B(A);
	cout<<"Point B,"<<B.GetX()<<","<<B.GetY();
	Point::GetC();	//使用类名调用静态函数成员
}


