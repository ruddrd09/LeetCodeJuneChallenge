class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return vector<int>();
        }
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++) {  // Same as LIS
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j; // Stroring the previous divisble element as the parent
                }
            }
        }
        int maxIndex = 0, maxLen = 0;
        for(int i=0;i<n;i++) { // Finding the index of the maximum length subsequence as in LIS
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        vector<int> ans(maxLen);
        int x = maxLen-1;
        while(maxIndex != -1) { // Forming the ans vector from index
            ans[x] = nums[maxIndex];
            maxIndex = parent[maxIndex];
            x--;
        }
        return ans;
    }
};