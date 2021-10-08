#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        int n=str.length(),arr[26]={0};
        for(int i=0;i<n;i++)arr[str[i]-'a']++;
        priority_queue<pair<int,char>> pq;
        
        for(int i=0;i<26;i++)pq.emplace(arr[i],(char)(i+'a'));
        if(pq.top().first>(n+1)/2)return "-1";
        int i=0;
        while(!pq.empty()){
            int m=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            for(int j=0;j<m;j++){
                if(i>n-1)
                i=1;
                str[i]=c;i+=2;
            }
        }
        return str;
    }
    
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  