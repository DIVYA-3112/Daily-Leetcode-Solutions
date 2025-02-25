#define mod 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n,0);
        v[0] = arr[0] % 2;
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            arr[i] = (arr[i] % 2);

            if(i != 0)
            {
                v[i] = (v[i-1] ^ arr[i]);
            }
        }

        int cnt0 = 0, cnt1 = 0;
        for(int i=0; i<n; i++)
        {
            // cout << v[i];
            // if(ans >= mod) ans = ans % mod;
            if(v[i] == 0)
            {
                ans = (ans + cnt1) % mod;
                cnt0++;
            }
            else
            {
                ans = (ans + cnt0) % mod;
                cnt1++;
            }
        }
        return (ans + cnt1) % mod;
    }
};