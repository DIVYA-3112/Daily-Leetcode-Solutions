class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q2;
        queue<int> q1;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > pivot)
            {
                q2.push(nums[i]);
            }
            else if(nums[i] < pivot)
            {
                q1.push(nums[i]);
            }
            else
            {
                cnt++;
            }
        }

        vector<int> ans;
        while(!q1.empty())
        {
            ans.push_back(q1.front());
            q1.pop();
        }


        while(cnt--)
        {
            ans.push_back(pivot);
        }

        while(!q2.empty())
        {
            ans.push_back(q2.front());
            q2.pop();
        }

        return ans;

    }
};