class Solution {
public:
    
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fiboTerm;
        fiboTerm.push_back(1);
        fiboTerm.push_back(1);
        int i=2;
        while((1LL*fiboTerm[i-1]+1LL*fiboTerm[i-2])<=1000000000){
            fiboTerm.push_back(fiboTerm[i-1]+fiboTerm[i-2]);
            i++;
        }
        
        int ans=0;
        for(int i=fiboTerm.size()-1;i>=0;i--){
            if(k==0){
                break;
            }
            if(fiboTerm[i]<=k){
                
                ans+=k/fiboTerm[i];
                k-=k/fiboTerm[i]*fiboTerm[i];
            }
            
        }
        return ans;
        
    }
};