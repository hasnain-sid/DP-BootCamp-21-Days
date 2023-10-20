class Solution {
public:

    int final_ans = INT_MIN;
    int solve(vector<int> & a, vector<int>& b,int i, int j,vector<vector<int>>& dp)
    {
        if(i == a.size())
            return 0;
        if(j == b.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans1 = 0,ans2 = 0;
        int f = 0;
        if(a[i] == b[j])
        {
            ans1 = solve(a,b,i+1,j+1,dp)+1;
        }
          
        int a1 = solve(a,b,i+1,j,dp);
        int b1 = solve(a,b,i,j+1,dp);
        
        final_ans = max(final_ans,ans1);
        
        
        return dp[i][j] = ans1;

    }
   


    int findLength(vector<int>& text1, vector<int>& text2) {

        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        solve(text1,text2,0,0,dp);
        return final_ans;
        
    }
};
