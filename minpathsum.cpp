/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/


int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n];//dp state: dp[i][j] represents min path sum req to get there from 0,0
        /*
        dp expr:
        dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1])
        base cond;
        firstrow,first col=summation till there
        for space optimization use grid as dp matrix
        */
        // dp[0][0]=grid[0][0];
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                    continue;
                if(i==0 )
                {
                    //dp[0][j]=dp[0][j-1]+grid[0][j];
                    grid[0][j]=grid[0][j-1]+grid[0][j]; 

                }
                else if(j==0 )
                {
                    //dp[i][0]=grid[i][0]+dp[i-1][0];
                    grid[i][0]=grid[i][0]+grid[i-1][0];
                }
                else
                    
                //dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                    grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }