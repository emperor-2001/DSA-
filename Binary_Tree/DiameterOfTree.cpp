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
class Node;
class HDPair{

    int height;
    int diameter;
    public:
       void set(int h,int d)
         {
             height = h;
             diameter = d;
         }
         int getdiameter()
           {
               return diameter;
           }
         int getheight()
           {
               return height;
           }
         friend HDPair diameters(Node* );
      
};
class Node{
     
     int data;
     Node* right;
     Node* left;

     public:
          Node(int d): data(d), right(NULL), left(NULL){};
          friend Node* BinaryTree();
          friend HDPair diameters(Node* );
          
};

//Preorder Build
Node*  BinaryTree()
{
    int d;
    cin >> d;

    if(d== -1)
     return NULL;

    Node* s = new Node(d);
    s->left = BinaryTree();
    s->right = BinaryTree();
    return s;

};




HDPair diameters(Node* root)
{
     HDPair h1;
     if(root == NULL)
         {
             h1.set(0,0);
             return h1;
         }
     
      
      
      HDPair d1 = diameters(root->left);
      HDPair d2 = diameters(root->right);

       
      int ht = max(d1.height,d2.height)+1;

      int dt = max((d1.height+d2.height+1),max(d1.diameter,d2.diameter()));

      h1.set(ht,dt);
      
      return h1;

};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    Node* root = BinaryTree();
    cout << "diameter= " << diameters(root).getdiameter() << el;
 

    return 0;
}

