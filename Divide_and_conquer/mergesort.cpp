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
void print(vector<int>&v,int s,int e)
{
   
    for(int i=s;i<=e;i++)
         cout << v[i] << endl;
}
void merge(vector<int>&v, int s, int e)
{
   int mid = (s+e)/2;
   int i = s;
   int j = mid+1;
   int s1 = s;

   vector<int>v1;
   while( (i <= mid ) && (j <= e) )
   {
         if(v[i] <= v[j])
           v1.push_back(v[i++]);

          else 
           v1.push_back(v[j++]);
    
    
   }

   while(i<= mid)
     v1.push_back(v[i++]);


   while(j<= e)
     v1.push_back(v[j++]);

    for(int i=0;i<v1.size();i++)
    {
        v[s1++] = v1[i];
        
        
    }
    
  

   return;

}

void mergesort(vector<int>& v,int s,int e)
{
   if(s < e)
    { 
      int mid = (s+e)/2;
      mergesort(v,s,mid);
      mergesort(v,mid+1,e);
      merge(v,s,e);
    //   for(int i=s;i<=e;i++)
    //     cout << v[i] << " = " ;

       
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n,x;
    cin >> n;
    vector<int>v;

    fo(i,n) 
    {
       cin >> x;
       v.push_back(x);
    }
    int s= 0;
    int e= v.size() - 1;

    mergesort(v,s,e);

    for(int i=0;i<v.size();i++)
      cout << v[i] << " ";

    return 0;
}

