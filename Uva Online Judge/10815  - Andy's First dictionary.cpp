#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("Output.txt", "w", stdout);

    string inputString;
    vector <string> vec;

    while (cin >> inputString){

        if (inputString == "stop")
            break;
        stringstream ss(inputString);
        string line;

        while (ss >> line){
            size_t prev = 0, pos;

            while ((pos = line.find_first_of("!`~@#$%^&*()_-+=|\][}{'\";:.,/?1234567890\\<>", prev)) !=  string::npos){
                if (pos > prev)
                    vec.push_back(line.substr(prev, pos-prev));
                    prev = pos + 1;
            }
            if (prev < line.length())
                vec.push_back(line.substr(prev, string::npos));
        }
    }
    for (int i=0; i<vec.size(); i++){
        transform(vec[i].begin(), vec[i].end(), vec[i].begin(), ::tolower);
    }

    sort(vec.begin(), vec.end());
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

    for (int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }
    return 0;
}
