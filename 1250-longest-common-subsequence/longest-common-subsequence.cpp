class Solution {
public:
    int solve(string& a ,string& b , int i ,int j, vector<vector<int>> &dp){
        if( i == a.length()) return 0;
        if( j == b.length()) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a,b,i+1,j+1,dp);
        }
        else{
            ans = 0+ max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0 ;
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));

        int ans= solve(text1,text2,i,j,dp);
        return ans;
    }
};