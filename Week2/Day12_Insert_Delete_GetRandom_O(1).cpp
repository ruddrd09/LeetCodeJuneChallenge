class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) == s.end()) {
            s.insert(val);
            return 1;
        } else {
            return 0;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end()) {
            s.erase(val);
            return 1;
        } else {
            return 0;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % s.size();
        auto it = s.begin();
        for(int i=0;i<index;i++) {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */