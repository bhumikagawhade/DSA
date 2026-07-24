class Solution {
public:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& max_len) {
        // Expand outward as long as characters match and boundaries are valid
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        // After loop breaks, the valid palindrome length is (right - left - 1)
        int current_len = right - left - 1;
        if (current_len > max_len) {
            max_len = current_len;
            start = left + 1; // The valid palindrome started at left + 1
        }
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            expandAroundCenter(s, i, i, start, max_len);
            
            // Case 2: Even length palindromes (e.g., "abba", center is between 'b' and 'b')
            expandAroundCenter(s, i, i + 1, start, max_len);
        }

        return s.substr(start, max_len);
    }
};