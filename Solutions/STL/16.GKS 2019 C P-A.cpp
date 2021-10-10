#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,map<int,int>> row,col;
void merge(map<int,int> &t,int x){
    if(t.size()==0)t[x]=x;
    else{
        auto itr=t.lower_bound(x);
        int currX=x;
        if(itr!=t.begin()){
            auto temp=itr;
            temp--;
            if(temp->second+1==x)currX=temp->first;
        }
        t[currX]=x;
        if(itr!=t.end()){
            int temp=itr->first;
            if(temp==x+1)t[currX]=t[temp],t.erase(temp);
            
        }
    }

}
void solution(){
    row.clear(),col.clear();
    int q,n,m,x,y;cin>>q>>n>>m>>x>>y;
    string s;cin>>s;
    row[x].insert({y,y});
    col[y].insert({x,x});
    int currX=x,currY=y;
    for(int i=0;i<q;i++){
        char dir=s[i];
        switch (dir)
        {
        case 'N':
        case 'S':{
            auto itr=col[currY].upper_bound(currX);
            itr--;
            int newX=itr->first;
            if(dir=='N')currX=newX-1;
            else currX=col[currY][newX]+1;
        }
            break;
        case 'W':
        case 'E':{
            auto itr=row[currX].upper_bound(currY);
            itr--;
            int newY=itr->first;
            if(dir=='W')currY=newY-1;
            else currY=row[currX][newY]+1;
        }
            break;
        }
        merge(row[currX],currY);
        merge(col[currY],currX);
    }
    cout<<currX<<" "<<currY<<'\n';
    
}
int32_t main(){
    int testCase;cin>>testCase;
    for(int i=1;i<=testCase;i++){
        cout<<"Case #"<<i<<": ";
        solution();
    }
}