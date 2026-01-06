#include <bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    // but our PQ dosnt know on bases of which value should we decide the priorities.
    // therefore we are defining the operatoring overliding so that our queue get to know that what to compare and on what bases should we prioterise.
    bool operator < (const Student &obj) const { // > - overliding this poerator.
        return this->marks < obj.marks;
    }
};
int main() {
    priority_queue<Student> pq;

    pq.push(Student("aman", 98));
    pq.push(Student("bhav", 78));
    pq.push(Student("sonam", 48));

    while(!pq.empty()){
        cout<<"top :"<<pq.top().name<<", "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}