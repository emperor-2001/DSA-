#include <bits/stdc++.h>
#define lli long long int
#define REP(i, n) for (lli i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<lli, lli>
#define vi vector<int>
#define vii vector<ii>
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    // TC : O(N)
    // Takes only one pass :

    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;
    while (mid <= hi)
    {
      switch (nums[mid])
      {
      case 0:
        swap(nums[lo++], nums[mid++]);
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(nums[mid], nums[hi--]);
        break;
      }
    }
  }
};