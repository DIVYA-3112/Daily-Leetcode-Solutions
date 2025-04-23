class Solution {
public:
    int count(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += (n%10);
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=1; i<=n; i++)
        {
            int k = count(i);
            mp[k]++;
            maxi = max(maxi, mp[k]);
        }
        int ans = 0;
        for(auto it : mp)
        {
            // cout << it.first << " - " << it.second << endl;
            if(it.second == maxi) ans++;
        }
        return ans;
    }
};