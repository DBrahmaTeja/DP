int maxSubarraySum(vector<int>arr)
{
    int n=arr.size();
    int dp[n],ans=arr[0]; //dpstate: dp[i] states that max subarray sum ending at i
    //dp expr: dp[i]=max(dp[i-1]+arr[i],arr[i]) as it is ending at i arr[i] must be included
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
        ans=max(ans,dp[i]);
    }
    return dp[n-1];
    //optimisation of space complexity at any time only two states are considered so
    //****
    int prev=arr[0];
    for(int i=1;i<n;i++)
    {
        int cur =max(arr[i],prev+arr[i]);
        prev=cur;
        ans=max(ans,cur);
    }
    return cur;
}