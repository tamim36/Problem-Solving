#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(const int& l, const int& r)
    {
     return l > r;
    }
};


int main ()
{
    //priority_queue <int, vector<int>, compare > qu;
    priority_queue<int,vector<int>, compare > qu;
    //priority_queue <int>::iterator it;

    int num;

    while (cin>>num && num != 0){
        int a, b, sum = 0, cost = 0;

        for (int i=0; i<num; i++){
            cin >> a;
            qu.push(a);
        }

        /*while (!qu.empty()){
            cout << qu.top() << endl;
            qu.pop();
        }*/


        while (!qu.empty()){
            a = qu.top();
            qu.pop();
            b = qu.top();
            qu.pop();
            sum = a + b;
            cost = cost + sum;
            if (qu.empty())
                break;
            qu.push(sum);
        }

        cout << cost << endl;
    }
    return 0;
}
