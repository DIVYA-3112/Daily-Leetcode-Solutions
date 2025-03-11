class Solution {
public:
    int numberOfSubstrings(string s) {

        int l=0,r=0;
        int n = s.size();
        int ans = 0;
        int cnta=0, cntb=0, cntc=0;

        while(r < n)
        {
            if(s[r] == 'a') cnta++;
            else if(s[r] == 'b') cntb++;
            else cntc++;

            while(cnta > 0 && cntb > 0 && cntc > 0)
            {
                ans += (n-r);
                if(s[l] == 'a') cnta--;
                else if(s[l] == 'b') cntb--;
                else cntc--;
                l++;
            }
            r++;
        }

        return ans;
    }
};