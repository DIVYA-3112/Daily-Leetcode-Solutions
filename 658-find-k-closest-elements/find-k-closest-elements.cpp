class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int l = -1,r = -1;
        vector<int> ans;
        int ind = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == x) break;
            else if(arr[mid] <= x)
            {
                ind = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(ind == -1) ind++;

        if(arr[ind] == x)
        {
            ans.push_back(x);
            l = ind - 1;
            r = ind + 1;
        }
        else
        {
            l = ind;
            r = ind + 1;
        }


        while(ans.size() < k && l >= 0 && r < n)
        {
            // check
            int diffl = abs(arr[l] - x);
            int diffr = abs(arr[r] - x);

            if(diffl > diffr)
            {
                ans.push_back(arr[r]);
                r++;
            }
            else
            {
                ans.push_back(arr[l]);
                l--;
            }
        }

        while(ans.size() < k && l >= 0)
        {
            ans.push_back(arr[l]);
            l--;
        }

        while(ans.size() < k && r < n)
        {
            ans.push_back(arr[r]);
            r++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};