#include<bits/stdc++.h>
using namespace std;

char solve(char a,char b,char c){
    int m=a-'0',n=c-'0';
    if(b=='&')return '0'+(m&n);
    else if(b=='|')return '0'+(m|n);
    else return '0'+(m^n);
}

int eval(string &s,int val){
    int n=s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(')continue;
        else if(s[i]==')'){
            char oprnd1=st.top();
            st.pop();
            char oprtr=st.top();
            st.pop();
            char oprnd2=st.top();
            st.pop();
            st.push(solve(oprnd1,oprtr,oprnd2));
        }else{
            if(s[i]=='x')st.push('0'+val);
            else if(s[i]=='X')st.push('0'+1-val);
            else st.push(s[i]);
        }
    }
    return st.top()-'0';
}

void solution(){
    string s;cin>>s;
    int x=eval(s,0);
    int y=eval(s,1);
    if(x==y)cout<<"0\n";
    else cout<<"1\n";
}

int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}