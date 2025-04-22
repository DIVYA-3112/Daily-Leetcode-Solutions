class Solution {
public:
    long long calculateScore(vector<string>& arr, vector<int>& val) {
        long long ans = 0;
        int n = arr.size();

        vector<int> vis(n,0);
        int i = 0;
        while(i<n && i>=0 && vis[i] == 0)
        {
            vis[i] = 1;
            if(arr[i] == "jump")
            {
                i += val[i];
            }
            else if(arr[i] == "add")
            {
                ans += val[i];
                i++;
            }
        }
        return ans;
    }
};