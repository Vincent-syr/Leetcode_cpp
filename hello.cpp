#include <iostream>
using namespace std;


class A {};

class B {
public:
  // conversion from A (constructor):
  B (const A &x) {}
  // conversion from A (assignment):
  B& operator= (const A &x) {return *this;}
  // conversion to A (type-cast operator)
  operator A() {return A();}
};


void fn (B x) {}  // 当我们希望x只能是B类型时，我们就需要禁止隐式类型转换


int main(int argc, char const *argv[])
{
  int a = INT_MAX;
  cout << a;

  

    

    return 0;
}
