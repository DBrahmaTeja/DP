/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
*/
bool isMatch(string s, string p) {
       
        vector<vector<bool>>dp(p.length()+1,vector<bool>(s.length()+1));
        
        for(int i=1;i<(s.length()+1);i++)   //filling the column edge case
        {
            dp[0][i]=false;
        }
        dp[0][0]=true;
        for(int i=1;i<(p.length()+1);i++)  //filling row edge case and col 0 is fixed
        {
            if(p[i-1]=='*')                //it would be star
            {
                dp[i][0]=dp[i-2][0];
            }
            else                          //it could be dot or char
            {
                dp[i][0]=false;
            }
        }
        dp[0][0]=true;
        
        for(int i=1;i<(p.length()+1);i++)
        {
            for(int j=1;j<(s.length()+1);j++)
            {
                if(p[i-1]=='*')            //star encounterd
                {
                    //ith char is star
                    if(p[i-2]==s[j-1] or p[i-2]=='.')     //if the preceding char of the star is same as the jth char of str
                    {
                        dp[i][j]=dp[i-2][j] or dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j]=dp[i-2][j];
                    }
                }
                else if(p[i-1]=='.')       //dot encounterd
                {
                    dp[i][j]=dp[i-1][j-1];    
                }
                else if(p[i-1]==s[j-1])    //both are same char
                { 
                    dp[i][j]=dp[i-1][j-1];
                }
                else                      //bot are char but not same
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[p.length()][s.length()];
    }