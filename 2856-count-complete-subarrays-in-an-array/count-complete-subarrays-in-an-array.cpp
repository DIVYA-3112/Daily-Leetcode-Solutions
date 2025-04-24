class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        int k = mp.size();

        int i=0,j=0;
        unordered_map<int,int> mp1;
        int ans = 0;
        while(j<n)
        {
            mp1[nums[j]]++;
            while(mp1.size() == k)
            {
                // cout << n-j << endl;
                ans += (n-j);
                mp1[nums[i]]--;
                if(mp1[nums[i]] == 0) mp1.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};