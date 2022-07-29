int fill(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] == -1)
    {
        if (s1[i] == s2[j])
        {
            dp[i][j] = 1 + fill(s1, s2, i - 1, j - 1, dp);
        }
        else
            dp[i][j] = max(fill(s1, s2, i - 1, j, dp), fill(s1, s2, i, j - 1, dp));
    }
    return dp[i][j];
}
int longestCommonSubsequence(string text1, string text2)
{
    /*int n1=text1.size(),n2=text2.size();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    return  fill(text1,text2,n1-1,n2-1,dp);*/
    // Iterative method

    int m = text1.size();
    int n = text2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}

// To print the LCS
int i = m, j = n;
vector<char> ans;
while (i > 0 and j > 0)
{
    if (s1[i - 1] == s2[j - 1])
    {
        ans.push_back(s1[i - 1]);
        i--;
        j--;
    }
    else
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
}
reverse(ans.begin(), ans.end());
return ans;
