#include <bits/stdc++.h>
using namespace std;

int main ()
{

    //freopen("Output.txt", "w", stdout);
    int test, op, num, a;
    while (cin >> test){
            if (test == 0){
                //break;
            }

        stack <int> st;
        queue <int> que;
        priority_queue <int> pq;

    bool b_st = true;
    bool b_que = true;
    bool b_pq = true;

    while (test--){
        cin >> op >> num;

        if (op == 1){
            st.push(num);
            que.push(num);
            pq.push(num);
        }

        else if (op == 2) {
            if(st.empty() || que.empty() || pq.empty()){
                    b_st = false ;
                    b_que = false;
                    b_pq = false;
            }

            if (b_st){
                a = st.top();
                if (a==num){
                    st.pop();
                }
                else {
                    b_st = false;
                }
            }

            if (b_que){
                a = que.front();
                if (a==num){
                    que.pop();
                }
                else {
                    b_que = false;
                }
            }

            if (b_pq){
                a = pq.top();
                if (a==num){
                    pq.pop();
                }
                else {
                    b_pq = false;
                }
            }

        }


    }

    if (  (b_st && b_pq) || (b_st && b_que) || (b_pq && b_que) ){
        cout << "not sure" << endl;
    }

    else if(b_st){
        cout << "stack" << endl;
    }

    else if(b_que){
        cout << "queue" << endl;
    }

    else if(b_pq){
        cout << "priority queue" << endl;
    }

    else {
        cout << "impossible" << endl;
    }
    }

    return 0;
}
