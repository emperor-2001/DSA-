// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    vector<string>v;
    string str;
    
	public:
	
	        void swapp(char * c,  char * d)
         {
             char temp;
             temp = *c;
             *c = *d;
             *d = temp;

             return;
         }
	
		vector<string>find_permutation(string S)
		{
		    
		    if(S.size()==0)
		    {
		       v.push_back(str);
            //    cout << str << "   gobar" << endl;
		    }     
		       
		    for(int i=0;i<S.size();i++)
		    {
		        str.push_back(S[i]);
		        swapp(&S[i],&S[0]);
		        string snew = S;
		        snew.erase(0,1);
		        find_permutation(snew);
		        str.pop_back();
				
		    }
		    
		    return v; 
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends