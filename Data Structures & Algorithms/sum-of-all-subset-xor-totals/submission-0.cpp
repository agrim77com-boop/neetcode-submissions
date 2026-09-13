class Solution {
public:
    int ans = 0;

    void solve(vector<int>& nums, int index, int currXor) {
        if (index == nums.size()) {
            ans += currXor;
            return;
        }

        // Include nums[index]
        solve(nums, index + 1, currXor ^ nums[index]);

        // Don't include nums[index]
        solve(nums, index + 1, currXor);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return ans;
    }
};