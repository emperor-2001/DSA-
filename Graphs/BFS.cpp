#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graphs
{
   
   int  V;
   list<int>* l;
   int* visited; 

   public:
       
       Graphs(int v)
       {
         
           V = v;
           l = new list<int>[V];
           visited = new int[v];
           memset(visited , -1 , sizeof(*visited) * v );
       }

       void addEdge(int i,int j,bool undir = true)
       {
          
           l[i].push_back(j); // push_front can be better
           if(undir)
           l[j].push_back(i);  
       }

       void printe()
       {
          
           for(int i=0;i<V;i++)
           {
               cout << i << "-->" << " ";
               
            //    for(auto it = l[i].begin();it!=l[i].end();it++)
            //     cout << *it << "- ";

            // Or
              for(auto node: l[i])
              cout << node << " - ";
               cout << endl; 
           }
       }

       void bfs1(int source)
       {
          if(visited[source] == -1)
          {
           cout << source << " ";
           visited[source] = 0;
          }

            queue<int> q1;
           list<int> l1 =l[source];
            for(auto it= l1.begin() ; it!= l1.end() ; it++) 
          {    
              int val = *it;
              if(visited[val] == -1)
                {
                    cout << val << " ";
                    q1.push(val);
                    visited[val] = 0;
                }   
          }

           while(!q1.empty())
           {
                int newSource = q1.front();
                q1.pop();
                bfs1(newSource);
           }
              
       }

     // better bfs code
       void bfs2(int source)
       {
           queue<int> q1;
           bool* visited = new bool[V]{0};
           q1.push(source);
           visited[source] = true;

           while(!q1.empty())
           {
                list<int> l1 = l[q1.front()];
                for(auto nbr : l1)    
                 if(!visited[nbr])
                 {
                    q1.push(nbr); 
                    visited[nbr] = true;
                 }

               cout << q1.front() <<  " ";
               q1.pop();      
              
           }
       }
      



};



int main() {
 
    Graphs g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(3,2);
    g.printe();

    g.bfs1(1);
    cout << endl;
    g.bfs2(1);

    return 0;
}

