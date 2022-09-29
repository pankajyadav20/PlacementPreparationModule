

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1 , st2;
        for(auto it : s){
        	if(it == '#'){
        		if(st1.size() != 0){
        			st1.pop();
        		}
        	}else st1.push(it);
        }
          for(auto it : t){
        	if(it == '#'){
        		if(st2.size() != 0){
        			st2.pop();
        		}
        	}else st2.push(it);
        }
        if(st1.size() != st2.size()){
        	return false;
        }
        while(st1.size() > 0 || st2.size() > 0){
        	if(st1.top() != st2.top()){
        		return false;
        	}else{
        		st1.pop();
        		st2.pop();
        	}
        } 
        return true;
    }
};