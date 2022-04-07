// memoization

int solve(int ind,int W, int maxWeight, int n, vector<int> &weight, vector<int>&value,vector<vector<int>> &dp){
    if(W>maxWeight) return -1e9;
    if(ind == n) return 0;
    if(dp[ind][W]!=-1) return dp[ind][W];
    
    int steal = value[ind] + solve(ind+1, W+weight[ind], maxWeight,n, weight, value,dp);
    int notSteal = 0 + solve(ind+1, W, maxWeight,n, weight, value,dp);
    
    return dp[ind][W]=max(steal, notSteal);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{  
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	return solve(0,0, maxWeight, n , weight, value,dp);
}