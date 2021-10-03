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
class Node{
     
     int data;
     Node* right;
     Node* left;

     public:
          Node(int d): data(d), right(NULL), left(NULL){};
          friend Node* BinaryTree();
          friend int height(Node* ,int);
          friend int diameter(Node* );
          
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

int height(Node* root,int h=0)
{
      
      if(root == NULL)
        return h;

     return max(height(root->left,h+1),height(root->right,h+1));


};

int diameter(Node* root)
{
     
     if(root == NULL)
     {
         return 0;
     }


      int d  = height(root->left)+height(root->right)+1 ;
      int d1 = diameter(root->left);
      int d2 = diameter(root->right);

      int x =  d1 > d ? (d1 > d2 ? d1 : d2 ) : (d > d2 ? d : d2) ;
      return x-1;


};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    Node* root = BinaryTree();
    cout << "diameter= " << diameter(root) << el;
 

    return 0;
}

