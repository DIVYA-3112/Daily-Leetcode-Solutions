class Solution {
public:

    bool check(int n)
    {
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i=3; i<n; i+=2)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int n1 = left,n2 = right;
        bool p = false;
        int ans1 = -1, ans2 = -1;
        int diff = INT_MAX;
        for(int i=left; i<=right; i++)
        {
            if(check(i) && p)
            {
                cout << i << " - prime" << endl;
                n2 = n1;
                n1 = i;
                int ndiff = n1 - n2;
                if(ndiff <= 2)
                {
                    return {n2, n1};
                }
                if(ndiff < diff)
                {
                    diff = ndiff;
                    ans1 = n2;
                    ans2 = n1;
                }
            }
            else if(check(i))
            {
                cout << i << " - prime" << endl;
                p = true;
                n1 = i;
            }
        }
        return {ans1, ans2};
    }
};