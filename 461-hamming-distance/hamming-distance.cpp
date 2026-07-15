class Solution {
public:
    int hammingDistance(int x, int y) {
        int count =0;
        while(x!=0 || y!=0){
            int bitx = x&1;
            int bity = y&1;

            if( bitx != bity){
                count++;
            }

            x=x>>1;
            y=y>>1;
        }

        return count;
    }
};