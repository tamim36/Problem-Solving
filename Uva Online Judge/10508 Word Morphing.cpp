#include <bits/stdc++.h>
using namespace std;
int vis[1000];
int main ()
{
    //freopen("Output.txt", "w", stdout);
    vector <string> vec;
    int word, letter, cnt=0, indx =0;

    string prev, rec;
    while (scanf("%d%d", &word, &letter)==2){
        vec.clear();
        memset(vis, 0, sizeof(vis));
        cnt=0, indx =0;
        //cin >> word >> letter;
        for (int i=0; i<word; i++){
            string str;
            cin >> str;
            vec.push_back(str);
    }
        if (vec.size() == 2){
            for (int i=0; i<vec.size(); i++){
            cout << vec[i] <<endl;
            }
        }
        else {
            prev = vec[0];
            cout << vec[0] << endl;
            vis[0] = 1;
                for (int k=0; k<vec.size()-1; k++){
                prev = vec[indx];

                        for (int i=0; i<vec.size()-1; i++){
                            cnt = 0;
                            rec = vec[i+1];
                            if (vis[i+1] == 0 ){
                                for (int j=0; j<letter; j++){
                                    if (prev[j] != rec[j]){
                                        cnt ++;
                                    }
                            }
                                    if (cnt == 1){
                                        cout << rec << endl;
                                        vis[i+1] = 1;
                                        indx = i+1;
                                        break;
                            }
                        }
                    }
                }
            }
        }
    return 0;
}
