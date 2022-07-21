/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order i.e. increasing subsequence. 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/

int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n],ans=arr[0];//dp state- max sum subsequence ending at i
	    dp[0]=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        int val=0;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                val=max(val,dp[j]);
	            }
	        }
	        dp[i]=arr[i]+val;
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}  