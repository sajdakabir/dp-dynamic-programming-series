// memoization
class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob=f(i-2,nums,dp)+nums[i];
        int nonRob=f(i-1,nums,dp)+0;
        return dp[i]=max(rob,nonRob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return f(n-1,nums,dp);
        
    }
};

// Time complexity-->O(n) and 
// space complexity-->O(n)for axuliry space + O(n) for dp array =O(2n) or O(n)


// Tabulation
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       dp[0]=nums[0];
      
       for(int i=1;i<n;i++){
        int rob=nums[i];
        if(i>1) rob+=dp[i-2];
        int nonRob=dp[i-1];
         dp[i]=max(rob,nonRob);
    }
        return dp[n-1];
    }
};

// Time complexity-->O(n) and 
// space complexity-->O(n) (dp array)


// Space Optimization
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        
       int prev=nums[0];
      int prev2=0;
       for(int i=1;i<n;i++){
        int rob=nums[i];
        if(i>1) rob+=prev2;
        int nonRob=prev;
       int curr_i=max(rob,nonRob);
           prev2=prev;
           prev=curr_i;
    }
        return prev;
    }
};

// Time complexity-->O(n) and 
// space complexity-->O(1) 