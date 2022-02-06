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
vector<int>v1,v2,v3;
int k;
//vi g[N];
//int a[N];
void print(vector<vector<int>> v)
{
     fo(i,v.size())
     {
         fo(j,v.size())
            cout << v[i][j];

        cout << el;    
     }           
}

bool issafe(vector<vector<int>> matrix,int x,int y)
{

   if((find(v1.begin(),v1.end(),x+y)== v1.end())  && (find(v2.begin(),v2.end(),abs(x-y))== v2.end())  && (find(v3.begin(),v3.end(),y)== v3.end()) )
     return true;

   else
    return false;  
}
pair<int,int> place(vector<vector<int>> matrix,int x,int y)
{
    pair<int,int> p1;

    while(issafe(matrix,x,y) == false)
    {
        if(x < matrix.size())
        {
            if(y < matrix.size())
            {
              y++;
              deb(y);
            }
            else
            {
                x++;
                y=0;
            }  

        }
        else
        {
          p1.first = -1;
          p1.second = -1;
          return p1;
        }
        
    }
   p1.first = x;
   p1.second = y;
   return p1; 

}
bool nQueen(vector<vector<int>> matrix,int i,int j, int n)
{

   if(n == 0)
    return 1;

    pair<int,int> pq =  place(matrix,i,j);
    
    if(pq.first == -1)
     return 0;

    int a = pq.first;
    int b = pq.second;

    matrix[a][b] = 1;
    v1.push_back(a+b);
    v2.push_back(abs(a-b));
    v3.push_back(b);

    print(matrix);
    deb(a);
    deb(b);
    while(nQueen(matrix,a+1,0,n-1) == 0)
     {
          matrix[a][b] = 0;
          v1.pop_back();
          v2.pop_back();
          v3.pop_back(); 


     pair<int,int> pq1 =  place(matrix,a,b+1);
    
          if(pq1.first == -1)
             return 0;

              a = pq1.first;
              b = pq1.second;

             matrix[a][b] = 1;
             v1.push_back(a+b);
             v2.push_back(abs(a-b));
             v3.push_back(b);


     } 
     return 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n,x;
    cin >> n;

    unsigned t = n;
    vector<vector<int>>matrix {
      t , vector<int> (t)
    };

    nQueen(matrix,0,0,n);
    print(matrix);

    return 0;
}

