class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        int n= nums.size();

        for(int i : nums){
            st.insert(i);
        }

        for(int i=1; i<=n ; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }

        return ans;

    }
};