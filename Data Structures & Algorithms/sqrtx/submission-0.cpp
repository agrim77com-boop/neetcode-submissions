class Solution {
public:
    int mySqrt(int x) {

        int left = 0;
        int right = x;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            long long square = 1LL * mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square > x) {
                right = mid - 1;
            }
            else {
                ans = mid;
                left = mid + 1;
            }
        }

        return ans;
    }
};