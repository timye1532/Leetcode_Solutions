// math
class Solution {
public:
    int countOdds(int low, int high) {
        if ((high - low) % 2 == 1)
            return (high - low + 1) / 2;
        int res = (high - low) / 2;
        if (high % 2 == 1) res++;
        return res;
    }
};