#include<bits/stdc++.h>
bool help(int ind,int sum,int target,vector<int>arr)
{
    if(sum==target)
        return true;
     if(ind==arr.size())
         return false;
    bool nottake=help(ind+1,sum,target,arr);
    bool take=help(ind+1,sum+arr[ind],target,arr);
    return nottake or take;
}
/*
f(ind,target){
    if(target ==0)return true
     if(ind ==0)return arr[ind]== target
     bool notTaken=f(ind-1,target)
     bool taken=false
     if(arr[ind]<=target)
         taken=f(ind-1,target-arr[ind]
     return notTaken || taken
    }*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    //return help(0,0,k,arr);
    //optimised using tabulization
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;//target is zero
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;//setting the value true for the target ==ar[0]
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];//recurrence relation will be same if we do in top-down approach means first finding the sub problem and then fill the rest.
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}

//Memorization
class Solution{
   vector<vector<int >> mem;
   bool subsetSum(vector<int>&nums,int n,int pos,int sum)
   {
       if(sum ==0)// Sum found
            return true;
       else if(pos>=n|| sum<0)// Out of bounds
            return false;
       if(mem[pos][sum]!=-1)
            return mem[pos][sum];
        return mem[pos][sum]=subsetSum(nums,n,pos+1,sum-nums[pos])|| subsetSum(nums,n,pos+1,sum);
   }
public:
   bool canPartition(vector<int>&nums){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
            sum+=nums[i];
       if(sum&1)// ODD sum
            return false;
       mem.clear();
       mem.resize(n+1,vector<int>(sum/2+1,-1));
        return subsetSum(nums,n,0,sum/2);
   }
}

//Tabulation
class Solution{
public:
    bool canPartition(vector<int>&nums){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
            sum+=nums[i];
        if(sum&1)// ODD sum
            return false;
        bool dp[n+1][sum/2+1];
        // Fill DP table(Subset Sum Problem code)
        for(int i=0;i<=n;++i)
        for(int j=0;j<=sum/2;++j)
       {
            if(i==0||j==0)// Base Case
                dp[i][j]=false;
            else if(nums[i-1]>j)// SKIP case
                dp[i][j]=dp[i-1][j];
            else if(nums[i-1]==j)
                dp[i][j]=true;
            else
                dp[i][j]=dp[i-1][j]|| dp[i-1][j-nums[i-1]];
        }
        return dp[n][sum/2];
   }
}