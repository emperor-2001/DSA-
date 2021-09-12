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


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
       int rows= matrix.size();
       int cols = matrix[0].size();
       vector<int>v;
        
       int size = rows > cols ? 2*cols : 2*rows-1;
       int x=0,y=cols-1;
       
       for(int i=0;i<size;i++)
       {
           if(i%2==0)
           {
               int j;
                int n=cols-floor(i/2);
               
               if((i/2)%2==1)  
               {
                   j=cols-1-(rows-x);
                   while(n--)
                   {
                      v.push_back(matrix[x][j]);
                       j--;
                   }
                  
                   x= floor((i/2)/2)+1;
               }
               
               else
               {
                   j=x;
                   while(n--)
                   {
                      v.push_back(matrix[x][j]);
                       j++;
                   }
                
                    x=rows-floor((i/2)/2)-1;
                   
               }
               
                 
                   
               
           }
           else
           {
               
                int j;
                int n=rows-1-floor(i/2);
               
               if(((i-1)/2)%2==1)  
               {
                   j=rows-1-y-1;
                   while(n--)
                   {
                      v.push_back(matrix[j][y]);
                       j--;
                   }
                  
                     y=cols-1-floor(((i+1)/2)/2); 
               }
               
               else
               {
                   
                   j=cols-y;
                   while(n--)
                   {
                      v.push_back(matrix[j][y]);
                       j++;
                   }
                    y= floor(((i-1)/2)/2);
                 
                   
               }
               
                 
               
           }
       }
       return v;
        
    }

void printvector(vector<int>v)
{
    fo(i,v.size())
     cout << v[i] << "  ";

     cout << el;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  int n,m,x;
   vector<vector<int>>matrix;
   cin >> n >> m;

   for(int i=0;i<n;i++)
    {
        vector<int>v;
        for(int i=0;i<m;i++)
        {
          cin >> x;
          v.push_back(x) ; 
        }
        matrix.push_back(v);   
    }

    vector<int>v = spiralOrder(matrix);
    printvector(v);
    return 0;
}

