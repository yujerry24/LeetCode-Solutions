class Solution {
public:
    vector<vector<int>> combinationSum2 (vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        solutions.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        temp.clear();
        
        vector<int> visited;
        visited.clear();
        
        for(int i=0; i<candidates.size(); i++) {
                
            if(find(visited.begin(), visited.end(),candidates.at(i))!=visited.end()) {
                continue;
            } else {
                temp.push_back(candidates.at(i));
                visited.push_back(candidates.at(i));
                possibleSolution(temp, candidates, target, i, solutions,visited);
                temp.pop_back();
            }
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
    
    void possibleSolution (vector<int> & sol, vector<int> & candidates, int target, int index, vector<vector<int>> & solutions, vector<int> visited) {
        if(sumOfVector(sol)>target) {
            return;
        }
        if(sumOfVector(sol)==target) {
            solutions.push_back(sol);
            return;
        }
        
     
        visited.clear();
        
        for(int i = index+1; i<candidates.size(); i++) {
            if(find(visited.begin(), visited.end(),candidates.at(i))!=visited.end())  {
                continue;
            } else {
                sol.push_back(candidates.at(i));
                possibleSolution(sol, candidates, target, i, solutions, visited);
                visited.push_back(candidates.at(i));
                sol.pop_back();
                
            }
        }
    }
};class Solution {
public:
    vector<vector<int>> combinationSum2 (vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        solutions.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        temp.clear();
        
        vector<int> visited;
        visited.clear();
        
        for(int i=0; i<candidates.size(); i++) {
                
            if(find(visited.begin(), visited.end(),candidates.at(i))!=visited.end()) {
                continue;
            } else {
                temp.push_back(candidates.at(i));
                visited.push_back(candidates.at(i));
                possibleSolution(temp, candidates, target, i, solutions,visited);
                temp.pop_back();
            }
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
    
    void possibleSolution (vector<int> & sol, vector<int> & candidates, int target, int index, vector<vector<int>> & solutions, vector<int> visited) {
        if(sumOfVector(sol)>target) {
            return;
        }
        if(sumOfVector(sol)==target) {
            solutions.push_back(sol);
            return;
        }
        
     
        visited.clear();
        
        for(int i = index+1; i<candidates.size(); i++) {
            if(find(visited.begin(), visited.end(),candidates.at(i))!=visited.end())  {
                continue;
            } else {
                sol.push_back(candidates.at(i));
                possibleSolution(sol, candidates, target, i, solutions, visited);
                visited.push_back(candidates.at(i));
                sol.pop_back();
                
            }
        }
    }
};