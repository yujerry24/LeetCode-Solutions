#include <iostream>
#include <utility>
#include <functional>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> set;
        vector<vector<string>> answer;
        for (int i = 0; i< strs.size(); i++) {
            string temp = strs.at(i);
            sort(temp.begin(), temp.end());
            if (set.find(temp) == set.end()) {
                cout<<"hello"<<endl;
                vector<string> cur;
                cur.push_back(strs.at(i));
                set.emplace(temp,  cur);
            } else {
                vector<string> cur = set.find(temp)->second;
                cur.push_back(strs.at(i));
                set.at(temp) =   cur;
            }
        }
        for (auto const& x : set) {
            answer.push_back(x.second);
        }
        return answer;
    }
};