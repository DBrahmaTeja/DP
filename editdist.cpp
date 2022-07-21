int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        //dp state: dp[i,j] states that how many edits have to do to equal word1[0,i] word2[0,j]
        /*
        dp expr:
            if word1[i]==word2[j]
            dp[i][j]=d[i-1][j-1];//no change to be needed.
            else
            {
                min(
                1+dp[i-1][j-1],//to replace either word1[i] or word2[j]
                1+dp[i][j-1],//to delete at word2[j] or to insert at word1[i]
                1+dp[i-1][j]//to delete at word1[i] or to insert at word2[j]
                )
            }
        base cond:
        if(i<0 and j<0)
        return 0;
        if(i<0)
        return j+1
        if(j<0)
        return i+1;
        
        */
            
        int dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++)
            dp[i][0]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }