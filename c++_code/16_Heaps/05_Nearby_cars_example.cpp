// IMP implementation.

#include <bits/stdc++.h>
using namespace std;
class Car{
public:
    int idx;
    int distsq;

    Car(int idx, int distsq){
        this->idx = idx;
        this->distsq = distsq;
    }

    bool operator < (const Car &obj) const{  // operator overloding so that PQ should know the meaning of that perticular operator and should creat desired pq(MAX/MIN).
        return this->distsq > obj.distsq;
    }
};

void Nearest_car(vector<pair<int, int>> &arr, int k){
    vector<Car> cars;
    for(int i=0; i<arr.size(); i++){   // o(n)
        int dist = (arr[i].first * arr[i].first) + (arr[i].second * arr[i].second);
        cars.push_back(Car(i, dist));
    }

    // priority_queue<Car> pq;
    // for(int i=0; i<cars.size(); i++){   
    //     pq.push(cars[i]);
    // }  
    // above implementation takes o(nlog(n)) complexivity.
    // insted we do following 
    priority_queue<Car> pq(cars.begin(), cars.end());  // o(n)  -- complexivity which is less than the preious case

    cout<<"Nearest k objects are : ";
    for(int i=0; i<k; i++){
        cout<<pq.top().idx<<" ";
        pq.pop();
    }
}
int main() {
    vector<pair<int, int>> arr = {
    {3, 3},
    {5, -1},
    {-2, 4}
};   // orordinates of the cars.
    int k = 2;  // count of nearest cars required

    Nearest_car(arr, k);
    return 0;
}