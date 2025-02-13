class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++) {
                mp[s[j]]++;

                // Find max and min frequency in the current substring
                int maxi = 0, mini = INT_MAX;
                for(auto& [ch, freq] : mp) {
                    maxi = max(maxi, freq);
                    mini = min(mini, freq);
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
