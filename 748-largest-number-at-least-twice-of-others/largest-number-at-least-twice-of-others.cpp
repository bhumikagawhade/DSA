class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxelement = INT_MIN;
        int index=-1;
        for(int i = 0 ;i<nums.size();i++){
            if(nums[i] > maxelement){
                maxelement = nums[i];
                index= i;
            } 
        }

        int half = maxelement/2;
        for(int i=0 ;i<nums.size();i++){
            if( i == index) continue;
            if(nums[i] > half){
                return -1;
            }
        }

        return index;
    }
};