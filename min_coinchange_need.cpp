/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2
Input: coins = [2], amount = 3
Output: -1
*/

//C++ Code
class Solution{
public:
    int coinChange(vector<int>&coins,int amount){
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;++i)
        {
            for(intj=0;j<=amount;++j)
            {
                if(j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=1e5;
                else if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
       }
        return dp[n][amount]>1e4?-1:dp[n][amount];
    }
}
//----------------------OR------------------//
int coinChange(vector<int> &coins, int amount)
{
    // dp state: min no.of coins needed to get amount i from coins[0-i]
    long long n = coins.size();
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; ++i)
    {
        for (int c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }
    if (dp[amount] == amount + 1)
    {
        return -1;
    }

    return dp[amount];
}

/*----------------------------OR--------------------------------*/
// Memoiation
int f(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    // Base Cases
    if (idx == 0)
    {
        if (amount % coins[idx] != 0)
            return 1e9;
        else
            return amount / coins[idx];
    }
    if (dp[idx][amount] != -1)
        return dp[idx][amount];
    int not_take = f(idx - 1, amount, coins, dp);
    int take = INT_MAX;
    if (coins[idx] <= amount)
        take = 1 + f(idx, amount - coins[idx], coins, dp);
    dp[idx][amount] = min(take, not_take);
    return dp[idx][amount];
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = f(n - 1, amount, coins, dp);
    if (res == 1e9)
        return -1;
    else
        return res;
}

// Tabulation Method
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int tar = 0; tar <= amount; tar++)
    {
        if (tar % coins[0] != 0)
            dp[0][tar] = 1e9;
        else if (tar % coins[0] == 0)
            dp[0][tar] = tar / coins[0];
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int not_take = dp[idx - 1][tar];
            int take = 1e9;
            if (coins[idx] <= tar)
                take = 1 + dp[idx][tar - coins[idx]];
            dp[idx][tar] = min(take, not_take);
        }
    }
    int ans = dp[n - 1][amount];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// Space Optimization
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int tar = 0; tar <= amount; tar++)
    {
        if (tar % coins[0] != 0)
            prev[tar] = 1e9;
        else if (tar % coins[0] == 0)
            prev[tar] = tar / coins[0];
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int not_take = prev[tar]; // dp[idx-1][tar];
            int take = 1e9;
            if (coins[idx] <= tar)
                take = 1 + curr[tar - coins[idx]]; // dp[idx][tar-coins[idx]] ;
            // dp[idx][tar] = min(take,not_take);
            curr[tar] = min(take, not_take);
        }
        prev = curr;
    }
    int ans = prev[amount]; // dp[n-1][amount];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}
