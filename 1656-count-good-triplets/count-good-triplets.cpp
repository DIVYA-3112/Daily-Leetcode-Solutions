class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    int a1 = abs(arr[i] - arr[j]);
                    int a2 = abs(arr[k] - arr[j]);
                    int a3 = abs(arr[i] - arr[k]);

                    if(a1 <= a && a2 <= b && a3 <= c) cnt++;
                }
            }
        }
        return cnt;
    }
};