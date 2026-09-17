class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {

                int idx = st.top();
                st.pop();

                int height = heights[idx];

                int right = i;

                int left;
                if (st.empty())
                    left = -1;
                else
                    left = st.top();

                int width = right - left - 1;

                area = max(area, height * width);
            }

            st.push(i);
        }

        return area;
    }
};