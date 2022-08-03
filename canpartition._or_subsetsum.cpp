/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that
the sum of elements in both subsets is equal.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/

bool help(int ind, int sum, int target, vector<int> arr)
{
    if (target == sum)
        return true;
    if (target < sum or ind == arr.size())
        return false;

    // not taking the element
    bool nottake = help(ind + 1, sum, target, arr);
    // taking the element
    bool take = help(ind + 1, sum + arr[ind], target, arr);
    return nottake or take;
}

bool canPartition(vector<int> &nums)
{
    int tot_sum = 0, n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        tot_sum += nums[i];
    }

    if (tot_sum % 2 != 0)
        return false;
    int k = tot_sum / 2;
    // return help(0,0,target,nums);
    // Tabullisation
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true; // target is zero
    }

    if (nums[0] <= k)
        dp[0][nums[0]] = true; // setting the value true for the target ==ar[0]

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (nums[ind] <= target)
                taken = dp[ind - 1][target - nums[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}
// Tabullization
vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= k; j++)
    {
        if (j == 0)
            dp[i][j] = true;
        else if (i == 0)
            dp[i][j] = false;

        else if (j < nums[i - 1])
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    }
}

return dp[n][k];
// space optimization

vector<bool> prev(k + 1, false), cur(k + 1, false);

prev[0] = true;
for (int i = 1; i <= n; i++)
{
    for (int j = 0; j <= k; j++)
    {
        if (j == 0)
            cur[j] = true;
        else if (j < nums[i - 1])
            cur[j] = prev[j];
        else
            cur[j] = prev[j] || prev[j - nums[i - 1]];
    }
    prev = cur;
}

return cur[k];