class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int,int> mp;
        int left=0;
        for(int right=0 ;right<nums.size(); right++){

            mp[nums[right]]++;

            if(right-left+1 > k){
                mp[nums[left]]--;
                left++;
            }

            if(right-left+1 == k){
                int count =0;
                for(auto element : mp){
                    count+= element.second;

                    if(count>=x){
                        if(element.first < 0 ) ans.push_back(element.first);
                        else ans.push_back(0);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};