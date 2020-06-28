class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& m, string x, vector<string>& ans) {
        for(auto& i: m[x]) {
            if(i != "") {
                string arr = i;
                i = "";
                dfs(m, arr, ans);
            }
        }
        ans.push_back(x);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> m;
        for(auto i: tickets) {
            m[i[0]].push_back(i[1]);
        }
        for(auto i: m) {
            sort(m[i.first].begin(), m[i.first].end());
        }
        vector<string> ans;
        dfs(m, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};