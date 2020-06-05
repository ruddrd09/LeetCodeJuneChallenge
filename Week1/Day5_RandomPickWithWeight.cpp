class Solution {
public:
    vector<int> v;
    int sum = 0;
    Solution(vector<int>& w) {
        for(auto i: w) {
            sum += i;
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        int r = rand() % sum;
        auto it = upper_bound(v.begin(), v.end(), r);
        return it - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */