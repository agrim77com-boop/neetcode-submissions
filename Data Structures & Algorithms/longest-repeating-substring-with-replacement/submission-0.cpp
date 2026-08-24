class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int ans = 0;

        int freq[26] = {0};

        while (right < s.length()) {

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            right++;

            while ((right - left) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans,right - left);
        }
        return ans;
    }
};