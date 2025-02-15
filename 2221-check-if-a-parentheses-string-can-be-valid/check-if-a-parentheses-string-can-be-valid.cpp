class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1) return false;  // Odd length can't be valid

        int balance = 0;  // Open count - Close count
        int wildcards = 0; // Flexible characters

        // Left to right check
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                balance += (s[i] == '(') ? 1 : -1;
            } else {
                wildcards++;  // Can be either `(` or `)`
            }
            if (balance + wildcards < 0) return false;  // More `)` than possible `(`
        }

        balance = 0;
        wildcards = 0;

        // Right to left check
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                balance += (s[i] == ')') ? 1 : -1;
            } else {
                wildcards++;  // Can be either `(` or `)`
            }
            if (balance + wildcards < 0) return false;  // More `(` than possible `)`
        }

        return true;
    }
};
