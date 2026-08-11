class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> prefix;
        //prefix.push_back(nums[0]);
        for(int i=0 ;i<nums.size();i++){

            if(i+1 < nums.size() && nums[i+1] == nums[i]+1){
                prefix.push_back(nums[i]);
            }
            else{
                prefix.push_back(nums[i]);
                break;
            }
        }

        
        int sum=0;
        for(int i=0;i<prefix.size();i++){
            cout<<prefix[i]<<endl;
            sum+=prefix[i];
            cout<<sum;
        }

        while(find(nums.begin(),nums.end(),sum) != nums.end()){
            sum++;
        }

        return sum;
    }
};