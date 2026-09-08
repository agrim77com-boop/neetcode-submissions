class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            // No collision possible
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }

            else {
                // Current asteroid is negative
                bool destroyed = false;

                while (!st.empty() && st.top() > 0) {

                    if (st.top() < abs(asteroids[i])) {
                        // Stack asteroid explodes
                        st.pop();
                    }

                    else if (st.top() == abs(asteroids[i])) {
                        // Both explode
                        st.pop();
                        destroyed = true;
                        break;
                    }

                    else {
                        // Current asteroid explodes
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> v;

        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());

        return v;
    }
};