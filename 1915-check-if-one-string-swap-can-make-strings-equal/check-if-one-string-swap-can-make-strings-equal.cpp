class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(s1 == s2) return true;

        if(n1 != n2) return false;
        int cnt = 0;
        int i1=-1,i2=-1;

        for(int i=0; i<n1; i++)
        {
            if(s1[i] != s2[i])
            {
                cnt++;
                i1 = i2;
                i2 = i;
            }
        }

        if(cnt == 2)
        {
            swap(s1[i1],s1[i2]);
            if(s1 == s2) return true;
        }
        return false;
    }
};