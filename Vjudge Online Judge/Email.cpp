#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char ara[1000], n[1000];
    int j=0, len, flag=0, att = 0;
    gets(ara);
    len = strlen(ara);


    for (int i=0; i<len; i++){
            flag = 0;
        if(ara[i] == 'd'  &&  i!=0  &&  (i+2)!= len-1 ){
            if (ara[i+1] == 'o' ){
                if (ara[i+2] == 't'){
                    n[j] = '.';
                    j++;
                    i=i+2;
                    flag=1;
                }
            }
        }
        else if (ara[i] == 'a' && (i!=0) && (i+1)!=len-1   &&   att==0 )  {
            if (ara[i+1] == 't'){
                n[j] = '@';
                i = i+1;
                j++;
                att = 1;
                flag = 1;
            }
        }
        if (flag == 0) {
            n[j] = ara[i];
            j++;
        }
    }
    //n[j++] = ara[len-1];
    n[j] = '\0';
    cout << n << endl;


    return 0;
}
