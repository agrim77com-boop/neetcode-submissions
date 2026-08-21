class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (s.find(need) != s.end()) {
                return {s[need], i};
            }
            s[nums[i]] = i;
        }
        return {};
    }
};