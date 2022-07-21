#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//optimised using memorization
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(j<weights[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
        }
    }
    return dp[n][w];
}

int maxprofit(int n,vector<int>wt,vector<int>profit,int w,vector<vector<int>>&mem)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(mem[n][w]!=-1) 
    return mem[n][w];
    int result;
    if(wt[n]>w)
        result= maxprofit(n-1,wt,profit,w,mem);
    else
        result= max(maxprofit(n-1,wt,profit,w,mem),profit[n]+maxprofit(n-1,wt,profit,w-wt[n],mem));
    return mem[n][w]=result;

}

int main()
{
    vector<int>wt;
    vector<int>profit;
    wt.push_back(3);
    wt.push_back(4);
    wt.push_back(1);
    profit.push_back(5);
    profit.push_back(6);
    profit.push_back(2);
    int w=6;
    vector<vector<int>>mem(wt.size()+1,vector<int>(w+1,-1));
    int max_profit=maxprofit(wt.size(),wt,profit,w,mem);
    cout<<"Max Profit that can be earned is : "<<mem[wt.size()][w]<<endl;
}