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

// Time Complexity: O(M*N)
// Reason: At max, there will be M*N calls of recursion.

// Space Complexity: O((N-1)+(M-1)) + O(M*N)

// Reason: We are using a recursion stack space:O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.



// Tabulation