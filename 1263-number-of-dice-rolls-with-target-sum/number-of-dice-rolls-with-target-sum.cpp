class Solution {
public:
    int solve(int n, int k, int target, vector<vector<long long int>> & dp){
        //base case 
        if(n<0 || target<0){
            return 0;
        }

        if( n== 0 && target == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        long long int mod = 1000000007;
        long long int ans = 0;
        for(int i=1 ; i<=k ; i++){
            ans = (ans+solve(n-1,k,target-i,dp))%mod;

        }
        return dp[n][target] =ans;
    }
    int numRollsToTarget(int n, int k, int target) {

        vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,-1));
        int ans = solve(n,k,target,dp);
        return ans;

    }
};