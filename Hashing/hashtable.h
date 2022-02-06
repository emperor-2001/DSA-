#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
template<typename T> 
class Node{

    public:
       string key;
       T value;
       Node<T>* next;
       Node(string k , T v): key(k) , value(v) , next(NULL) {};
       ~Node()
       {
           if(next!= NULL)
            delete next;
             
       }
};


template<typename T> 
class Hashtable
{
   Node<T>** table;
   int ts;
   int cs;

 public:

   int binPow(int a, int n,int ts)
   {
       int res = a;

       if(n&1)
        res = ((res%ts) * (a%ts))%ts;

        a = ((a%ts) * (a%ts))%ts;
        n >> 1;

       return res%ts;


   }
   Hashtable(int default_size = 7)
   {
      ts = default_size;
      cs = 0;
      table = new Node<T>* [ts];
      for(int i= 0 ; i < ts ; i++ )
      {
          table[i] = NULL;
      }
   }

   int hashfunction(string key)
   {
       int result = 0;
    //    int a;
       
       for(int i=0; i< key.size() ; i++)
       {
        //  stringstream ss;
        //  ss << key[i];
        //  ss >> a;
     
         result = ((result%ts) +  (((int)key[i]) * (int)binPow(29,i,ts)))%ts;
        //  cout << result << endl;
       }

         return result;
         
   }

   void insert(string key , int value)
   {
       int i = hashfunction(key);
    //    cout << i  << "key= " << key << endl;
       Node<T>* item = new Node<T>(key,value);
       item->next = table[i];
       table[i] = item;

       cs++;
       float loadnumber = cs/float(ts);
       if(loadnumber > 0.7)
       {
        //    cout << "kutta= " << endl;
         rehash();   
       }   

   }

   void rehash()
   {
       Node<T>** oldtable = table;
       int oldts = ts;
       ts = 2*ts + 1; // try to make it prime
    //    cout << "ts= " << ts << endl;
       table = new Node<T>*[ts];

       for(int i=0 ; i<ts ; i++)
          table[i] = NULL;

       for(int i =0; i<oldts ; i++)
       {
           Node<T>* tmp = oldtable[i];

           while(tmp!= NULL)
           {
               string key = tmp->key;
               int value = tmp->value;
               insert(key,value);
               tmp =tmp->next;
           } 

          if(oldtable[i]!= NULL)   
             delete oldtable[i];

       } 
       delete [] oldtable;

   }

   void print()
   {
        for(int i=0 ;i<ts ;i++)
        {
            cout << "Bucket" << i << "-> " ;
            Node<T>* tmp = table[i];
            while(tmp!= NULL)
            {
                cout << tmp->key << "->";
                tmp = tmp->next;
            }
            cout << endl;
        }

   }

   Node<T>* search(string key)
   {
       int idx = hashfunction(key);
       Node<T>* tmp = table[idx];

       while(tmp!= NULL)
       {
           if(tmp->key == key)
              return tmp;

         tmp= tmp->next;
       }
       return NULL;
   }

   void erase(string key)
   {
       Node<T> *tmp = search(key);

     if(tmp!= NULL)
       {

       if(tmp->next == NULL)
         {
             int i = hashfunction(key);
             Node<T>* tmp1 = table[i];
             if(tmp1->key == key)
              table[i] = NULL;
              else
              {
             while(tmp1->next!= tmp)
              tmp1 = tmp1 ->next;

              tmp1->next = NULL;
              
              }
              delete tmp;
         }


            else
            {
                // cout << "kutta= " << endl;
                Node<T>* tmp1 = tmp->next;
                tmp->value = tmp1->value;
                tmp->key = tmp1->key;
                tmp->next = tmp1->next;
            }  

            
       }

   }


   T& operator[](string key)
   {

     
      Node<T>* tmp = search(key);

      if(tmp == NULL)
      {
          T x = 0;
          T& v = x;
        insert(key,0);
        return v;
      }

      else
        return tmp->value;


   }




};