class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp; // char ,index 
        int start =0 ;
        int maxlength=0;

        for(int i=0;i<s.length();i++){
            char ch = s[i];

            if(mp.find(ch) != mp.end() && mp[ch] >= start){
                start = mp[ch]+1;
            }
            mp[ch] = i;
            maxlength = max(maxlength,i-start+1);
        }

        return maxlength;
        
    }
};