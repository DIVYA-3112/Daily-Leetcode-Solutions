class Solution {
public:
    // divya
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        // loop 1 - putting all left balls in each boxes
        int cnt = 0, sum = 0;
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)
        {
            ans[i] += sum;
            if(boxes[i] == '1') cnt++;
            sum += cnt;
        }
        sum = 0, cnt = 0;

        // loop 2 - putting all right balls in each box
        for(int i=n-1; i>=0; i--)
        {
            ans[i] += sum;
            if(boxes[i] == '1') cnt++;
            sum += cnt;
        }
        return ans;
    }
};