// memoization
class Solution {
public:
 int   f(int n,vector<int>&dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
       int ans=f(n,dp);
        return ans;
        
    }
};
// Time complexity-->O(n) and 
// space complexity-->O(n)for axuliry space + O(n) for dp array =O(2n) or O(n)

// Tabulation
class Solution {
public:
	int fib(int n) {
	
	if(n==0 || n==1){
		return n;
	}
	vector<int>dp(n+1,-1);
	dp[0] = 0; dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
	}
};

// Time complexity-->O(n) and 
// space complexity-->O(n) (dp array)

// Space Optimization
class Solution {
public:
	int fib(int n) {
	if(n==0 || n==1){
		return n;
	}
	int  prev2=0;
        int prev=1;
   
        for(int i=2;i<=n;i++){
            int curr_i=prev2+prev;
            prev2=prev;
            prev=curr_i;
            
        }
        return prev;
	}
};

// Time complexity-->O(n) and 
// space complexity-->O(1) 