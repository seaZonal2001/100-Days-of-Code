#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int LCS[51][51];
	int LCSLen=0;
	vector<string> ans;
	int n,m;
	void printAllLCS(string& s,string& t,string currLCS,int idx1,int idx2){
	    if(currLCS.length()==LCSLen){
	        ans.push_back(currLCS);
	        return ;
	    }
	    if(idx1==n || idx2==m){
	        return ;
	    }
	    
	    for(char c='a';c<='z';c++){
	        bool f=false;
	        for(int i=idx1;i<n;i++){
	            if(c==s[i]){
	                for(int j=idx2;j<m;j++){
	                    if(c==t[j] && LCS[i][j]==currLCS.length()){
	                        printAllLCS(s,t,currLCS+c,i+1,j+1);
	                        f=true;
	                        break;
	                    }
	                }
	            }
	            if(f)
	                break;
	        }
	        
	    }
	    
	    
	}
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    n=s.length(),m=t.length();
		    memset(LCS,0,sizeof(LCS));
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=m;j++){
		            if(s[i-1]==t[j-1])
		                LCS[i][j]=1+LCS[i-1][j-1];
		            else
		                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		        }
		    }
		    LCSLen=LCS[n][m];
		    printAllLCS(s,t,"",0,0);
		    return ans;
		    
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends