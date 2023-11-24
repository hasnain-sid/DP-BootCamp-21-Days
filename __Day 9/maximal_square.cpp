class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        vector<vector<int>> mat;
        for(int i = 0; i < a.size(); i++)
        {
            vector<int> tmp;
            for(int j = 0; j < a[i].size(); j++)
            {
                tmp.push_back(char(a[i][j]) - '0');
            }
            mat.push_back(tmp);
        }
       int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] and i and j)
                    mat[i][j]=min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]})+1;
                ans=max(ans,mat[i][j]);
            }
        }
        return ans*ans;
    }
};