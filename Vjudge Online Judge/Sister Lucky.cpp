#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    for (int i=1; i<=num; i++){
        if (i%4 == 1){
            cout<<"a";
        }
        else if (i%4 == 2){
            cout << "b";
        }
        else if (i%4 == 3){
            cout << "c";
        }
        else if (i%4==0){
            cout<<"d";
        }
    }
    return 0;
}
