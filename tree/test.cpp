#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *a = nullptr;
    int c = 1;
    int* b = &c;
    if(a || b)  cout<<"yes"<<endl;
    // cout<< a==b<<endl;
    return 0;
}
