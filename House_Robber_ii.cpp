// memoization
int f(int i,vector<int>&nums,vector<int>&dp){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob=f(i-2,nums,dp)+nums[i];
        int nonRob=f(i-1,nums,dp)+0;
        return dp[i]=max(rob,nonRob);
    }
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int>test1,test2;
        for(int i=0;i<n;i++){
            if(i!=0) test1.push_back(nums[i]);
            if(i!=n-1) test2.push_back(nums[i]);
        }
        return max(f(n-2,test1,dp1),f(n-2,test2,dp2));
    }
};

// Time complexity--> 


// Tabulation
int f(int i,vector<int>&nums,vector<int>&dp){
     dp[0]=nums[0];
      int n=nums.size();
       for(int i=1;i<n;i++){
        int rob=nums[i];
        if(i>1) rob+=dp[i-2];
        int nonRob=dp[i-1];
         dp[i]=max(rob,nonRob);
    }
        return dp[n-1];
    }
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int>test1,test2;
        for(int i=0;i<n;i++){
            if(i!=0) test1.push_back(nums[i]);
            if(i!=n-1) test2.push_back(nums[i]);
        }
        return max(f(n-2,test1,dp1),f(n-2,test2,dp2));
    }
};



// Space Optimization

int f(vector<int>&nums){
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
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
if(n==2) return max(nums[0],nums[1]);
        vector<int>test1,test2;
        for(int i=0;i<n;i++){
            if(i!=0) test1.push_back(nums[i]);
            if(i!=n-1) test2.push_back(nums[i]);
        }
        return max(f(test1),f(test2));
    }
};

