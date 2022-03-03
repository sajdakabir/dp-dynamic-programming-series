// memoization
#include <bits/stdc++.h>
int f(int n, vector<int> &heights, vector<int> &dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int jump1=f(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int jump2=INT_MAX;
    if(n>1){
   jump2=f(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]= min(jump1,jump2);
}
int frogJump(int n, vector<int> &heights)
{
vector<int>dp(n,-1);
    return f(n-1,heights,dp);
}

// Time complexity-->O(n) and 
// space complexity-->O(n)for axuliry space + O(n) for dp array =O(2n) or O(n)



// Tabulation

#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
 vector<int> dp(n,-1);
   dp[0]=0;
   for(int i=1;i<n;i++){
 int jump2= INT_MAX;
    int jump1= dp[i-1] +abs(heights[i]-heights[i-1]);
        if(i>1)
   jump2=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]= min(jump1,jump2);
    
            }

     return dp[n-1];
}


// Time complexity-->O(n) and 
// space complexity-->O(n) (dp array)


// Space Optimization
#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
  int prev=0;
  int  prev2=0;
  for(int i=1;i<n;i++){
  int jump2= INT_MAX;
   int jump1= prev +abs(heights[i]-heights[i-1]);
        if(i>1)
           jump2=prev2+abs(heights[i]-heights[i-2]);
      int  curr_i= min(jump1,jump2);
       
    prev2=prev;
       prev=curr_i;
            }

     return prev;
}

// Time complexity-->O(n) and 
// space complexity-->O(1) 