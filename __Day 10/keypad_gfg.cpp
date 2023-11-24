class Solution {
public:
    vector<int> dp;
    int helper(unordered_map<int,int> &mp,vector<int> &nums,int i)
    {
        if(i == nums.size())
        {
            return 0;
        }
        if(dp[i] != -1) return dp[i];


        // pick
        int a=0,t,x,b=0;
        bool f = false,m = false;
        if(mp.find(nums[i]-1) != mp.end())
        {
            t = mp[nums[i]-1];
            f = true;
        }
        if(mp.find(nums[i]+1) != mp.end())
        {
            m = true;
        }
        if(m)
        {
            if(f)
            {
                a = nums[i]*mp[nums[i]] - t*(nums[i]-1)  + helper(mp,nums,i+2);
            }
            else
                a = nums[i]*mp[nums[i]] + helper(mp,nums,i+2);
        }
        else
        {
            if(f)
            {
                a = nums[i]*mp[nums[i]] - t*(nums[i]-1)  + helper(mp,nums,i+1);
            }
            else
                a = nums[i]*mp[nums[i]] + helper(mp,nums,i+1);
        }
        
        // backtracking step
        if(f)
        {
            a+=t*(nums[i]-1);
        }


        // not_pick
        b = helper(mp,nums,i+1);
        return dp[i] = max(a,b);


        
        
    }
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        nums.resize(unique(nums.begin(),nums.end()) - nums.begin());
        for(int i = 0; i < nums.size()+2; i++)
        dp.push_back(-1);
        return helper(mp,nums,0);
        
    }
};