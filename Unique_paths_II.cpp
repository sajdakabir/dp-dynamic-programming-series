// memoization
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
         if(obstacleGrid[m-1][n-1]==1)return 0;
        for(int j=n-1;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                 if(i==m-1 && j==n-1){
                     dp[i][j]=1;
                      continue;
                 }
                  if(obstacleGrid[i][j]==1 && i<m-1 && j<n-1) {
                      dp[i][j]=0;
                   
                  }
                int right=0;
                if(j<n-1){
                    right+=dp[i][j+1];
                }
                int down=0;
                if(i<m-1){
                    down+=dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }