class Solution {
public:
    vector<int> dp;
    int helper(int i,string &s)
    {
        if(i >= s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        int op1 = s[i] - '0';
        int op2 = 0;
        
        if(i < s.size()-1)
        {
            op2 =  op1*10 + (s[i+1] - '0');

        }
        if(op1 > 0) ans = helper(i+1,s);
        if(op1 > 0 and (op2 > 0 and op2 < 27)) ans += helper(i+2,s);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        for(int i = 0; i < s.size() + 5; i++ )
            dp.push_back(-1);
        return helper(0,s);
        
    }
};