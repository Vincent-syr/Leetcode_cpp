//6_18.cpp
#include<iostream>
using namespace std;
class Point
{ public:
       Point() 
      {   X=Y=0;     cout<<"Default Constructor called."<<endl;     }
       Point(int xx,int yy)
      {   X=xx;     Y=yy;     cout<< "Constructor called."<<endl;     }
      Point(Point &p)
      {cout<< "copy constructor called"<<endl;}
       ~Point()
      {   cout<<"Destructor called."<<endl;    }
       int GetX() {return X;}
       int GetY() {return Y;}
	 void Move(int x,int y)
		{  X=x;  Y=y;   }
  private:
       int  X,Y;
};

class ArrayOfPoints
{
   public:
     ArrayOfPoints(int n)
     {   numberOfPoints=n;  points=new Point[n];  }
     ~ArrayOfPoints()
     {   cout<<"Deleting..."<<endl;
         numberOfPoints=0;  delete[] points;     
       }
       
     Point& Element(int n)   //copy constructor called
     {  return points[n];  }
   private:
     Point *points;
     int numberOfPoints;
};

int main(int argc, char const *argv[])
{
    int number = 2;

    ArrayOfPoints points(number);    //创建对象数组
    points.Element(0).Move(5,10);     //通过指针访问数组元素的成员
    points.Element(1).Move(15,20);   //通过指针访问数组元素的成员

    cout<< points.Element(0).GetY()<<endl;  //10, 2686840
    Point p1(2,3); 
    p1 = points.Element(1);    // not copy consturctor
    points.Element(1).Move(1,1);
    cout<<p1.GetX()<<endl;

    return 0;
}
