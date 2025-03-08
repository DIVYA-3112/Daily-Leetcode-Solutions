class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return 1;
        else return (coloredCells(n-1) + (n-1)*4);
    }
};