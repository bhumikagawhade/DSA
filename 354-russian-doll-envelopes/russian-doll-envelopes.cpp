class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort with custom width-asending height-decending 

        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a ,const vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1]; //decending
            }
            else{
                return a[0] < b[0]; //asending
            }
        });

        //lis logic
        vector<int> ans;
        for(auto env : envelopes){
            int currHeight = env[1];

            //loer bound
            auto element = lower_bound(ans.begin(),ans.end(),currHeight);
            if( element == ans.end()){
                ans.push_back(currHeight);
            }
            else{
                *element = currHeight;
            }
        }

        return ans.size();

    }
};