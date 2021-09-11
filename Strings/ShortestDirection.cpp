// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string shortestPath (string S)
    {
        // your code here
        int x=0,y=0;
        string s;
        for(int i=0;i<S.size();i++)
         {
             if(S[i]=='S')
              y--;
             
             else if(S[i]=='N')
              y++;
             
             else if(S[i]=='W')
              x--;
             
             else if(S[i]=='E')
              x++;
             
              
         }
         
         int x1=x, y1=y;
         
         if(x >= 0)
             while(x1--)
             s.append("E");
         
         if(y >= 0)
             while(y1--)
              s.append("N");
         
       
         
          if(y <0)
           while(y1++)
               s.append("S");
                      
         
         
         if(x < 0)
           while(x1++)
              s.append("W");
              
              
          
          return s;
        
       
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.shortestPath (s) << endl;
    }
}
  // } Driver Code Ends