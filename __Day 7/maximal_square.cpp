class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = 0;
        int prev = 0; // previous row value of dp[j-1]
        vector<int> dp(n+1, 0); // one-dimensional dp array
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j]; // store previous value of dp[j]
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min(dp[j], min(dp[j-1], prev)) + 1;
                    maxLen = max(maxLen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp; // update prev
            }
        }
        
        return maxLen * maxLen;
    }
};
