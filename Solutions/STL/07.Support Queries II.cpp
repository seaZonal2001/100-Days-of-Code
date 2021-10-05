#include<bits/stdc++.h>
using namespace std;
class myStructure{
    multiset<int> s1,s2;
    long long sum;
    int k;
    public:
    myStructure(int k):k(k),sum(0){};
    void add(int value){
        s1.insert(value);
        sum+=value;
        if(s1.size()>k){
            int aux=*s1.begin();
            s1.erase(s1.begin());
            s2.insert(aux);
            sum-=aux;
        }
    }
    void remove(int value){
        if(s2.find(value)!=s2.end()){
            s2.erase(s2.find(value));
        }else if(s1.find(value)!=s1.end()){
            sum-=value;
            s1.erase(s1.find(value));
            if(s2.empty())return;
            int y=*s2.rbegin();
            s2.erase(s2.find(y));
            sum+=y;
        }
    }
    int getSum(){
        return sum;
    }
};
int main(){
    int queries,k;
    cin>>queries>>k;

    myStructure M(k);
    int type,value;
    char ask;
    while(queries--){
        cin>>type;
        switch(type){
            case 1:
                cin>>value;
                M.add(value);
            break;
            case 2:
                cin>>value;
                M.remove(value);
            break;
            case 3:
                cout<<M.getSum()<<'\n';
            break;
            default:
            cout<<"Enter valid query\n";
        }
    }

}