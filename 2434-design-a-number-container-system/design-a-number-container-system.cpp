class NumberContainers {
public:
    unordered_map<int,set<int>> mp;
    unordered_map<int,int> mp2;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(mp2.find(index) != mp2.end())
        {
            mp[mp2[index]].erase(index);
            if(mp[mp2[index]].size() == 0) mp.erase(mp2[index]);
        }
        mp2[index] = number;
        mp[number].insert(index);
        return;
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end()) return -1;
        else return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */