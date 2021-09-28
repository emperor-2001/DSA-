#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define el  "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

//vi g[N];
//int a[N];
class Node
{
    int data;
    Node* next;

    public:
       Node(int n): data(n) , next(NULL) {};
       Node(){};
       friend class List;
       ~Node()
       {
      
           if(next!= NULL)
           {
            //    cout << "data= " << data << el;
               delete next;
              
           }
            cout << "deleted element node has data= " << data << el;
       }
      
};


class List 
{
    Node* head;
    Node* tail;

    public:
       List(): head(NULL), tail(NULL) {};
     
        Node* begin()
        {
            return head;
        }
        
       void push_front(int n)
       {
           if(head == NULL)
           {
               Node* s = new Node(n);
            //    s-> next = head;  no need of this
               head = s;
               tail = s;
           }

           else
           {
              Node* s = new Node(n);
               s-> next = head;
               head = s; 
           }
       }

       void push_back(int n)
       {
           if(tail== NULL)
           {
               Node* s = new Node(n);
               s-> next = tail; // no need of this
               tail = s;
               head = s;
           }
           else
           {
             Node* s = new Node(n);
               tail-> next = s;
               s-> next = NULL; // no need of this
               tail = s; 
           }
       }

       void print()
       {
             Node* temp = head;
           while(temp != NULL)
           {
               cout << temp->data << "  ";
               temp = temp->next;
           } 

           cout << el; 
       }

       void reverse()
       {
           Node* prev = NULL;
           Node* tmp = head;
           Node* tmp1;

           while(tmp!= NULL)
           {

               tmp1 = tmp->next;
               tmp->next = prev;
                prev = tmp;
               tmp = tmp1;
           }
           head = prev;
       }

       void insert(int data,int pos)
       {
           if(pos == 0)
               push_back(data);
           else
           {
               Node* s = new Node(data);
               Node* tmp = head;
               int x = 0;
               while(x!= pos-1)
               {
                   tmp = tmp->next;
                   x++;
               }
               s->next = tmp->next;
               tmp->next = s; 


           }
       }

       int search(int d)
       {
           Node* tmp = head;
           int x=0;
           while(tmp!= NULL)
           {
              if(tmp->data == d)
                return x;
              tmp = tmp->next;
              x++;  
           } 

           return -1;
       }

       bool searchrec(Node* head,int d)
       {
           if(head== NULL)
             return false;

           if(head->data == d) 
             return true;
            
              return searchrec(head->next,d);   
       };
       
       void pop_front()
       {
           if(head!= NULL)
           {
             Node* headnew = head;
            
             head = head->next;
               headnew-> next = NULL;
              delete headnew;
            
           }
          

       };
      void remove(int pos)
      {
          Node* tmp = head;
          int x=0;

          while(x!= pos-1)
          {
              tmp = tmp->next;
              x++;
          }
         Node* tmp1 = tmp->next;
         tmp->next = tmp1->next;
         tmp1->next= NULL;
         delete tmp1; 
      }

      void pop_back()
      {
          if(tail!= NULL)
          {

              if(head == tail)
              {
                  delete head;
                  head = tail = NULL;
              }
              else
              {
              Node* tmp = tail;
              Node* tmp1 = head;

              while(tmp1->next!= tmp)
                 tmp1 = tmp1->next;

               tail = tmp1;
               tail->next = NULL;
                 
              tmp->next = NULL;
              delete tmp;
              }

          }
      }
     ~List()
     {
         if(head!= NULL)
          {
            
              delete head;
              head = NULL;
          }
         
          
     };

};







int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    List l1;
    int n,x;
    cin >> n;

    //  l1.reverse();
    while(n--)
    {
       cin >> x;
       l1.push_back(x);
       
    }

     l1.print();
    //  l1.pop_front();
   
     l1.remove(2);
       l1.print();

       l1.pop_back();
       l1.print();
    // l1.reverse();
    // l1.print();

    // l1.insert(4,2);

    // l1.print();

    // int g;
    // cin >> g;

    // int ans = l1.search(g);
    // if( ans == -1)
    // cout << "NOT FOUND" << el;

    // else
    // cout << "FOUND AT INDEX= " <<  ans << el;

    // if(l1.searchrec(l1.begin(),g))
    //  cout << "FOUND" << el;
    // else
    //    cout << "NOT FOUND" << el;





    return 0;
}

