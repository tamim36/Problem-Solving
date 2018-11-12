#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("Output.txt", "w", stdout);
    int num, cnt;

    while (cin>>num && num!=0){
        queue <int> que;
        cnt = 1;

        for (int i=1; i<=num; i++){
            que.push(i);
        }
        cout << "Discarded cards:";
        while (!que.empty()){
            if (cnt%2 == 1){
                if (que.size() == 1){
                        cout<<endl;
                    cout << "Remaining card: " << que.front() << endl;
                    que.pop();
                }
                else {
                cout << " " << que.front() ;
                if (que.size() != 2){
                    cout << "," ;
                }
                que.pop();
                }
            }
            else {
                que.push(que.front());
                que.pop();
            }
            cnt++;
        }
    }
    return 0;
}
