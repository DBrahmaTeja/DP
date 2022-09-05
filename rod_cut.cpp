#include<bits/stdc++.h>
int helper(vector<int> &price,int n,int i){
    if(i<0){
        return 0;
    }
   //if(dp[i][n]!=-1) return dp[i][n];
    int nottaken = 0 + helper(price,n,i-1);
    
    int taken = INT_MIN;
    int rodlength = i+1;
    if(rodlength<=n){
        taken = price[i] + helper(price,n-rodlength,i);
    }
    return max(taken,nottaken);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(price.size()+1,vector<int>(n+1,0));
    //int ans = helper(price,n,price.size()-1);
    for(int i=1;i<=price.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
             dp[i][j]=dp[i-1][j];
            
             if(i<=j){
                 dp[i][j]=max(dp[i][j],price[i-1]+dp[i][j-i]);
             } 
        }
    }
    
    return dp[price.size()][n];
}