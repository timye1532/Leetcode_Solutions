// straight forward solution
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); i++)
        {
            char letter = order[i];
            dict[letter] = i;
        }

        for (int j = 1; j < words.size(); j++)
        {
            if (!check(words[j-1], words[j], dict)) return false;
        }

        return true;
    }

    bool check(const string& word1, const string& word2, unordered_map<char, int>& dict)
    {
        int l1 = word1.size(), l2 = word2.size();
        int i = 0;
        while ((i < l1) && (i < l2))
        {
            char cur_char1 = word1[i];
            char cur_char2 = word2[i];
            if (dict[cur_char1] < dict[cur_char2]) {
                return true;
            } else if (dict[cur_char1] > dict[cur_char2]) {
                return false;
            } else {
                i++;
            }
        }
        return (l1 <= l2);
    }
};