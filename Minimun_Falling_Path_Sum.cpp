// memoization

class Solution {
public:
    
    int f(int i,int j,int n,vector<vector<int>>& matrix ,vector<vector<int>>& dp){
       
        if(j<0 || j>=n)return 1e9;
         if(i==n-1) return matrix[n-1][j];
        if(dp[i][j]!=-1)return dp[i][j];
            
            
        int ld=matrix[i][j]+f(i+1,j-1,n,matrix,dp);
        int down=matrix[i][j]+f(i+1,j,n,matrix,dp);
        int rd=matrix[i][j]+f(i+1,j+1,n,matrix,dp);
        
        return dp[i][j]=min(ld,min(down,rd));
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



// Time Complexity: O(N*N)

// Reason: At max, there will be M*N calls of recursion to solve a new problem,

// Space Complexity: O(N) + O(N*M)

// Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’.




// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
     
        for(int j=0;j<n;j++) dp[n-1][j]=matrix[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int ld =matrix[i][j];
                if(i+1<n && j-1>=0)
                   ld += dp[i+1][j-1];
                else ld+=1e9;
                
               
                int down=matrix[i][j]+ dp[i+1][j];
                
                int rd=matrix[i][j];
                if(i+1<n && j+1<n)
                     rd+=dp[i+1][j+1];
                else rd+=1e9;
                
                dp[i][j]=min(ld,min(down, rd));
            }
        }
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }

};