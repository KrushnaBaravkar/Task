#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <utility>   // Required for std::pair and std::make_pair

using namespace std;

// This is the class definition from image_dc4406.png
class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

// This is the function from image_dc444c.png and image_dc44a5.png
// It includes the correction from your last request (image_dc9b38.png)
int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for(int i=0; i<n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); //idx, deadline, profit
    }

    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    // Check if there are any jobs
    if (n == 0) {
        return 0;
    }

    // Select the first (highest profit) job
    // This is the corrected line:
    cout << "selecting Job" << jobs[0].idx << endl; 
    int profit = jobs[0].profit;
    int safeDeadline = 2; // Represents the next available time slot

    // Try to schedule the remaining jobs
    for(int i=1; i<n; i++) {
        // If the job's deadline is late enough to be scheduled
        if(jobs[i].deadline >= safeDeadline) {
            cout << "selecting Job" << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++; // Increment the next available time slot
        }
    }
    
    // The original function was missing this, but it should return the profit
    return profit; 
}

// This is the main function from image_dc44e0.png
int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    // Call the function (and print the result, which is good practice)
    int totalProfit = maxProfit(jobs);
    cout << "Total Profit: " << totalProfit << endl;
    
    return 0;
}