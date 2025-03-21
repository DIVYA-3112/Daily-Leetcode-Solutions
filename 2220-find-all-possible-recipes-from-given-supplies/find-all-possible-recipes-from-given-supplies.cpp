#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int fun(const string& s, const vector<string>& rec, const vector<vector<string>>& ing, const unordered_map<string, int>& mpr, unordered_set<string>& cooked, unordered_set<string>& processing) {
        if (cooked.find(s) != cooked.end()) {
            return 1;
        }
        if (mpr.find(s) == mpr.end()) {
            return 0;
        }
        if(processing.find(s) != processing.end()){
            return 0;
        }

        processing.insert(s);
        int ind = mpr.at(s);
        for (const string& it : ing[ind]) {
            if (cooked.find(it) == cooked.end()) {
                if (mpr.find(it) == mpr.end()) {
                    processing.erase(s);
                    return 0;
                } else if (!fun(it, rec, ing, mpr, cooked, processing)) {
                    processing.erase(s);
                    return 0;
                }
            }
        }
        processing.erase(s);
        cooked.insert(s);
        return 1;
    }

    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supplies) {
        unordered_set<string> cooked(supplies.begin(), supplies.end());
        vector<string> ans;
        unordered_map<string, int> mpr;
        for (int i = 0; i < rec.size(); ++i) {
            mpr[rec[i]] = i;
        }
        unordered_set<string> processing;

        for (const string& recipe : rec) {
            if (fun(recipe, rec, ing, mpr, cooked, processing)) {
                ans.push_back(recipe);
            }
        }
        return ans;
    }
};