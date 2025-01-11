class Solution {
public:
    bool hasMatch(string s, string p) {
        int k = p.find('*');
        string t1 = "";
        string t2 = "";

        t1 = p.substr(0,k);
        t2 = p.substr(k+1);

        cout << t1 << " " << t2 << endl;
        int n1 = t1.size();
        int n2 = t2.size();

        if(n1 == 0)
        {
            if(s.find(t2) != string::npos) return true;
            else return false;
        }

        if(n2 == 0)
        {
            if(s.find(t1) != string::npos) return true;
            return false;
        }

        int k1 = s.find(t1);
        if(k1 == string::npos) return false;
        int k2 = s.find(t2,k1+n1);
        if(k2 == string::npos) return false;

        cout << k1 << " " << k2 << endl;
        return true;
        // if(k1 == string::npos || k2 == string::npos) return false;

        // if(k2 > k1 + n1) return true;
        // else return false;
    }
};