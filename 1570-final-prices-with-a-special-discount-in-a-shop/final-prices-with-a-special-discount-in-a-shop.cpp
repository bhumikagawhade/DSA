class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        vector<int> arr;
        s.push(-1);
        for(int i=prices.size()-1 ; i>=0 ;i--){
            int element = prices[i];
            while(s.top() > element){
                s.pop();
            }
            arr.push_back(s.top());
            s.push(element);
        }
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]>= 0){
                arr[i]=prices[i]-arr[i];
            }
            else{
                arr[i]=prices[i];
            }
        }

        return arr;
    }
};