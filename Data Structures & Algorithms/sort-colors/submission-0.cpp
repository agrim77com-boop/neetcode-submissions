class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector <int> ans1;
        vector <int> ans2;
        vector <int> ans3;

        for(int i =0;i<nums.size();i++){

            if(nums[i] == 0){

                ans1.push_back(nums[i]);
            }
        }

        for(int i =0;i<nums.size();i++){

            if(nums[i] == 1){

                ans2.push_back(nums[i]);
            }
        }

        for(int i =0;i<nums.size();i++){

            if(nums[i] == 2){

                ans3.push_back(nums[i]);
            }
        }

        nums.clear();

        for(int i =0;i<ans1.size();i++){

            nums.push_back(ans1[i]);
        }

        for(int i =0;i<ans2.size();i++){

            nums.push_back(ans2[i]);
        }

        for(int i =0;i<ans3.size();i++){

            nums.push_back(ans3[i]);
        }

        
    }
};