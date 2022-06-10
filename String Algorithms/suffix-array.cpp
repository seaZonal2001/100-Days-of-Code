#include<bits/stdc++.h>
using namespace std;

class suffixArray{
    public:
    #define MAX_N 100010
    string s;                                                       //input string
    int n;                                                          //Length of input string
    vector<int> RA,tempRA;                                          //rank array and temporary rank array
    vector<int> SA,tempSA;                                          //suffix array and temporary suffix array
    vector<int> c;                                                  //for counting / radix sort
    vector<int> Phi,PLCP,LCP;

    suffixArray(int n,string s){
        this->s=s;
        this->n=n;
        RA.resize(MAX_N);
        tempRA.resize(MAX_N);
        SA.resize(MAX_N);
        tempSA.resize(MAX_N);
        c.resize(MAX_N);
    }
    
    void countingSort(int k){                                       //O(n)
        int i,sum,maxi = max(300,n);                                //upto 255 ASCII chars or length of n
        fill(c.begin(),c.end(),0);                                  //clear frequency table
        for(i=0;i<n;i++){                                           //count the frequency of each integer rank
            c[i+k<n?RA[i+k]:0]++;
        }
        for(i=sum=0;i<maxi;i++){
            int t=c[i];
            c[i]=sum;
            sum+=t;
        }
        for(i=0;i<n;i++){                                           //shuffle the suffix array if necessary
            tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
        }
        for(i=0;i<n;i++){                                           //update the suffix array SA
            SA[i]=tempSA[i];
        }
    }

    vector<int> constructSA(){                                      //this version can go upto 100000 characters
        int i,k,r;
        for(i=0;i<n;i++)RA[i]=s[i];                                 //initial rankings
        for(i=0;i<n;i++)SA[i]=i;                                    //initial SA: {0,1,2,....n-1}
        for(k=1;k<n;k<<=1){                                         //repeat sorting process log n times
            countingSort(k);                                        //actually radix sort:sort based on the second item
            countingSort(0);                                        //then (stable) sort based on the first item

            tempRA[SA[0]]=r=0;                                      //re-ranking; start from rank r=0
            for(i=1;i<n;i++){
                tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r; //if same pair => same rank r; otherwise, increase r
            }
            for(i=0;i<n;i++){                                       //update the rank array RA
                RA[i]=tempRA[i];
            }
            if(RA[SA[n-1]]==n-1)break;                              //nice optimization trick
        }
        return SA;
    }

    vector<int> computeLCP(){
        int i,L;
        Phi.resize(MAX_N);
        PLCP.resize(MAX_N);
        LCP.resize(MAX_N);
        Phi[SA[0]]=-1;                                              //default value;
        for(i=1;i<n;i++){                                           //compute Phi in O(n)
            Phi[SA[i]]=SA[i-1];                                     //remember which suffix is behind this suffix
        }
        for(i=L=0;i<n;i++){                                         //compute permuted LCP in O(n)
            if(Phi[i]==-1){                                         //special case
                PLCP[i]=0;
                continue;
            }
            while(s[i+L]==s[Phi[i]+L])L++;                          //L increased max n times
            PLCP[i]=L;
            L=max(L-1,0);                                           //L decreased max n times
        }
        for(i=0;i<n;i++){                                           //compute LCP in O(n)
            LCP[i]=PLCP[SA[i]];                                     //put the permuted LCP to the correct position
        }
        return LCP;
    }
};

int main(){
    int n;cin>>n;
    string s;cin>>s;
    s+='$';
    suffixArray sa(n,s);
    vector<int> SA=sa.constructSA();
    vector<int> LCP=sa.computeLCP();
    for(int i=0;i<n;i++)cout<<SA[i]<<' ';
    cout<<'\n';
    for(int i=0;i<n;i++)cout<<LCP[i]<<' ';
    return 0;
}