// CPP program for priority queue using Arrays

#include <bits/stdc++.h>
using namespace std;

struct item
{
    int value;
    int priority;
};

item pr[100000];

int pq_size = -1;

void enqueue(int value, int priority)
{
    pq_size++;
    pr[pq_size].value = value;
    pr[pq_size].priority = priority;
}

int peek()
{
    int highest_priority = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= pq_size; i++)
    {
        if (highest_priority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highest_priority = pr[i].priority;
            ind = i;
        }else if (highest_priority < pr[i].priority) {
            highest_priority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    for (int i = ind; i < pq_size; i++)
    {
        pr[i] = pr[i + 1];
    }
    pq_size--;
}

int main()
{

    vector<pair<int, int>> items = {
        {10, 2}, {14, 4}, {16, 4}, {12, 3}
    };

    for(int i=0; i<items.size(); i++){
        enqueue(items[i].first, items[i].second);
    }

    int ind = peek();
    cout<<pr[ind].value <<endl; //16

    dequeue();

    ind = peek();
    cout<<pr[ind].value <<endl; //14

    dequeue();

    ind = peek();
    cout<<pr[ind].value << endl; //12


    return 0;
}