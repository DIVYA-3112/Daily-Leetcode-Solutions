class Solution {
public:

    int fun(vector<int> &arr, int num)
    {
        int l=0, h=arr.size()-1;
        int ans = -1;
        while(h>=l)
        {
            int mid = (h) - (h-l)/2;
            if(arr[mid] <= num)
            {
                ans = mid;
                l = mid + 1;
            }
            else if(arr[mid] > num)
            {
                h = mid-1;
            }
        }
        return arr[ans];
    }
    bool checkPowersOfThree(int n) {
        vector<int> temp;
        int k = 1;
        while(k <= n)
        {
            temp.push_back(k);
            k *= 3;
        }

        int s = temp.size();
        int num = n;
        int last = -1;
        // cout << "num - " << num ;
        while(num > 0)
        {
            int check = fun(temp, num);
            cout << check << endl;
            if(check == last) return false;
            last = check;
            num -= check;
        }
        return true;

        
    }
};