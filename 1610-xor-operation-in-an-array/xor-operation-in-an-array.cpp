class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        nums.push_back(start);
        int ans = start;

        for(int i=1 ;i<n; i++){
            int element =  start + 2*i;
            nums.push_back(element);
            ans^=element;
        }
        return ans;
    }
};