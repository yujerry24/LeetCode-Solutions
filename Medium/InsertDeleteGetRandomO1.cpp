class RandomizedSet {
public:
    
    unordered_map <int, int> set;
    vector<int> list;
    /** Initialize your data structure here. */
    RandomizedSet() {
        set.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(set.find(val)!=set.end()) {
            return false;
        }
        else {
            set[val]=val;
            return true;
        }
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(set.find(val)==set.end()) {
            return false;
        }
        else {
            set.erase(set.find(val));
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(set.size()==0) {
            return 0;
        }
        int random = rand() % (int) (set.size());
        for(const auto & i: set) {
            if(random==0) {
                return i.first;
            }
            random=random-1;
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */