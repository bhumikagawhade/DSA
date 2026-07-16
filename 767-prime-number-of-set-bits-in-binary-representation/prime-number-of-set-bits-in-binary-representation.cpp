class Solution {
public:

    bool isPrime(int count){
        if(count ==0 || count == 1){
            return false;
        }
        for(int i=2 ;i<=count/2;i++){
            if((count%i)==0){
                return false;
            }

        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        
        for(int i=left ; i<=right ;i++){
            int countSetBit=0;
            int num = i;
            while(num!=0){
                int bit = num&1;
                if(bit == 1){
                    countSetBit++;
                }
                num = num>>1;
            }

            if(isPrime(countSetBit)){
                ans++;
            }
        }
        return ans;
    }
};