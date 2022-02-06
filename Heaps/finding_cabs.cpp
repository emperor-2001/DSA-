#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define swap(x,y) do { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; memcpy(swap_temp,&y,sizeof(x)); memcpy(&y,&x,       sizeof(x));  memcpy(&x,swap_temp,sizeof(x)); } while(0)
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

class Compare{
    
    public:
       bool operator()(pair<int,double>p1, pair<int,double>p2){
          return p1.first > p2.first;
       }
    
};


vector<int> nearbyCabs(vector<pair<int,int>> v , int m)
{
    vector<int>v1;
    priority_queue<pair<double,int> , vector<pair<double,int>> , Compare> nc;
    fo(i,v.size())
    {
         double a1 = v[i].first;
         double a2 = v[i].second;
        //  deb(a1);
        //  deb(a2);
         nc.push(make_pair(sqrt(pow(a1,2)+pow(a2,2)),i+1));
        //  deb(nc.top().first);
    }
    fo(i,m)
    {
        // deb(nc.top().second);
       v1.push_back(nc.top().second);
       nc.pop();

    }

       return v1;
        
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());


    int n, m;
    cin >> n >> m;
    int x,y;

    vector<pair<int, int>> v (n, make_pair(-1, -1));
    
    int i=0;
    while(n--)
    {
      int x,y;
      cin >> x >> y;
      v[i] = {x,y}; 
    //    cout << v[i].first << "  i=    " << i << " " << v[i].second << el;
       i++;
    }
     
    //  fo(i,n)
    //  {
    //      cout << v[i].first << "  =  " << v[i].second << el;
    //  }
     vector<int>ans;

     ans = nearbyCabs(v,m);
     fo(i,ans.size())
     {
         cout << "C" << ans[i] << el;
     }
   
    return 0;
}

