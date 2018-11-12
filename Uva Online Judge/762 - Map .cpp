#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string,int> mp1;
    map <int, string> mp2;
    map <string,int> ::iterator it;
    map <string,int> ::iterator it2;
    string a, b;
    int i=1;
    int j=1;
    string str1 = "pt" , str2;
    int num1, num2;
    while (1){
        cin >> a >>b;
        if (mp1[a] == 0){
        mp1[a] = i++;
        mp2[j++] = a;
        }
        if (mp1[b] == 0){
            mp1[b] = i++;
            mp2[j++] = b;
        }


           // str1 = mp2[mp1[2]];
           // cout << str1<<endl;
           num1 = mp1[str1];
           cout << num1 << endl;

  }
   //c = ((a[0] - 'a' + 1)*10) + a[1] - 'a' +1;

    return 0;
}
