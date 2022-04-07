// memoization
int f(int i,int l,int n,vector<int> &price,vector<vector<int>>&dp){
    if(l==n || i==n)return 0;
    if(l>n )return -1e9;
    if(dp[i][l]!=-1)return dp[i][l];
    int cut=price[i]+f(i,l+i+1,n,price,dp);
    int notCut=f(i+1,l,n,price,dp);
    return dp[i][l]=max(cut,notCut);
}
int cutRod(vector<int> &price, int n)
{
 vector<vector<int>>dp(n,vector<int>(n,-1));
    if(n==0)return price[0]*n;
    return f(0,0,n,price,dp);
	
}


// Time Complexity: O(N*N)

// Reason: There are N*(N+1) states therefore at max ‘N*(N+1)’ new problems will be solved.

// Space Complexity: O(N*N) + O(N)

// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*(N+1)).
