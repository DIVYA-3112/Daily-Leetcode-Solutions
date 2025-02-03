class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int N = 0, S = 0, E = 0, W = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
            {
                if(s[i] == 'N') N++;
                else if(s[i] == 'S') S++;
                else if(s[i] == 'W') W++;
                else E++;

                int max1 = max(N,S);
                int min1 = min(N,S);
                int max2 = max(E,W);
                int min2 = min(E,W);

                int p = min(min1 + min2, k);
                ans = max(ans, max1 + max2 - min1 - min2 + 2 * p);
            }
            // if(ans > n) ans = n;
            return ans;
    }
};