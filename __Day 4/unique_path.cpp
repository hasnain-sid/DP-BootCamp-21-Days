class Solution {
public:
    int solve(int row,int col,int i,int j,vector<vector<int>> &dp){
        
        if(i==row-1 && j==col-1){
            return 1;
        }
        if( dp[i][j] != -1)
        {
            return dp[i][j] ;
        }
        int down = 0,right = 0;
        if(i<row){
            down = solve(row,col,i+1,j,dp);
        }
        if(j<col){
            right = solve(row,col,i,j+1,dp);
        }
        dp[i][j] = down + right;
        return dp[i][j];
        
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                dp[i][j] = -1;
            }
        }
        return solve(m,n,0,0,dp);
        
    }
    
};