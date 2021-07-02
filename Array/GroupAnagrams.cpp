class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> set;
        vector<vector<string>> answer;
        for (int i = 0; i< strs.size(); i++) {
            string temp = strs.at(i);
            sort(temp.begin(), temp.end());
            if (set.find(temp) == set.end()) {
                vector<string> cur;
                cur.push_back(strs.at(i));
                set.emplace(make_pair<string, vector<string>>(temp,  cur);
            } else {

            }
        }
        for (auto const& x : set) {
            answer.push_back(x.second());
        }
        return answer;
    }
};