class Solution {
public:
     int f(int i,int j,int n,vector<vector<int>>& matrix ,vector<vector<int>>& dp){
       
        if(j<0 || j>=n)return 1e9;
         if(i==n-1) return matrix[n-1][j];
        if(dp[i][j]!=-1)return dp[i][j];
            
         int mini=1e9;
            
       for(int newCol=0; newCol<n;newCol++){
           
           if(newCol!=j){
               int ans=matrix[i][j]+f(i+1,newCol,n,matrix,dp);
               mini=min(mini,ans);
           }
       } 
         return dp[i][j]=mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {   
          int n=matrix.size();
         vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int ans=f(0,j,n,matrix,dp);
            mini=min(ans,mini);
        }
        return mini;
    }
};