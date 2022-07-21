#include<bits/stdc++.h>

bool ispalin(int i,int j,string s)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int help(int i,int n,string str,vector<int>&dp)
{
    if(i==n)
        return 0;
    
    int mincost=INT_MAX;
    if(dp[i]!=-1)
        return dp[i];
    for(int j=i;j<n;j++)
    {
        if(ispalin(i,j,str))
        {
            int cost=1+help(j+1,n,str,dp);
            mincost=min(mincost,cost);
        }
    }
    return dp[i]=mincost;
}

int palindromePartitioning(string str) {
    // Write your code here
    /*vector<int>dp(str.size(),-1);
    return help(0,str.size(),str,dp)-1; //-1 is added as it is considering the last partition.
    */
    int n=str.size();
    vector<int>dp(n+1,0);
    dp[n]=0;//as in recursion it is going from 0->n in tabulization it should go from n->0;
    for(int i=n-1;i>=0;i--)
    {
         int mincost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(ispalin(i,j,str))
            {
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
        }
    dp[i]=mincost;
    }
    return dp[0]-1;
    
}
