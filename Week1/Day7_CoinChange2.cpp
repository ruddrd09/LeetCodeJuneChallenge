class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int n = amount;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                } else if(i == 0) {
                    dp[i][j] = 0;
                } else {
                    if(j >= coins[i-1]) {
                        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

Space Optimized Solution ->

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=0;i<coins.size();i++) {
            for(int j=1;j<=amount;j++) {
                if(j>=coins[i]) {
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};