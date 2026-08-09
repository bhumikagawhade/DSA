class Solution {
public:
    int solve(int index,int end,vector<int>&nums,vector<int>&dp){
        if(index >end){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int include=nums[index]+solve(index+2,end,nums,dp);
        int exclude=0+solve(index+1,end,nums,dp);

        int ans = max(include ,exclude);
        dp[index]=ans;
        return ans;
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1){
            return nums[0];
        }

        //for exclude last 
        vector<int> dp1(n+1,-1);
        int ans1=solve(0,n-2,nums,dp1);

        //exclude first house
        vector<int> dp2(n+1,-1);
        int ans2=solve(1,n-1,nums,dp2);

        return max(ans1,ans2);
    }
};