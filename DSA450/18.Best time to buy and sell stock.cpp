class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPurchase=INT_MAX;
        int res=0;
        for(auto &x:prices){
            mnPurchase=min(mnPurchase,x);
            res=max(res,x-mnPurchase);
        }
        return res;
    }
};