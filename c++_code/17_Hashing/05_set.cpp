#include <bits/stdc++.h>
using namespace std;

int main() {
    
    set<int> s;

    s.insert(1);
    s.insert(7);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    // doublicates are not formed inside the same u_set.
    s.insert(7);
    s.insert(5);
    s.insert(0);
    s.insert(8);

    cout<<s.size()<<endl;
    s.erase(5);

    if(s.find(4) != s.end()){   // checking does 4 exist in the set.
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key dosnt found"<<endl;
    }

    for(auto el : s){
        cout<<el<<", ";
    }
    cout<<endl;
    return 0;
}