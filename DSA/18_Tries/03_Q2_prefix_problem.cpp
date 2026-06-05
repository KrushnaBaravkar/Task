#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unordered_map<char, pair<Node*, int>> children; // char -> (Node*, freq)
    bool endOfString;

    Node() {
        endOfString = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(const string &key) {  // insert new string
        Node* temp = root;
        for (char c : key) {
            if (temp->children.count(c)) {
                temp->children[c].second++; // increase frequency
            } else {
                temp->children[c] = {new Node(), 1};
            }
            temp = temp->children[c].first;
        }
        temp->endOfString = true;
    }

    vector<string> shortestUniquePrefixes(const vector<string>& words) {
        // 1) Insert all words
        for (const string &s : words) {
            insert(s);
        }

        // 2) Find shortest unique prefix for each word
        vector<string> ans;
        for (const string &s : words) {
            Node* temp = root;
            string prefix = "";
            for (char c : s) {
                prefix.push_back(c);
                if (temp->children[c].second == 1) {
                    ans.push_back(prefix);
                    break;
                }
                temp = temp->children[c].first;
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"one", "two", "twree", "twrr", "fove"};
    Trie t;

    vector<string> ans = t.shortestUniquePrefixes(words);

    cout << "Shortest unique prefixes are:\n";
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
