class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int mod = 1e9 + 7;
    // int dp[5001][5001] = {-1};
  
    int helper(int i, int n,int dp[][5001])
    {
        
        if(n == 0)
            return 1;
        if(dp[i][n] != -1)
            return dp[i][n];
        vector<int> curr = mp[i];
        int ans = 0;
        for(auto it: curr)
        {
            ans= ((ans)%mod)+ (helper(it,n-1,dp))%mod;
        }
        return dp[i][n] = ans;
    }
    int knightDialer(int n) {
    //    memset
       mp[1] = {6,8};
       mp[2] = {7,9};
       mp[3] = {4,8};
       mp[4] = {3,9,0};
       mp[5] = {};
       mp[6] = {1,7,0};
       mp[7] = {2,6};
       mp[8] = {1,3};
       mp[9] = {2,4};
       mp[0] = {4,6};
        n = n-1;
        long long ans = 0;
        
        int dp[10][5001] ;
        // k = n;
        memset(dp,-1,10*(5001)*sizeof (int));

        
       for(int i = 0; i <= 9 ; i++)
       {
        //    if(i == 5) continue;

           ans = ans%mod + (helper(i,n,dp))%mod;
           ans %= mod;
       }
       return ans;

    
        
    }
};