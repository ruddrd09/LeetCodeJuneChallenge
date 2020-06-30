class Solution {
public:
    vector<string> ans;
    int r[4] = {-1, 0, 0, 1};
    int c[4] = {0, -1, 1, 0};
    
    class Trie {
        public:
        Trie* child[26];
        string word;
        
        Trie() {
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            word = "";
        }
    };
    
    Trie* build(vector<string>& words) {
        Trie* root = new Trie();
        for(string word: words) {
            Trie* temp = root;
            for(char c: word) {
                if(!temp->child[c - 'a']) {
                    Trie* newNode = new Trie();
                    temp->child[c - 'a'] = newNode;
                }
                temp = temp->child[c - 'a'];
            }
            temp->word = word;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, Trie* root, int i, int j) {
        char temp = board[i][j];
        if(board[i][j] == '/' || !(root->child[temp - 'a'])) {
            return;
        }
        root = root->child[temp - 'a'];
        if(root->word != "") {
            ans.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '/';
        for(int k = 0; k < 4; k++) {
            int y = i + r[k];
            int z = j + c[k];
            if(y >= 0 && z >= 0 && y < board.size() && z < board[0].size()) {
                dfs(board, root, y, z);
            }
        }
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        Trie* root = build(words);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, root, i, j);
            }
        }
        return ans;
    }
};