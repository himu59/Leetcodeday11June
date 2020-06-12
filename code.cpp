class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> um;
    vector<int> v;
    RandomizedSet() {
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    
    bool insert(int val) {
        if(um.find(val) != um.end()) return 0;
        v.push_back(val);
        um.insert({val,v.size()-1});
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end()) return 0;
         int x = um[val];
        v[x] = v[v.size()-1];
         um[v[x]] = x;
        v.pop_back();
        um.erase(val);
        return 1;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
