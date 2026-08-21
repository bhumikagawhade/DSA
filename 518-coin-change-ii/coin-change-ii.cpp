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
        vector<vector<unsigned long long >> dp(amount+1,vector<unsigned long long >(coins.size()+1,0));

        for(int i=0 ;i<coins.size();i++){
            dp[0][i] = 1;
        }

        for(int i=1;i<=amount;i++){
            for(int j=coins.size()-1;j>=0;j--){
                int currcoin = coins[j];
                unsigned long long inc = 0;
                if(i-currcoin >= 0){
                    inc = dp[i-currcoin][j];
                }
                
                unsigned long long exc = dp[i][j+1];

                dp[i][j]=inc+exc;
            }
        }

        // int total=solve(amount,coins,0,dp);
        // return total;

        return dp[amount][0];
    }
};