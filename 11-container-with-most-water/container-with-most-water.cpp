class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            
            int current_width = right - left;
            int current_height = std::min(height[left], height[right]);
            int current_water = current_width * current_height;
            
            // Track the maximum area
            max_water = max(max_water, current_water);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};