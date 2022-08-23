/*
You have been given string 'S' of length 'N' that may contain duplicate alphabets. Your task is to return the count of distinct subsequences of it.
For example:
For the given string “deed” :
The possible subsequences are {“”}, {“d”}, {“e”}, {“de”}, {“e”}, {“de”}, {“ee”}, {“dee”}, {“d”}, {“dd”}, {“ed”}, {“ded”}, {“ed”}, {“ded”}, {“eed”} and {“deed”}.
As, {“d”}, {“e”}, {“de”}, {“ed”} and {“ded”} are repeated.
The distinct subsequences are {“”}, {“d”}, {“e”}, {“de”}, {“ee”}, {“dee”}, {“dd”}, {“ed”}, {“ded”}, {“eed”} and {“deed”}
Thus, the output will be 11.
*/

// Brute Force
/*
#include<bits/stdc++.h>
void help(string s,string &substr,int i,int n,unordered_set<string>&hs)
{
    if(i==n)
    {
        hs.insert(substr);
        return;
    }

    //considering
     substr+=s[i];
    help(s,substr,i+1,n,hs);
     substr.pop_back();
    //not considering
    help(s,substr,i+1,n,hs);
}

int distinctSubsequences(string S)
{

    string substring="";
    int n=S.size(),c=0;
    unordered_set<string>hs;
    help(S,substring,0,n,hs);
    return hs.size();

}
TC: O(2^N)  SC: O(2^N);
*/

/*
Dynamic programming
The idea is to use dynamic programming.
Take a ‘DP’ list which at every index stores the number of subsequences created by the given string which ends at that particular index.
 Mathematically, DP[id] will store the number of subsequences created by string ‘STR’ if the length of the string is id.
We maintain a ‘MAP’ which stores the index of the latest occurrence of any particular alphabet in the string.
Now, to calculate DP[id] the steps follow:

If the character at index id has not appeared before then there will be no possibility for repetition in subsequence.
 Hence, DP[id] = 2 * DP[id - 1].
Otherwise, we need to subtract the repetitions and
as the last occurrence of the current character in the string is at the MAP[STR[id-1]].
So the count of subsequences till this index is repeated so we will subtract the count.
Hence, DP[id] = 2 * DP[id - 1] - DP[ MAP[STR[id-1]].
Update the latest index of the current index in the MAP.
Return DP[N] where N is the size of the string.

For example, let’s take the string ”abbcb”

Size of the given string is 5. Initialise a MAP to store the latest index of each character.
Along with this also initialise a DP array DP[6]
The base case, DP[0] = 1 This stores the number of subsequences that can be created
if string size is 0 which is 1, i.e a null string.
From index 1 to the length of the string:
Iteration 1: STR[1-1], i.e ‘a’ occurs for the first time, DP[1] = 2 * DP[0]. Thus, DP[1] = 2. Also, MAP[a] = 0.
Iteration 2: STR[2-1], i.e ‘b’ occurs for the first time, DP[2] = 2 * DP[1]. Thus, DP[2] = 4. Also, MAP[b] = 1.
Iteration 3: STR[3-1], i.e ‘b’ is repeated, DP[3] = 2 * DP[2] - DP[ MAP[ b ]]. Thus, DP[3] = 2 * 4 - 2, DP[3] = 6.
Also, MAP[b] = 2.
Iteration 4: STR[4-1], i.e ‘c’ occurs for the first time, DP[4] = 2 * DP[3]. Thus, DP[4] = 12. Also, MAP[c] = 3.
Iteration 5: STR[5-1], i.e ‘b’ is repeated, DP[5] = 2 * DP[4] - DP[ MAP[ b ]]. Thus, DP[5] = 2 * 12 - 4, DP[5] = 20.
Also, MAP[b] = 4.
The final count is stored in DP[5] i.e 20. The DP list is [1, 2, 4, 6, 12, 20].
Time Complexity
O(N), where ‘N’ is the size of the string.

In the worst case, we are traversing the whole string to maintain the DP list and store the index in the map.
Therefore, overall time complexity will be O(N).

Space Complexity
O(N), where ‘N’ is the size of the string.

In the worst case, we are using an extra list of size N+1 as well as an extra map.
So, overall space complexity will be O(N).
*/
/*
    Time complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the size of given string.
*/

#include <string>
#include <unordered_map>

int distinctSubsequences(string S)
{
    int mod = 1000000007;
    unordered_map<char, int> map;
    int n = S.length();
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // If the character has occured for first time.
        if (map.find(S[i - 1]) == map.end())
        {
            dp[i] = (2 * dp[i - 1]) % mod;
        }
        // If the character is repeated.
        else
        {
            dp[i] = (((2 * dp[i - 1]) % mod) - dp[map[S[i - 1]]] + mod) % mod;
        }
        // Updating map with last occurrence of current character.
        map[S[i - 1]] = (i - 1);
    }
    return dp[n];
}
