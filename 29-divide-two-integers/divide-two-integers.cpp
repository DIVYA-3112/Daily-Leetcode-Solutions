class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        long long int num = abs((long long)dividend);
        long long int k = abs((long long)divisor);
        long long int ans = 0;
        while(num >= k)
        {
            int i=0;
            long long t1 = num;
            long long t2 = k;

            while((t2 << i) <= t1)
            {
                i++;
            }
            long long t3 = t1 - (t2 << (i-1));
            ans = (ans | (1 << (i-1)));
            num = t3;
        }
        if(divisor < 0) ans *= -1;
        if(dividend < 0) ans *= -1; 
        return ans;
    }
};