class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n);
        
        // Forward Pass
        int pos = -100000;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }
        
        // Backward Pass
        pos = 100000;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) pos = i;
            res[i] = std::min(res[i], pos - i);
        }
        
        return res;

    }
};