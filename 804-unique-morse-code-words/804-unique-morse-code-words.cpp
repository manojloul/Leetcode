class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
       
        
        for(int i=0;i<words.size();++i)
        {
            string temp=words[i];
             string st;
             for(int i=0;i<temp.size();++i)
                 st+=v[temp[i]-97];
            
            s.insert(st);
        }
        return s.size();
    }
};