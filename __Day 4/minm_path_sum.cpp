class Solution {
public:
    
    int solve(int row,int col,int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==row-1 && j==col-1){
            return grid[i][j];
        }
        if(i>row-1 || j>col-1){
            return 1000000;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];}

        int down= grid[i][j]+ solve(row,col,i+1,j,grid,dp);
        int right= grid[i][j]+ solve(row,col,i,j+1,grid,dp);

        return  dp[i][j] = min(right,down);



    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp;
           for(int i=0;i<m;i++){
               vector<int> tmp(n,-1);
            //    for(int j=0;j<n;j++){
            //        tmp.push_back()
            //    }
               dp.push_back(tmp);
           }

        return solve(m,n,0,0,grid,dp);
    }
};