#include <bits/stdc++.h>
using namespace std;
int main()
{
    set <string> s;
    set <string> ::iterator it;
    s.insert("Tamim");
    s.insert("Arefin");
    s.insert("Iqbal");
    s.insert("Shakib");
    s.insert("Anik");

    pair <set <string> ::iterator , bool >  p;
    p = s.insert("Neymay");
    if (p.second == false){
        cout << "Can't insert" << endl;
    }
    else {
        cout << "inserted" << endl;
    }


    for (it=s.begin(); it != s.end(); it++){
        cout << *it <<"\t";
    }
}
