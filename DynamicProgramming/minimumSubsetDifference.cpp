// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    bool isSubsetSum(int n, int arr[], int s)
    {
        int t[n + 1][s + 1];
        memset(t, 0, sizeof(t));

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

    int minDifference(int arr[], int n)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        int start = sum / 2;

        while (start != -1)
        {
            if (isSubsetSum(n, arr, start))
                return abs(sum - 2 * start);
            else
                start--;
        }

        // Your code goes here
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends