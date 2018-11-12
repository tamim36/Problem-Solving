#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char text[1000], ans[1000];
    int j = 0;
    gets(text);
    for (int i=0; text[i] != '\0'; i++){
        if (text[i] == '.'){
            ans[j] = '0';
            j++;
        }
        else if (text[i+1] == '.'){
            ans[j] = '1';
            j++;
            i++;
        }
        else if (text[i+1] == '-'){
            ans[j] = '2';
            j++;
            i++;
        }
    }
    ans[j] = '\0';
    printf("%s\n", ans);
    return 0;
}
