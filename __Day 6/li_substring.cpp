

//User function Template for Java

class Solution{
    int max_length = 0;
    int dp[][] = new int[1001][1001];
    int lis(String a,String b,int n,int m,int i,int j)
    {
        if(i == n || j == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if(a.charAt(i) == b.charAt(j))
        {
            ans = 1 + lis(a,b,n,m,i+1,j+1);
        }
        
        lis(a,b,n,m,i,j+1);
        lis(a,b,n,m,i+1,j);
        max_length = Math.max(max_length,ans);
        return dp[i][j] = ans;
    }
    int longestCommonSubstr(String S1, String S2, int n, int m){
        // code here
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = -1;
            }
        }
        lis(S1,S2,n,m,0,0);
        return max_length;
    }
}