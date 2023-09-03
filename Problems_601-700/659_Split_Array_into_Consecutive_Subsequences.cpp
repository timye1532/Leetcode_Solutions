/* for each num in nums first try placing it in one of the existing subseq.
if no subseq. needs that number.
then, try creating a new subseq. of at least length 3 starting with that num.

if neither of the two condtn is true, we return false
since, that num can't be a part of any subseq.

*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // freq dict the frequency of nums
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }

        // need dict record the need for consecutive numbers
        unordered_map<int, int> need;
        for (int num: nums) {
            if (freq[num] ==  0) continue;
            
            if (need[num] > 0) {
                freq[num]--;
                need[num]--;
                need[num+1]++;
            } else if (freq[num+1] > 0 && freq[num+2] > 0) {
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;

                need[num+3]++;
            } else {
                return false;
            }
        }
        return true;
    }
};