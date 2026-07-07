class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        long mod = 1000000007 ;
        long [][] dp = new long [n+1][target+1];

        for(long [] row : dp ){
            Arrays.fill(row,0);
        }

        dp[0][0] = 1;

        // if(dp[n][target] != 0 ){
        //     return dp[n][target];
        // }

        for(int i=1 ; i<=n ;i++){
            for(int j=1 ; j<=target ; j++){
                for( int val =1; val<=k ; val++){
                    if(j-val >= 0){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-val]) % mod;

                    }
                }
            }
        }

        return (int)dp[n][target];

    }
}