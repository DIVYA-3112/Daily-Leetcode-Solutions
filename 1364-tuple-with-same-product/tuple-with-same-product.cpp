class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int mul = nums[i] * nums[j];
                mp[mul]++;
            }
        }

        int ans = 0;
        for(auto it : mp)
        {
            int k = it.second;
            if(k >= 2)
            {
                ans += ((k) * (k-1)) / 2;
            }
        }
        return ans*8;
    }
};