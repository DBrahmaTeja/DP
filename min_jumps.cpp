/*
Approach:

In this way, make a jumps[] array from left to right such that jumps[i] indicate the minimum number of jumps needed to reach arr[i] from arr[0].
To fill the jumps array run a nested loop inner loop counter is j and outer loop count is i.
Outer loop from 1 to n-1 and inner loop from 0 to i.
if i is less than j + arr[j] then set jumps[i] to minimum of jumps[i] and jumps[j] + 1. initially set jump[i] to INT MAX
Finally, return jumps[n-1].
*/
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int reachable = 0;

    for (int i = 0; i < n; ++i)
    {
        if (reachable < i)
            return false;
        reachable = max(reachable, i + nums[i]);
    }
    return true;
}
int minJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int *jumps = new int[n];
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}