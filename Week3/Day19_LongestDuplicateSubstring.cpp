class Solution {
public:
    string longestDupSubstring(string S)
    {
        string longest;
        unordered_set<string> set;
        int l = 0;
        int r = S.size() - 1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            bool found = false;
            for (int i = 0; i < S.size()-mid+1; i++) {
                auto [it, inserted] = set.emplace(S.data() + i, mid);
                if (!inserted) {
                    found = true;
                    longest = move(*it);
                    break;   
                }
            }
            if (found) {
                l = mid + 1;   
            } else {
                r = mid - 1;   
            }
            set.clear();      
        }    
        return longest;
    }
};