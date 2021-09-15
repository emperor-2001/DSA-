#include<iostream>
#include "vector.h"
using namespace std;



int main()
{
    Vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(15);
    v.push_back(16);

    cout << v.size() <<endl;
    cout << v.capacity() <<endl;
    cout << v[0] <<endl;
    cout << v.back() <<endl;
    cout << v.front() <<endl;

    v.pop_back();

    cout << v.size() <<endl;
    cout << v.capacity() <<endl;
     cout << v.back() <<endl;



    return 0;

}