class Solution {
public:
    int minimumPushes(string word) {
        int length = word.length();
        int totalPushes = 0;
        
        for (int i = 0; i < length; i++) {
            totalPushes += (i / 8) + 1;
        }
        return totalPushes;
    }
};