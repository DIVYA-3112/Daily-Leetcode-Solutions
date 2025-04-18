class Solution {
public:

    string fun(int n, string s)
    {
        if(n == 1) return s;

        int len = s.size();
        char st = s[0];
        int cnt = 1;
        string ns = "";
        for(int i=1; i<len; i++)
        {
            if(s[i] == st) cnt++;
            else
            {
                ns += (char)(cnt + '0');
                ns += st;
                cnt = 1;
                st = s[i];
            }
        }
        ns += (char)(cnt + '0');
        ns += st;
        return fun(n-1, ns);
    }
    string countAndSay(int n) {
        string s = "1";
        return fun(n, s);
    }
};