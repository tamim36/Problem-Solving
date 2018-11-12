#include <bits/stdc++.h>
using namespace std;

int main()
{

   freopen("Output.txt", "w", stdout);
    int tes_cas;
    cin >> tes_cas;
    for  (int t=0; t<=tes_cas+1; t++){

    string tree;
    int num, a, b, c=0;
    map <string,double> mp;
    map <string,double> ::iterator it;

    while(getline(cin, tree)){
            if (tree[0] == '\0'){
                break;
            }
        c++;
        /*if (mp[tree] == 0){
            mp[tree] = 1;
        }
        else {
            mp[tree]++;
            }*/
            mp[tree]++;
        }
    for (it = mp.begin(); it != mp.end(); it++){
        double  ans = (it->second * 100) /c;
        it->second = ans;
    }
    for (it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " ";
        printf("%0.4lf\n", it->second);
    }
    if(t>1 && t<tes_cas+1){
    printf("\n");
    }

    //printf("Case %d: %d\n", t, sum);
    }


    return 0;
}
