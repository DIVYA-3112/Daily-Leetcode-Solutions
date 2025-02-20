class Solution {
public:

    int fun(string s, int n)
    {
        int ans = 0;
        int k = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans += (k * (int)(s[i] - '0'));
            k = (k << 1);
        }
        return ans;
    }

    string fun2(int i, int n)
    {
        string s = "";
        while(i || s.size() < n)
        {
            s += (char)((i % 2) + '0');
            i /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            int k = fun(nums[i], n);
            mp[k] = 1;
        }

        for(int i=0; i<n+1; i++)
        {
            if(mp.find(i) == mp.end())
            {
                return fun2(i,n);
            }
        }
        return "0";
    }
};