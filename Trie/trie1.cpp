#include<iostream>
#include "Trie.h"
using namespace std;

int main()
{
    trie  t1;
    t1.insert("apple");
    t1.insert("appled");
    t1.insert("news");
    t1.insert("Mango");
    t1.insert("no");


    string str;
    cin >> str;

    Node* tmp = t1.search(str);
    if(tmp == NULL)
      cout << "key not found" << endl;

    else
     cout  << "found"  << endl; 
}

