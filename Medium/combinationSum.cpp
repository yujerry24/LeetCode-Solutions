/* Jerry Yu
* July 29th, 2019
* First time doing a backtracking solution.
*/


class Solution {
public:
    vector<vector<int>> combinationSum (vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        solutions.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        temp.clear();
        for(int i=0; i<candidates.size(); i++) {
            temp.push_back(candidates.at(i));
            possibleSolution(temp, candidates, target, i, solutions);
            temp.pop_back();
        }
        
        return solutions;
    }
    
    int sumOfVector (vector<int> & vec) {
        if (vec.size()==0) {
            return 0;
        }
        
        int sum = 0;
        for(int i = 0; i<vec.size(); i++) {
            sum += vec.at(i);
        }
        
        return sum;
    }
    
    void possibleSolution (vector<int> & sol, vector<int> & candidates, int target, int index, vector<vector<int>> & solutions) {
        if(sumOfVector(sol)>target) {
            return;
        }
        if(sumOfVector(sol)==target) {
            solutions.push_back(sol);
            return;
        }
        for(int i = index; i<candidates.size(); i++) {
            sol.push_back(candidates.at(i));
            possibleSolution(sol, candidates, target, i, solutions);
            sol.pop_back();
        }
    }
};