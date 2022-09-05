/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
*/
bool is_valid(int ind, int end, string s)
{

    if (end - ind + 1 > 2)
        return false;
    if (s[ind] == '0')
        return false;
    int num = 0;
    for (int i = ind; i <= end; i++)
    {
        num = num * 10 + s[i] - '0';
    }
    if (1 <= num and num <= 26)
        return true;
    return false;
}
int decodes(int ind, int n, string s, vector<int> &dp)
{
    if (ind == n)
        return 1;
    int cut = 0;
    if (dp[ind] != -1)
        return dp[ind];
    for (int j = ind; j < n; j++)
    {

        if (is_valid(ind, j, s))
        {
            cut += decodes(j + 1, n, s, dp);
        }
    }
    return dp[ind] = cut;
}
int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    //   return decodes(0,s.size(),s,dp);
    dp[n] = 1;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int cut = 0;
        for (int j = ind; j < n; j++)
        {

            if (is_valid(ind, j, s))
            {
                cut += dp[j + 1];
            }
        }
        dp[ind] = cut;
    }
    return dp[0];
}