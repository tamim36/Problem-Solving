#include <bits/stdc++.h>
using namespace std;

int main ()
{
    //freopen("vOutput.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num,ans,mx;

    while (cin>>num && num!=0){

        map <string,int> mp;
        map <string,int> ::iterator it;
            for (int t=0; t<num; t++){
                ans=0, mx=0;
                string ara[5], combo;

                for (int i=0; i<5; i++){
                    cin >> ara[i];
                }
                sort (ara, ara+5);
                for (int i=0; i<5; i++){
                    combo +=ara[i];
                }
                mp[combo]++;
            }
            for (it=mp.begin(); it!=mp.end(); it++){
                mx = max(mx, it->second);
            }
            for (it=mp.begin(); it!=mp.end(); it++){
                if(it->second == mx){
                    ans +=mx;
                }
            }
            cout <<  ans<<endl;
    }
    return 0;
}
