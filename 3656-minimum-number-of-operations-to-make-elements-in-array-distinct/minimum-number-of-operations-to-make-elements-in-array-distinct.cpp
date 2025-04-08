class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int > mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        int n = nums.size();
        if(mp.size() == n) return 0;
        int i=0;
        int ans = 0;
        while(mp.size() < n && n >= 3)
        {
            cout << mp.size() << " " << n << endl;
            n -= 3;
            for(int k=0; k<3; k++)
            {
                mp[nums[i+k]]--;
                if(mp[nums[i+k]] == 0) mp.erase(nums[i+k]);
            }
            i += 3;
            ans++;
        }
        cout << mp.size() << " " << n << endl;

        if(mp.size() == n) return ans;
        return ans+1;
    }
};