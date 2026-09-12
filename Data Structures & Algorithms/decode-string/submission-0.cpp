class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string curr = "";
        int num = 0;

        for (int i = 0; i < s.length(); i++) {

            // Build the number
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // Start of a new bracket
            else if (s[i] == '[') {
                numStack.push(num);
                strStack.push(curr);

                num = 0;
                curr = "";
            }

            // End of a bracket
            else if (s[i] == ']') {

                int k = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string temp = "";

                for (int j = 0; j < k; j++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            // Normal character
            else {
                curr += s[i];
            }
        }

        return curr;
    }
};