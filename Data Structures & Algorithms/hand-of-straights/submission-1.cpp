class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> freq;

        for (int i = 0; i < hand.size(); i++) {
            freq[hand[i]]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int j = 0; j < groupSize; j++) {
                if (freq.find(start + j) == freq.end()) {
                    return false;
                }

                freq[start + j]--;

                if (freq[start + j] == 0) {
                    freq.erase(start + j);
                }
            }
        }
        return true;
    }
};