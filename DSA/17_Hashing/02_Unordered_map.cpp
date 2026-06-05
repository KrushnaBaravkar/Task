#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["india"] = 160;
    m["UK"] = 1;
    m["USA"] = 16;
    m["UAE"] = 2.5;
    m["Bhutan"] = 2.5;

    m.erase("UAE");  // erase function

    for(pair<string, int > countary : m){
        cout<<countary.first <<" - "<<countary.second<<endl;  
    }

    cout<<m.count("india")<<endl;
    cout<<m.count("USA")<<endl;
    cout<<m.count("Nepal")<<endl;

    return 0;
}