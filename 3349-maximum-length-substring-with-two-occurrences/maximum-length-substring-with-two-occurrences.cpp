class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> cnt;
        int ans = 0;
        int i = 0;
        
        for (int j = 0; j < s.length(); j++) {
            cnt[s[j]]++;
            
            while (cnt[s[j]] > 2) {
                cnt[s[i]]--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};