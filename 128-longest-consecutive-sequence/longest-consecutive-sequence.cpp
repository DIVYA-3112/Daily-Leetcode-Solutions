class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums)
        {
            mp[num] = 1;
        }
        int ans = 0;
        for(int num : nums)
        {
            if(mp.find(num) == mp.end()) continue;
            int cnt = 1;
            int k = num;
            mp.erase(k);
            while(mp.find(k+1) != mp.end())
            {
                mp.erase(k+1);
                cnt++;
                k++;
            }
            k = k - cnt + 1;
            while(mp.find(k-1) != mp.end())
            {
                mp.erase(k-1);
                cnt++;
                k--;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};