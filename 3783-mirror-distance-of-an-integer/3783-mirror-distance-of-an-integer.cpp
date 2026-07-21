class Solution {
public:
    int mirrorDistance(int n) {
        int c = n;
        int rev = 0;

        while (c > 0) {
            rev = rev * 10 + c % 10;
            c /= 10;
        }

        return abs(n - rev);
    }
};