class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        for(auto it : mp)
        {
            int a = it.first;
            int b = it.second;

            if(b <= a + 1)
            {
                ans += 1 + a;
            }
            else
            {
                int k = b % (a+1);
                if(k != 0)
                {
                    ans += (1 + (b/(a+1))) * (a+1);
                }
                else
                {
                    ans += b;
                }
            }
        }
        return ans;
    }
};