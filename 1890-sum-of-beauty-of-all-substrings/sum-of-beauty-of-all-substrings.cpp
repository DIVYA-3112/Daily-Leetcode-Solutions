class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            char maxi = s[i], mini = s[i];
            mp[s[i]]++;

            for (int j = i + 1; j < n; j++) {
                mp[s[j]]++;

                // Update `maxi` correctly
                if (mp[s[j]] >= mp[maxi]) {
                    maxi = s[j];
                }

                // Instead of relying on direct comparison, recalculate `mini`
                if (mp[s[j]] <= mp[mini]) {
                    mini = s[j];
                }

                // Ensure `mini` holds the correct least frequency character
                for (auto& [ch, freq] : mp) {
                    if (freq < mp[mini]) {
                        mini = ch;
                    }
                }

                ans += (mp[maxi] - mp[mini]);
            }
        }
        return ans;
    }
};
