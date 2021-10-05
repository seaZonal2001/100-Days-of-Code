#include<bits/stdc++.h>
using namespace std;
long long sum=0;
void Add(int value,multiset<int> &D){
    sum+=value;
    D.insert(value);
}
void Remove(int value,multiset<int> &D){
    auto it=D.find(value);
    if(it!=D.end()){
        sum-=*it;
        D.erase(it);
    }
}
int getMinimum(multiset<int> &D){
    if(D.empty())return -1;
    return *D.begin();
}
int getMaximum(multiset<int> &D){
    if(D.empty())return -1;
    return *D.rbegin();
}
int getSum(){
    return sum;
}
int main(){
    int queries;
    cin>>queries;
    multiset<int> D;
    int type,value;
    char ask;
    while(queries--){
        cin>>type;
        if(type==1 || type==2)
        cin>>value;
        else 
        cin>>ask;
        switch(type){
            case 1:
            Add(value,D);
            break;

            case 2:
            Remove(x,D);
            break;

            case 3:
             cout<<getMinimum(D)<<'\n';
            break;

            case 4:
            cout<<getMaximum(D)<<'\n';
            break;

            case 5:
            cout<<getSum()<<'\n';
            break;

            default:
            cout<<"Enter valid Query\n";
        }

    }
}