#include<bits/stdc++.h>

int change(int amount,vector<int>&coins){
    
    int n=coins.size();
    vector<vector<int >> dp(n+1,vector<int>(amount+1));
    // Fill 1st row withebecause no amount(except0)can be formed without any coin
    int i,j;
    for(i=1;i<=amount;++i)
        dp[0][i]=0;
    // Fill 1st col by1(assuming amount9can always be formed)
    for(i=0;i<=n;++i)
        dp[i][0]=1;
    // Fill DP-Table
    for(i=1;i<=n;++i)
   {
        for(j=1;j<=amount;++j)
        {
            if(j>=coins[i-1])
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
           
        }
   }
   return dp[n][amount];
}

long findways(int * arr,int ind,int T,vector<vector<long>>&dp)
{
    if(ind==0)
    {
        return (T%arr[0]==0);
    }
    if(dp[ind][T]==-1)
    {
    //not take
    long nottake=findways(arr,ind-1,T,dp);
    long take=0;
    if(arr[ind]<=T)
        take=findways(arr,ind,T-arr[ind],dp);
       return dp[ind][T]=nottake+take;
    }
    return dp[ind][T];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    /*vector<vector<long>>dp(n,vector<long>(value+1,-1));
//     return findways(denominations,n-1,value,dp);
    for(int t=0;t<=value;t++)
    {
        dp[0][t]=(t%denominations[0]==0);
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int T=0;T<=value;T++)
        {
             long nottake=dp[ind-1][T];
            long take=0;
            if(denominations[ind]<=T)
                take=dp[ind][T-denominations[ind]];
           dp[ind][T]=nottake+take;
        }
    }
    return dp[n-1][value];*/
    //More optimised use 2 row array as dp
   vector<long>prev(value+1);
    vector<long>cur(value+1);
    for(int t=0;t<=value;t++)
    {
        prev[t]=(t%denominations[0]==0);
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int T=0;T<=value;T++)
        {
             long nottake=prev[T];
            long take=0;
            if(denominations[ind]<=T)
                take=cur[T-denominations[ind]];
          cur[T]=nottake+take;
        }
        prev=cur;
    }
    return prev[value];
}