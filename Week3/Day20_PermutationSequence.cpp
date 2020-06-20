class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n);
        fact[0] = 1;
        for(int i=1;i<n;i++) {
            fact[i] = i*fact[i-1];
        }
        vector<string> x(n);
        for(int i=0;i<n;i++) {
            x[i] = to_string(i+1);
        }
        k--;
        string ans;
        for(int i=n-1;i>=0;i--) {
            int d = k / fact[i];
            ans += x[d];
            k %= fact[i];
            x.erase(x.begin() + d);
        }
        return ans;
    }
};