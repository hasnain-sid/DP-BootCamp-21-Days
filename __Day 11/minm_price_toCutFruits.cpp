class Solution {
    public int minimumCoins(int[] prices) {
        int dp[][] = new int[prices.length][prices.length+1];
        for(int d[] : dp){
            Arrays.fill(d,-1);
        }
        return solve(0,0,prices,dp);
    }
    public int solve(int i,int free,int prices[],int dp[][]){
        if(i>=prices.length)
            return 0;
        if(dp[i][free]!=-1)
            return dp[i][free];
        int take = solve(i+1,i+1,prices,dp)+prices[i];
        int nottake = Integer.MAX_VALUE;
        if(free>0){
            nottake  = solve(i+1,free-1,prices,dp);
        }
        return dp[i][free] = Math.min(take,nottake);
    }
}