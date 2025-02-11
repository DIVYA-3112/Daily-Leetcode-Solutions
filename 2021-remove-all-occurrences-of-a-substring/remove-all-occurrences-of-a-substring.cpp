class Solution {
public:
    string removeOccurrences(string s, string part) {
       stack<char> st;
       int n = s.size();
       int m = part.size();
       char c = part[m-1];
       reverse(part.begin(), part.end());

       for(int i=0; i<n; i++)
       {
            st.push(s[i]);
            if(st.top() == c)
            {
                if(st.size() < m) continue;
                int t = m;
                string temp = "";
                while(t--)
                {
                    temp += st.top();
                    st.pop();
                }
                if(temp != part)
                {
                    for(int i=0; i<m; i++)
                    {
                        st.push(temp[m-i-1]);
                    }
                }
            }
       } 

       string ans = "";
       while(!st.empty())
       {
          ans += st.top();
          st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans; 
    }
};