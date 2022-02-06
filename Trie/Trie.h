#include<bits/stdc++.h>
using namespace std;

class trie;
class Node
{
 
    char value;
    unordered_map<char , Node*> m1;
    bool isterminal;

      public:
         Node(char v) : value(v) , isterminal(false)  {};
         friend class trie;

};

class trie
{
   Node* root ;
   public:

   trie()
   {
       root = new Node('\0');
   }

   void insert(string str)
   {
       Node* tmp = root;
       Node* temp1;
       for(int i=0; i<str.size() ;i++)
       {
             char value = str[i];
             
             if((tmp->m1).find(value) == (tmp->m1).end())
              {
                 temp1 = new Node(value);
                 tmp->m1[value] = temp1;
              }
                 tmp = tmp->m1[value];
              
       }
       tmp->isterminal = true;       
          
   }

   Node* search(string key)
   {

       Node* tmp = root;
       Node* temp1;
       for(int i=0; i<key.size() ;i++)
       {
             char value = key[i];
             
             if((tmp->m1).find(value) == (tmp->m1).end())
                  return NULL;
              
              else
                 tmp = tmp->m1[value];
              
       }
       if(tmp->isterminal)
          return tmp;

       else
         return NULL;   


   }



};