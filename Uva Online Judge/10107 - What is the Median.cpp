#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Output.txt", "w", stdout);
    int num, med, cnt = 0;
    vector <int> vec;


    while (cin >> num){

        vec.push_back(num);
        sort(vec.begin(), vec.end());

        if (cnt%2 == 0){
            med = vec.at(cnt/2);
        }

        else if (cnt%2 == 1){
            med = (vec.at(cnt/2) + vec.at(cnt/2 + 1))/2;
        }
        cnt++;

        cout << med << endl;
    }

    return 0;
}
