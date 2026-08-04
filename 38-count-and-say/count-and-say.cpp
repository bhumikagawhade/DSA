class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";
        
        // Pre-allocate strings to prevent frequent dynamic resizing overhead
        string current = "1";
        string next_term;
        next_term.reserve(4462); // Max sequence length for n=30 is 4462
        
        for (int i = 2; i <= n; ++i) {
            next_term.clear();
            int len = current.length();
            
            int start = 0;
            while (start < len) {
                int run_length = 1;
                
                // Count consecutive identical characters
                while (start + run_length < len && current[start] == current[start + run_length]) {
                    run_length++;
                }
                next_term.push_back('0' + run_length);
                next_term.push_back(current[start]);
                
                // Advance pointer past the processed run
                start += run_length;
            }
            
            // Move contents instead of copying to preserve allocation spaces
            current = move(next_term);
        }
        
        return current;
    }
};