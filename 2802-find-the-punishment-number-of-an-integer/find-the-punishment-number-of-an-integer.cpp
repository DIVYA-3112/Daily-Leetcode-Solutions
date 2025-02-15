class Solution {
public:
    
    bool fun(string s, int n, int len, int sind)
    {
        if(sind == len)
        {
            return (n == 0);
        }
        
        int sum = 0;
        for(int i=sind; i < len; i++)
        {
            sum = sum * 10 + (s[i] - '0');
            if(sum > n) break;
            if(fun(s,n-sum,len,i+1)) return true;
        }
        return false;
    }
    int check(int n)
    {
        int k = n * n;
        string s = to_string(k);
        int len = s.size();
        if(fun(s,n,len,0)) return k;
        else return -1;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            int k = check(i);
            if(k != -1)
            {
                ans += k; 
                // cout << k << endl;
            }
        }
        return ans;
    }
};