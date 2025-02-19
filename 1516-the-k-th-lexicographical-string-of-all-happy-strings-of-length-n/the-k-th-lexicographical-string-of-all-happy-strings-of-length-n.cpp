class Solution {
public:

    void fun(int n, int &k, string &ans, string &s, int last)
    {
        cout << s << endl;
        int len = s.size();
        if(s.size() == n)
        {
            k--;
            if(k == 0)
            {
                ans = s;
            }
            return;
        }
        
        for(int i=0; i<3; i++)
        {
            if(i != last)
            {
                s += (char)(i + 'a');
                fun(n, k, ans, s, i);
                s = s.substr(0,len);
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        // vector<int> v(3,0);
        int last = -1;
        string s = "";
        string ans = "";
        fun(n,k,ans,s,last);
        return ans;
    }
};