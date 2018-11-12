#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("Output.txt", "w", stdout);
    int test, cnt = 0;
    cin >> test;

    while (test--){
        cnt ++ ;

        map <string,int> mp;
        map <string,int> ::iterator it;

        int num, days, sub_day;
        string sub;

        cin >> num;

        for (int i=0; i<num; i++){
            cin >> sub;
            cin >> sub_day;

            mp[sub] = sub_day;
        }

        cin >> days;
        cin >> sub;

        if (mp[sub] == 0){
            cout << "Case " << cnt << ": Do your own homework!" << endl;
        }

        else if (mp[sub] <= days){
            cout << "Case " << cnt << ": Yesss" << endl;
        }

        else if (mp[sub] > days  && mp[sub] <= days+5){
            cout << "Case " << cnt << ": Late" << endl;
        }

        else {
            cout << "Case " << cnt << ": Do your own homework!" << endl;
        }
    }
    return 0;
}
