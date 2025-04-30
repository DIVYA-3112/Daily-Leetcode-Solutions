class Solution {
public:
    int dig(int n)
    {
        int k = 0;
        while(n)
        {
            n = n/10;
            k++;
        }
        return k;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i : nums)
        {
            int k = dig(i);
            if(k % 2 == 0) ans++;
        }
        return ans;
    }
};