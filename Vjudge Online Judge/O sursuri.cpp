#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str;
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);


    for (int i=0; i<str.length(); i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
            str.erase(i,1);
            i -= 1;
        }
    }

    for (int i=0; i<str.length(); i++){
        if (isalpha(str[i]) != 0){
            cout << "." << str[i];
        }
        else{
            cout << str[i];
        }
    }
    return 0;
}
