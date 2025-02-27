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
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            int a = arr[i];
            cnt++;
            for(int j=i+1; j<n; j++)
            {
                int b = arr[j];
                cnt++;
                while(true)
                {
                    int req = a + b;
                    int chk = bs(req, n, arr);
                    if(chk == -1)
                    {
                        ans = max(ans, cnt);
                        cnt = 1;
                        a = arr[i];
                        break;
                    }
                    else
                    {
                        a = b;
                        b = arr[chk];
                        cnt++;
                    }
                }
            }
            cnt = 0;
        }
        return (ans > 2) ? ans : 0;

    }
};