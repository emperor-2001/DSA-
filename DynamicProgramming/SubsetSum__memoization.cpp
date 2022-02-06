// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
int t[102][100002];


class Solution{
public:

    Solution()
    {
      memset(t,-1,sizeof(t[0][0])*102*100002);
    }
    bool isSubsetSum(int N, int arr[], int sum){
        if(N==1)
         {
             if(arr[N-1]==sum)
               return 1;
             else if(arr[N-1]!=sum)
               return 0;
         }

        if(t[N][sum]!=-1)
            return t[N][sum];

        if(arr[N-1]<=sum)
         t[N][sum]= (isSubsetSum(N-1,arr,sum) || isSubsetSum(N-1,arr,sum-arr[N-1]));

        else if(arr[N-1]>sum)
        t[N][sum] = isSubsetSum(N-1,arr,sum);

        return t[N][sum];
    }

};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
  // } Driver Code Ends
