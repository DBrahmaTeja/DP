/*
300. Longest Increasing Subsequence
Medium

12317

238

Add to List

Share
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
*/
 int lengthOfLIS(vector<int>& nums) {
        /*int n=A.size(),ans=1;
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int val=0;
            for(int j=0;j<i;j++)
            {
                if(A[j]<A[i])
                {
                    val=max(val,dp[j]);
                }
            }
            dp[i]=val+1;
            ans=max(ans,dp[i]);
        }
        return ans;
        TC: O(n^2);
        SC: O(n);
        */
        //Using LowerBound Method if it is less than all prev ele it is  push_backed otherwise it will be swapped with its lower bound element
        // at last return the size of V.
        int n = nums.size();
        vector<int> v;
        int max_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i == 0)
                v.push_back(nums[i]);
            else{
                auto x = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                if(x >= v.size())
                    v.push_back(nums[i]);
                else
                v[x] = nums[i];
            }    
        }
        return v.size();
        /*
        TC: O(nlogn);
        SC: O(n);*/
        
    }