// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int t[600][10001];

class Solution
{
public:
    int SubsetSum(int arr[], int n, int s)
    {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n + 1; i++)
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

        return t[n][s];
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return 0;
        else
            return SubsetSum(arr, N, sum / 2);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends