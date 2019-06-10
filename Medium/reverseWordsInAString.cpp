//Solved on June 10th, 2019
//Trim functions were taken from https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
//In hindsight, solving this in Java would've been easier 

class Solution {
public:
    const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s)
{
    return rtrim(ltrim(s));
}

string reverseWords(string s) {
    vector <string> list;
        string newString="";
        while(s.size()>0) {
            s=trim(s);
            if(s.find(" ")!=string::npos) {
                list.push_back(s.substr(0,s.find(" ")));
                //cout<<"Pushing back: "<<s.substr(0,s.find(" "))<<endl;
                s=s.substr(s.find(" "));
            }
            else {
                list.push_back(s);
                //cout<<"Pushing back: "<<s<<endl;
                s="";
            }
        }
        for(int i=list.size()-1; i>=0; i--) {
            newString+=list.at(i);
            if(i!=0) {
                newString+=" ";
            }
        
        }
        return newString;
}
};