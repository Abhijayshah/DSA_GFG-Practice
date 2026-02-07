class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {

        if (s1.size() != s2.size())
            return false;

        // Mapping arrays for 26 lowercase letters
        vector<int> map1(26, -1);
        vector<int> map2(26, -1);

        for (int i = 0; i < s1.size(); i++) {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            // Check s1 -> s2 mapping
            if (map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                map2[c2] = c1;
            }
            else {
                if (map1[c1] != c2 || map2[c2] != c1)
                    return false;
            }
        }

        return true;
    }
};
