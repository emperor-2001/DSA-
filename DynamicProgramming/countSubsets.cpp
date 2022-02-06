// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int mod = 1000000007;

    int perfectSum(int arr[], int n, int s)
    {
        int t[n + 1][s + 1];
        // int count = 0;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < s + 1; j++)
            {

                if ((j != 0) && (i == 0))
                    t[i][j] = 0;

                else if (j == 0)
                {
                    t[i][j] = 1;
                }

                else if (arr[i - 1] <= j)
                {
                    t[i][j] = ((t[i - 1][j - arr[i - 1]]) % mod + (t[i - 1][j]) % mod) % mod;
                    //   if(t[i][j] == 1)
                }

                else
                {
                    t[i][j] = t[i - 1][j] % mod;
                    //   if(t[i][j] == 1)
                    // count = (count%mod + 1%mod)%mod;
                }
            }

        return t[n][s];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}
// } Driver Code Ends