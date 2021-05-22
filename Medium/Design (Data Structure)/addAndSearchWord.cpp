class WordDictionary {
public:
    
    map <string,string> myMap;
    int minSize = 2147483647;
    int maxSize = 0;
    /** Initialize your data structure here. */
    WordDictionary() {
        myMap.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        myMap.insert({word,word});
        if(word.size()<minSize) {
            minSize = word.size();
        }
        if(word.size() > maxSize) {
            maxSize = word.size();
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.size() > maxSize || word.size() < minSize) {
            return false;
        } 
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            string tempword = i->first;
            if (tempword.size() != word.size()) {
                continue;
            }
            else {
                for (int j = 0; j < word.size(); j++) {
            
                    if (tempword[j] != word[j] && word [j] !='.') {
                        break;
                    }
                    if(j == word.size()-1) {
                        if ((word[j]=='.' || tempword[j] ==word[j])) {
                            return true;
                        }
                    }
    
                }
            }
        }
        return false; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */