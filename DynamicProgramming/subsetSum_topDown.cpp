// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

int t[101][100001];

class Solution
{
public:
    bool isSubsetSum(int n, int arr[], int s)
    {

        memset(t, -1, sizeof(t));
        // for (int i = 0; i < n + 1; i++)
        // {
        //     for (int j = 0; j < s + 1; j++)
        //         cout << t[i][j];

        //     cout << endl;
        // }

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < s + 1; j++)
            {

                if ((j != 0) && (i == 0))
                    t[i][j] = 0;

                else if (j == 0)
                    t[i][j] = 1;

                else if (arr[i - 1] <= j)
                    t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);

                else
                    t[i][j] = t[i - 1][j];
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
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends