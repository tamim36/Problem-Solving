#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("output.txt", "w", stdout);
    char ara[200];
    stack <char> stk;
    int tes, i=0;
    cin >> tes;
        getchar();
    while (i < tes){
            i++;
    int flag = 0;
    fgets(ara, sizeof ara, stdin);
    for (int i=0; ara[i] != '\0' ; i++){
            if (ara[i] == '(' || ara[i] == '['){
                stk.push(ara[i]);
            }
            else if (ara[i] == ')' || ara[i] == ']'){
                if (stk.empty()){
                    flag = 1;
                    break;
                }
                char c = stk.top();
                stk.pop();
                if (ara[i] == ')'){
                    if ( c != '('){
                            flag = 1;
                            break;
                        }
                }
                else if (ara[i] == ']'){
                    if (c != '['){
                        flag = 1;
                        break;
                    }
                }
            }
    }

    if ((flag == 1) ||  (!stk.empty())){
        cout << "No\n";
        while (!stk.empty()){
            stk.pop();
        }
    }
    else {
        cout << "Yes\n";
    }

    }
    return 0;
}
