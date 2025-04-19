class Solution {
public:

    int l_bound(vector<int> &nums, int num)
    {
        int l = 0;
        int h = nums.size() - 1;
        int ans = -1;
        while(h >= l)
        {
            int mid = (l + h)/2;
            int k = nums[mid];

            if(k >= num)
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }

    int u_bound(vector<int> &nums, int num)
    {
        int ans = -1;
        int n = nums.size();
        int l=0,h=n-1;

        while(h >= l)
        {
            int mid = (l+h)/2;
            int k = nums[mid];

            if(k <= num)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            int lb = lower - num;
            int ub = upper - num;

            int i1 = l_bound(nums, lb);
            int i2 = u_bound(nums, ub);

            if(i1 != -1 && i2 != -1 && i2 >= i1 && i2 > i)
            {
                if(i >= i1) i1 = i + 1;
                ans += i2 - i1 + 1;
                cout << ans << " ";
            }
        }
        return ans;
    }
};