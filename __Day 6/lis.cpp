class Solution {
public:


   
    int lengthOfLIS(vector<int>& l) {
    int n = l.size();
    vector<int> lis(n,1);
   
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(l[j]<l[i])
        {
            lis[i]=max(lis[i],1+lis[j]);
        }
      }
    }
    sort(lis.begin(),lis.end());
    return lis[n-1];
        
    }
};