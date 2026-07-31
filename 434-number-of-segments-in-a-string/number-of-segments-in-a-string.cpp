class Solution {
public:
    int countSegments(string s) {
        int count=0;
        int i=0;
        while(i<s.length()){
            while(s[i]==' '){
                i++;
            }
            if(i>=s.length()) break;
            int j=i;
            while(j<s.length() && s[j] !=' '){
                j++;
            }
            count++;
            i=j;
        }

        return count;
    }
};