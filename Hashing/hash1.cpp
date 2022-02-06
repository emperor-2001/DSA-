#include<iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> h; 
    h.insert("Mango",100);
    h.insert("Apple",120);
    h.insert("Banana",140);
    h.insert("Orange",500); 
    h.insert("Kiwi",200);
    h.insert("Pappay" , 1200); 
    h.print();

 

    
      // h.erase(str);
      // h.print();

         h["Orange"] = 222;
         h["Chikku"]  = 343;
         h["Apple"] += 100;

        string str;
         cin >> str;

         Node<int>* val = h.search(str);

         if(val == NULL)
            cout << "Fruit not found" << endl;

         else
            cout << "Price of the fruit is " << val->value << endl;


          h.print();

      


    return 0;
}

