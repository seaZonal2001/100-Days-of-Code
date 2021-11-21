class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string a,string b){
        if(a==b)return true;
        if(a.length()<=1)return false;
        string key=a+" "+b;
        if(dp.find(key)!=dp.end())return dp[key];
        int n=a.length();
        bool flag=false;
        for(int i=1;i<n;i++){
            if((solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i))) 
               ||
               (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))){
                flag=true;
                break;
            }
        }
        return dp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
        return solve(s1,s2);
    }
};