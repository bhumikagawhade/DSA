class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();

        int buy=prices[0];
        int sell=prices[1];

        for(int i=0;i<n-1;i++){
            buy=min(buy,prices[i]);
            
            int current=prices[i+1]-buy;
            profit=max(current,profit);

        }
        //profit=sell-buy;
        if(profit>0){
            return profit;
        }
        return 0;

    }
};