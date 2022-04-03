// memoization

class Solution {
    int slove(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=slove(i,j+1,m,n,dp);
        int down=slove(i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return slove(0,0,m,n,dp);
    }
};


// sloution---->>2

int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp);
  int left = countWaysUtil(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}

int countWays(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp);
    
}

// Time Complexity: O(M*N)
// Reason: At max, there will be M*N calls of recursion.

// Space Complexity: O((N-1)+(M-1)) + O(M*N)

// Reason: We are using a recursion stack space:O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.



// Tabulation

class Solution {
  
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
       for(int j=n-1;j>=0;j--){
           for(int i=m-1;i>=0;i--){
                if(i==m-1 && j==n-1){
                    dp[i][j]=1;
                    continue;
                                    }
        
                int right=0;
               if(j<n-1) right+= dp[i][j+1];
        int down=0;
              if(i<m-1)down+= dp[i+1][j];
              dp[i][j]=right+down; 
           }
       }
        return dp[0][0];
    }
};

// sloution --->>2
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){ 
                    dp[i][j]= 1;
                    continue;
                                }
                
                int up=0;
                if(i>0) up=dp[i-1][j];
                int left=0;
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};
// Time Complexity: O(M*N)

// Reason: There are two nested loops

// Space Complexity: O(M*N)

// Reason: We are using an external array of size ‘M*N’’.