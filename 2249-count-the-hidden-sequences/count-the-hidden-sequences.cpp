class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) {
        int n = arr.size();
        long long last = 0;
        long long mini = 0, maxi = 0;
        for(int i : arr)
        {
            long long k = i + last;
            mini = min(mini, k);
            maxi = max(maxi, k);
            last = k;
        }
        int diff1 = (upper - lower + 1);
        int diff2 = maxi - mini;
        if(diff2 > diff1) return 0;
        else return diff1 - diff2;
    }
};