class Solution {
public:
    int pivotArr(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] >= nums[0]) {

                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {

                return mid;
            } else if (nums[mid] > target) {

                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = pivotArr(nums);

        if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {

            return binarySearch(nums, pivot, nums.size() - 1, target);
        }

        else {

            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
