class Solution {
public:
    int numOfUnplacedFruits(vector<int>& arr, vector<int>& bas) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i] <= bas[j])
                {
                    bas[j] = -1;
                    arr[i] = 0;
                    break;
                }
            }
            if(arr[i] > 0) ans++;
        }
        return ans;
    }
};