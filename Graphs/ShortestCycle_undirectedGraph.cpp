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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define el "\n"
#define F first
#define S second
#define sz(x)          ((int) x.size())
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
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

vi g[N];
int a[N];
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N1 = 200005;
void solve() {
  int i, j, n, m;
}
int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % mod;
      base = ((ll)base * base) % mod;
      exp >>= 1;
    }
    return result;
  }
  
  void ipgraph(int n, int m){
      int i, u, v;
      while(m--){
          cin>>u>>v;
      u--, v--;
          g[u].pb(v);
          g[v].pb(u);
      }
  }
  
  void dfs(int u, int par){
      for(int v:g[u]){
          if (v == par) continue;
          dfs(v, u);
      }
  }

class Graphs
{
    public:

    int v;
    list<int>* l;

    Graphs(int V)
    {
        v = V;
        l = new list<int>[v];
    }
    void addEdge(int x , int y , bool undir = true)
    {
        l[x].push_back(y);
         if(undir)
           l[y].push_back(x);
    }
};

int shortestCycle(Graphs& g)
{
    int ans = INT_MAX;
    int v = g.v;
    for(int i =0 ; i< v ; i++)
    {
        vector<int>dist(v , INT_MIN);
        vector<int>parent(v , -1);
        queue<int>q;

        q.push(i);
        dist[i] = 0;
        parent[i] = i;

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            for(auto child : g.l[x])
            {
                if(child == parent[x] )
                {
                     continue;
                }
                    
                else if(dist[child] == INT_MIN)
                {
                    dist[child] = dist[x] + 1;
                    parent[child] = x;
                    q.push(child);
                }
                else 
                {
                    // deb(ans);
                    ans = min(ans , dist[x] + dist[child] + 1);
                    if(ans == 3)
                     return  3;
                }
            }
        }
        


    }
    return ans;
}  
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    int x = 1;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        Graphs g(v);
        int a,b;

        for(int i = 0 ;i<e ; i++)
        {
          cin >> a >> b;
          g.addEdge(a,b);
        }

        int ans = shortestCycle(g);
        if(ans == INT_MAX)
          cout << "Case " << x << ": " << "impossible" << el;
        else
          cout << "Case " << x << ": " << ans << el;

          x++;


      
    }

    return 0;
}


