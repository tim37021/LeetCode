/*
109 / 109 test cases passed.
Status: Accepted
Runtime: 1768 ms
*/

class Solution {
public:

int expr(string &s)
    {
        int ans = term(s);
        while(s.length()>0)
        {
            switch(s[0])
            {
                case '+':
		    s=s.substr(1);
                    ans += term(s);
                    break;
                case '-':
		    s=s.substr(1);
                    ans -= term(s);
                    break;
                case ' ':
                    s=s.substr(1);
		    break;
		default:
			return ans;
            }
        }
        return ans;
    }
    
    int term(string &s)
    {
        int ans=factor(s);
        while(s.length()>0){
            switch(s[0])
            {
                case '*':
                    s=s.substr(1);
                    ans *= factor(s);
                    break;
                case '/':
                    s=s.substr(1);
                    ans /= factor(s);
                    break;
                case ' ':
                    s=s.substr(1);
		    break;
		default:
			return ans;
            }
        }
        return ans;
    }
    
    int factor(string &s)
    {
        string num;
	int i;
        while(s[0]==' ')
            s=s.substr(1);
        for(int i=0; i<s.length(); i++)
        {
            if((i==0&&s[i]=='-')||isdigit(s[i]))
                num+=s[i];
            else
                break;
        }
        
    	// may be ()
    	if(num=="")
    	{
    		int balance=1;
    		for(i=1; i<s.length()&&balance; i++)
    		{
    			if(s[i]=='(')
    				balance++;
    			if(s[i]==')')
    				balance--;
    		}
    		string s2=s.substr(1, i-2);
    		s=s.substr(i);
    		return expr(s2);
    	}
        
        s = s.substr(num.length());
        return atoi(num.c_str());
    }

    int calculate(string s) {
        return expr(s);
    }
};