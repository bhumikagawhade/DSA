class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        int total = m*n;
        vector<int> nums;
        int remainder = (grid[0][0]%x + x)%x;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((grid[i][j]%x +x)%x != remainder){
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());
        int median = nums[total/2];
        int op=0;

        for(int num : nums){
            op+= abs(num-median)/x;
        }

        return op;
    }
};