class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m ? 1 : 0;
    }
};

DP Bottom Up ->

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                if(i == 0) {
                    dp[i][j] = 1;
                } else if(j == 0) {
                    dp[i][j] = 0;
                } else {
                    if(s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};