#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

void printItinerary(unordered_map<string, string> tickets) {

    // Starting Point
    unordered_set<string> to;

    for (pair<string, string> ticket : tickets) {   // <from, to>
        to.insert(ticket.second);
    }

    string start = "";
    for (pair<string, string> ticket : tickets) {
        // set.find(key) function return iterator if that key exist in the set else return set.end().
        if (to.find(ticket.first) == to.end()) {     // starting pt
            start = ticket.first;
        }
    }

    // Plan Print
    cout << start << " -> ";
    while (tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }

    cout << "destination\n";
}

int main() {

    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"]  = "Delhi";
    tickets["Goa"]     = "Chennai";
    tickets["Delhi"]   = "Goa";

    printItinerary(tickets);

    return 0;
}
