class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for(int i : derived)
        {
            x ^= i;
        }
        if(x) return false;
        return true;
    }
};