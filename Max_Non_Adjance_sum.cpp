// memoization
int f(int i,vector<int>&a ,vector<int>&dp){
    if(i==0)return a[0];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int pick=a[i]+f(i-2,a,dp);
    int notPick=0+f(i-1,a,dp);
    return dp[i]=max (pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}

// Time complexity-->O(n) and 
// space complexity-->O(n)for axuliry space + O(n) for dp array =O(2n) or O(n)


// Tabulation

int maximumNonAdjacentSum(vector<int> &nums){
    
        int n=nums.size();
        vector<int>dp(n,-1);
       dp[0]=nums[0];
      
       for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int nonPick=dp[i-1];
         dp[i]=max(pick,nonPick);
    }
        return dp[n-1];
    
}

// Time complexity-->O(n) and 
// space complexity-->O(n) (dp array)


// Space Optimization

int maximumNonAdjacentSum(vector<int> &nums){
    
        int n=nums.size();
       
       int prev=nums[0];
     int prev2=0;
       for(int i=1;i<n;i++){
        int pick=nums[i]+prev2;
      
        int nonPick=prev;
       int  cur_i=max(pick,nonPick);
           prev2=prev;
           prev=cur_i;
    }
        return prev;
    
}

// Time complexity-->O(n) and 
// space complexity-->O(1) 