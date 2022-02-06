#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int , int> m1;

    m1.insert({1,3});
    m1.insert(make_pair(2,5));
    pair<int,int> p1{7,4} , p2;
    p2 = make_pair(6,9);
    m1.insert(p2);
    m1.insert(p1);

    for(auto it = m1.begin() ; it!= m1.end() ; it++)
        cout << it->first << "- >" <<it->second << "  Bucket no'= " << m1.bucket(it->first) << endl;
    

    int x;
    cin >> x;

    // if(m1.count(x))
    //   cout << "key Found" << endl;

    //  else
    //   cout << "key Not found" << endl;  

    //OR

    if(m1.find(x)!= m1.end())
      cout << "key Found" << endl;

     else
      cout << "key Not found" << endl;  

  
   cout << "Total no of buckets present= " << m1.bucket_count() << endl;

   for(int i=0 ;  i<m1.bucket_count() ; i++)
       cout << "Size of bucket " << i << "= " << m1.bucket_size(i) << endl;
   
  cout << "Maximum possible buckets= " << m1.max_bucket_count() << endl; // It returns the maximum number of buckets unordered_map container can have.


}