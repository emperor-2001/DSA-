#include<bits/stdc++.h>
using namespace std;

class Compare{
    
    public:
       bool operator()(int a, int b){
          return a < b;
       }
    
};

int main()
{
   int arr[] = {10,15,20,70,90,35,78};
   int n = sizeof(arr)/sizeof(int);

   priority_queue<int, vector<int> , Compare> heap;
 // by default priority_queue is max heap
   for(int x : arr)
     heap.push(x);

  priority_queue<int>::value_type AnInt;

  AnInt = 12;
  heap.push(AnInt);
  heap.emplace(44);
  cout << "Size of heaps= " << heap.size() << endl;

  //  while(!heap.empty())
  //    {
  //        cout << heap.top() << endl;
  //        heap.pop();
  //    }  
  priority_queue<int, vector<int> , Compare> pq;
   int arr1[] = {20,45,70,71,93,95,18,77,22};
   

   cout << endl;

    for(int x : arr1)
     pq.push(x);
cout << "Size of pq= " << pq.size() << endl;

 pq.swap(heap);
   while(!pq.empty())
     {
         cout << pq.top() << endl;
         pq.pop();
     }  

    cout << endl;
 


   while(!heap.empty())
     {
         cout << heap.top()  << " jj " << endl;
         heap.pop();
     }  
cout << endl;
      


}