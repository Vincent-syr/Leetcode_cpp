//4_4.cpp
#include <iostream>
#include <cmath>
using namespace std;
class Point	//Point类声明
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;cout<<"Point constructor"<<endl;}
	Point(Point &p);
	int GetX() {return X;}
	int GetY() {return Y;}
	~Point()	{cout<<"Point deconstructor"<<endl;}
private:
	int X,Y;
};
Point::Point(Point &p)	//拷贝构造函数的实现
{
	X=p.X;
	Y=p.Y;
	cout<<"Point copy called"<<endl;
}

//类的组合
class Line	//Line类的声明
{
public:	//外部接口
	Line (Point xp1, Point xp2);
    Line(Point *xp1, Point *xp2);
	Line (Line &);
	double GetLen(){return len;}
	~Line(){cout<<"Line destructor"<<endl;}
private:	//私有数据成员
	Point p1,p2;	//Point类的对象p1,p2
	double len;	
};

//组合类的构造函数1
Line:: Line (Point xp1, Point xp2): p1(xp1),p2(xp2)
{
    cout<< "before p1 copyed"<<endl;
    // p1= xp1;  p2 = xp2;

	cout<<"Line constructor called"<<endl;
	double x=double(p1.GetX()-p2.GetX());
	double y=double(p1.GetY()-p2.GetY());
	len=sqrt(x*x+y*y);
}

//组合类的构造函数2
Line:: Line (Point *xp1, Point *xp2) 
{
    p1 = *xp1; p2 = *xp2;
    cout<< "p1.addr = "<< &p1<<endl;

	cout<<"Line constructor"<<endl;
	double x=double(p1.GetX()-p2.GetX());
	double y=double(p1.GetY()-p2.GetY());
	len=sqrt(x*x+y*y);
}
//组合类的拷贝构造函数
Line:: Line (Line &Seg): p1(Seg.p1), p2(Seg.p2)
{
	cout<<"Line copy called"<<endl;
	len=Seg.len;
}


int main(){
	Point myp1(1,1),myp2(4,5);	//建立Point类的对象
    cout<< "myp1.addr = "<< &myp1<<endl;
    // Point
	// Line line(&myp1, &myp2);	//建立Line类的对象
    Line line(myp1, myp2);
	Line line2(line);	//利用拷贝构造函数建立一个新对象


}