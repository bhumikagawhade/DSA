class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128,0);

        for(char ch: s){
            freq[ch]++;
        }

        int length = 0;
        bool has_odd = false;

        for(int c : freq){
            length+=(c/2)*2;

            if( c%2 == 1){
                has_odd=true;
            }
        }

        if(has_odd){
            length+=1;
        }

        return length;
    }
};