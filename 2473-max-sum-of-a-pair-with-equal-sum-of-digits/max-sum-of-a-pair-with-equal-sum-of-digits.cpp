class Solution {
public:

    int countDigit(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            mp[countDigit(nums[i])].push_back(nums[i]);
        }

        int ans = -1;
        for(auto it : mp)
        {
            if(it.second.size() >= 2)
            {
                int max1 = 0, max2 = 0;
                for(int i : it.second)
                {
                    cout << i << " ";
                    if(i >= max1 && i >= max2)
                    {
                        max2 = max1;
                        max1 = i;
                    }
                    else if(i >= max2)
                    {
                        max2 = i;
                    }
                }
                cout << endl;
                ans = max(max1+max2, ans);
            }
        }
        return ans;
    }
};