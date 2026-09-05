/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int peakIndex(MountainArray &mountainArr) {

        int start = 0;
        int end = mountainArr.length() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return start;
    }

    int binarySearch(MountainArray &mountainArr,
                     int start,
                     int end,
                     int target,
                     bool ascending) {

        while (start <= end) {

            int mid = start + (end - start) / 2;

            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }

            if (ascending) {

                if (value < target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }

            }
            else {

                if (value > target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = peakIndex(mountainArr);

        // Search increasing part first
        int left = binarySearch(mountainArr, 0, peak, target, true);

        if (left != -1) {
            return left;
        }

        // Search decreasing part
        int right = binarySearch(
            mountainArr,
            peak + 1,
            mountainArr.length() - 1,
            target,
            false
        );

        return right;
    }
};