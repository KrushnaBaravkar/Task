// 2 words are amagram if they have same ni. of emements and tere frequency is also same and the elements used should be same only order of eements can be different.

// T.C - o(n)
// S.C - o(k) / k-unique char count.
#include <bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2){
    unordered_map<char,int> m;       // using just single map.

    if(s1.size() != s2.size()){
        return false;
    }
    for(int i=0; i<s1.size(); i++){
        if(m.count(s1[i])){        // for s1 - increase frequency of that perticular char
            m[s1[i]]++;
        }
        else{
            m[s1[i]] = 1;
        }

        if(m.count(s2[i])){       // for s2 - decrease frequency of that perticular char.
            m[s2[i]]--;
        }
        else{
            m[s2[i]] = -1;
        }
    }

    for(pair<char,int> p : m){     // if it is anagram then frequency of all the char should be 0, (IMP)
        if(p.second != 0){
            return false;     
        }
    }
    return true;
}
int main() {
    
    string s1 = "small55";
    string s2 = "malll55";

    cout<<anagram(s1, s2);
    return 0;
}