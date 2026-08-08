class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // Scan from the back to find the largest valid triangle
        for (int i = nums.size() - 3; i >= 0; --i) {
            if (nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        
        // Return 0 if no valid triangle can be formed
        return 0;
    }
};