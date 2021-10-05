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

    public:
      int key;
      Node* left;
      Node* right;
      Node(int key)
      {
          this->key = key;
          left = right = NULL;
      }

};

Node* insert(Node* root,int key)
{
     if(root == NULL)
       return  new Node(key);
      
       
     else if(key < root->data)
      root->left = insert(root->left,key);
      


     else if(key > root->data)
       root->right = insert(root->right,key);  
       
     else if(key == root->data)
       return root;
      

      return root;
    

};

void inorder(Node* root)
{
    if(root == NULL)
      return;

    inorder(root->left);  
    cout << root-> key << " ";  
    inorder(root->right);
};

Node* del(Node* root,int key)
{
  Node* tmp = root;
  Node* prev = NULL;
  
  while(1)
  {  
    
      if(tmp == NULL)
        {
           cout << "Key not Found" << el;
           return root;
        }
    
    if(key == tmp->key)
           break; 

    else
    {
       
        prev = tmp;

         if(key < tmp->key)
            tmp = tmp->left;
            
        else if(key > tmp->key)
            tmp = tmp->right;    
    }


  }


 if((tmp->left == NULL) || (tmp->right == NULL))
 {
     Node* child;

  if(tmp->left != NULL )
       child = tmp->left; 

  else
       child = tmp->right; 


  if(prev == NULL)
     root = child;
  

  else if(prev->left == tmp)
     prev->left = child;
  

  else
   prev->right = child; 
    

  
 }

  else
  {
    
      Node* tmp1 = tmp;
      Node* succ = tmp1->right;
      Node* parsucc = tmp1;
      while(succ->left != NULL)
      {
           parsucc =  succ;
          succ = succ->left; 
      }
      

     
      tmp->key = succ->key;
   
      if(parsucc->left == succ)
         parsucc->left = del(succ,succ->key);
      else
         parsucc->right = del(succ,succ->key);
      
  }


   return root;



};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    Node* root = NULL;
    int arr[] = {8,9,3,-1,7,4,89,23,12,-6,0,25};

   for(int x : arr)
     {
       root = insert(root,x);
     }
     inorder(root);
     cout << el;
     int key;
     cin >> key;
     root = del(root,key);
     inorder(root);


    return 0;
}

