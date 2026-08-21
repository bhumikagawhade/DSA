class Solution {
public:
    int solve(int amount,vector<int>& coins,int index,vector<vector<int>>& dp){
        //base case
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size() || amount <0){
            return 0;
        }

        if(dp[amount][index] != -1){
            return dp[amount][index];
        }

        //recursion 

        int inc = solve(amount-coins[index],coins,index,dp);
        int exc = solve(amount,coins,index+1,dp);

        dp[amount][index]=inc+exc;

        return dp[amount][index];


    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        int total=solve(amount,coins,0,dp);
        return total;
    }
};