class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        //ans.push_back(0);
        for(int i=0 ;i<=n; i++){
            int count = 0 ;
            int num=i;
            while(num>0){
                int bit = num&1;
                if(bit == 1){
                    count++;
                }
                num=num>>1;
            }
            ans.push_back(count);
        }

        return ans;
    }
};