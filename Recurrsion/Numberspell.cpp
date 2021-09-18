// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    
     
    
    
public:
    string convertToWords(long n) {
        
        map<pair<long,long>,string>m1;
        

        m1[{1,1}] = "eno ";
        m1[{1,0}] = "net ";
        m1[{2,1}] = "owt ";
        m1[{2,0}] = "ytnewt ";
        m1[{3,1}] = "eerht ";
        m1[{3,0}] = "ytriht ";
        m1[{4,1}] = "ruof ";
        m1[{4,0}] = "ytrof ";
        m1[{5,1}] = "evif ";
        m1[{5,0}] = "ytfif ";
        m1[{6,1}] = "xis ";
        m1[{6,0}] = "ytxis ";
        m1[{7,1}] = "neves ";
        m1[{7,0}] = "ytneves ";
        m1[{8,1}] = "thgie ";
        m1[{8,0}] = "ythgie ";
        m1[{9,1}] = "enin ";
        m1[{9,0}] = "ytenin ";
        m1[{3,2}] = "derdnuh ";
        m1[{4,2}] = "dnasuoht ";
        m1[{6,2}] = "hkal ";
        m1[{8,2}] = "erorc ";
        m1[{0,3}] = "net " ;
        m1[{1,3}] = "nevele ";
        m1[{2,3}] = "evlewt ";
        m1[{3,3}] = "neetriht ";
        m1[{4,3}] = "neetruof ";
        m1[{5,3}] = "neetfif ";
        m1[{6,3}] = "neetxis ";
        m1[{7,3}] = "neetneves ";
        m1[{8,3}] = "neethgie ";
        m1[{9,3}] = "neetenin ";

        string s = to_string(n);
        int size = s.size()-1;
        string str;
       // reverse(s.begin(),s.end());
        
  
        long j=0;
        for(long i=s.size()-1;i>=0;i--)
        {

            //cout << "i= " << i << endl;
            int y = int(s[i]) -48;
            // cout << "y= " << y << endl;
            j++;

            //cout << "j= " << j << endl;
             if(j<3)
            {
            //   cout << "jji= " << i << endl;    
            if(s[s.size()-2] == '1')
            {
                // cout << "stt" << endl;
                // cout << "y= " << y << endl;
                str.append(m1[{y,3}]);
                i--;
                j++;
                
            }
            
             else
             {
                 if(s[i]!= '0')
             {
                   str.append(m1[{y,j%2}]);
             }
                // cout << str << endl;
             }
               
            }
             
               
             
             
            
             
            if(j==3)
            { 
               if(str != "")    
             str.append("dna ");
              
             if(s[i]!= '0' )
             {
            
             str.append(m1[{3,2}]);
             str.append(m1[{y,j%2}]);
             }
            
            //  cout << str << endl;
            }
           
            
            if(j>3)
            {

             if(s[i]!= '0')
             {
                //   cout << "bhullu " << endl;
                 if(j==4 || j==6 || j==8)
                     str.append(m1[{j,2}]);

                
                if(i>=0)
                {
                    
                if((i>=1) && (s[i-1]== '1'))
                {
                // cout << "stt" << endl;
                // cout << "y= " << y << endl;
                str.append(m1[{y,3}]);
                i--;
                j++;
                }

             else
             {   
                
               
                // cout << "thullu " << endl;
                if((s[i+1] == '0') && (j>4))
                str.append(m1[{j-1,2}]);

                str.append(m1[{y,(j+1)%2}]);
                
             }

             }
             }
            //   cout << "hh= " <<str << endl;
            }
            
        }
        
        reverse(str.begin(),str.end());
        
         str.erase(0,1);
        return str;
       
        
        
    }
};



 
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends