class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        s = "";
        while(!st.empty())
        {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};