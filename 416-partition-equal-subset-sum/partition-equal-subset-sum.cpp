class Solution {
public:

    bool solve(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        //base case 
        int n = nums.size();
        if( index >= n){
            return 0;
        }

        if(target < 0){
            return 0; //return false = 0
        }

        if(target == 0){
            return 1; //return true = 1
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = solve(nums,index+1,target-nums[index],dp);
        bool exclude = solve(nums,index+1,target,dp);

        return dp[index][target] = (include || exclude);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size() ; i++){
            sum+=nums[i];
        }
        if(sum&1 == 1) return false ;
        int target = sum/2;
        int index = 0;
        vector<vector<int>> dp(nums.size(),vector<int> (target+1,-1)); // 2d array bc index and target is chaning.
        bool ans = solve(nums,index,target,dp);
        return ans ;

    }
};