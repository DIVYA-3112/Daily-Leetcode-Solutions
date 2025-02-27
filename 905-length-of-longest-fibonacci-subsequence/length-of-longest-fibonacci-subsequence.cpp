class Solution {
public:

    int bs(int k, int n, vector<int> &arr)
    {
        int l = 0, h = n-1;
        while(h >= l)
        {
            int mid = h - (h - l)/2;
            if(arr[mid] == k) return mid;
            else if(arr[mid] > k) h = mid-1;
            else l = mid + 1;
        }
        return -1;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> v;
            v.push_back(arr[i]);
            for(int j=i+1; j<n; j++)
            {
                v.push_back(arr[j]);
                // cout << "i - " << i << "j - " << j << endl;
                while(true)
                {
                    int s = v.size();
                    int req = v[s-1] + v[s-2];
                    int chk = bs(req, n, arr);
                    // cout << "chk - " << chk << endl;
                    if(chk == -1)
                    {
                        ans = max(ans, s);
                        v = {arr[i]};
                        break;
                    }
                    else
                    {
                        v.push_back(arr[chk]);
                    }
                }
            }
        }
        return (ans > 2) ? ans : 0;

    }
};