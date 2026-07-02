class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Track the last occurrence index of each character
        unordered_map<char, int> last_occ;
        for (int i = 0; i < s.length(); i++) {
            last_occ[s[i]] = i;
        }
        
        string result = "";          // Acts as our monotonic stack
        unordered_set<char> visited; // Hash set to track characters in the stack
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If character is already in our stack, skip it
            if (visited.count(c)) {
                continue;
            }
            
            // Pop larger characters from the stack if they appear again later
            while (!result.empty() && result.back() > c && last_occ[result.back()] > i) {
                visited.erase(result.back()); // Remove from hash set
                result.pop_back();            // Pop from stack
            }
            
            // Add current character to stack and hash set
            result.push_back(c);
            visited.insert(c);
        }
        
        return result;
    }
};