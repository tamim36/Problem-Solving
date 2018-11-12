#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("aaa.txt", "w", stdout)
    map <string,int> mp;
    map <string,int>::iterator it;
    int p=1, loc;
    string s, s1, s2, s3, s4, s5,s6, inp ;

    string a = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<26; i++){
        s = a[i];
        mp[s] = p;
        p++;
    }
    for (int j=0; j<=25 ; j++){
        for (int i=j+1; i<=25; i++){
            s1 = a[j];
            s2 = a[i];
            s = s1+s2;
            mp[s] = p;
            p++;
        }
    }
    for (int k=0; k<=25; k++){
        for (int j=k+1; j<=25 ; j++){
            for (int i=j+1; i<=25; i++){
                s3 = a[k];
                s1 = a[j];
                s2 = a[i];
                s = s3+s1+s2;
                mp[s] = p;
                p++;
            }
        }
    }
    for (int l=0; l<=25; l++){
        for (int k=l+1; k<=25; k++){
            for (int j=k+1; j<=25 ; j++){
                for (int i=j+1; i<=25; i++){
                    s4 = a[l];
                    s3 = a[k];
                    s1 = a[j];
                    s2 = a[i];
                    s = s4+s3+s1+s2;
                    mp[s] = p;
                    p++;
                }
            }
        }
    }
    for (int m=0; m<=25; m++){
            for (int l=m+1; l<=25; l++){
            for (int k=l+1; k<=25; k++){
                for (int j=k+1; j<=25 ; j++){
                    for (int i=j+1; i<=25; i++){
                        s5=a[m];
                        s4 = a[l];
                            s3 = a[k];
                        s1 = a[j];
                        s2 = a[i];
                        s = s5+s4+s3+s1+s2;
                        mp[s] = p;
                        p++;
                    }
                }
            }
        }
    }
    while (cin >>inp){

            cout <<mp[inp] << endl;

    }
    return 0;
}

