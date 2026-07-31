class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size() - 1;
        int area = 0;
        int currArea = 0; 

        while(left<right){     

            currArea = min(heights[left],heights[right]) * (right-left);

            if(heights[left] < heights[right]){

                area=max(area,currArea);
                left++;
            }
            else {

                area=max(area,currArea);
                right--;
            }
        }
        return area;
    }
};
