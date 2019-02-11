#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("Output.txt", "w", stdout);
    std::string binder;
    int t;

    //cin>> binder;
    cin >> t;
    while(t--)
    {
        int m, n, b;
        getchar();
        getline(cin, binder);
        cin >> m >> n >> b;

        map<string,int> ingred;
        multimap<int, string> res;
        vector<pair<int, string> >::iterator it;
        vector<pair<int, string> > vec;


        //Loop for mth ingredient item
        for(int i=0; i<m; i++)
        {
            string a;
            int aa;
            cin >> a >> aa;
            ingred.insert(pair<string,int>(a, aa));
        }

        //Loop for nth recipe
        for (int i=0; i<n; i++)
        {
            string rec_name;
            int req_item, cost=0;
            getchar();
            getline(cin, rec_name);
            cin >> req_item;
            for(int i=0; i<req_item; i++)
            {
                string a;
                int aa;
                cin>>a >> aa;
                cost += (ingred[a]*aa);
            }
            if (b>=cost)
            {
                //res.insert(pair<int, string>(cost, rec_name));
                vec.push_back(make_pair(cost, rec_name));
            }
        }
        //transform(x1.begin(), x1.end(), x1.begin(), ::toupper);
        transform(binder.begin(), binder.end(), binder.begin(), ::toupper);
        cout << binder << endl;

        sort(vec.begin(), vec.end());

        if (vec.empty()==true)
        {
            cout << "Too expensive!" <<endl;
        }
        else
        {
            for (it=vec.begin(); it!=vec.end(); it++)
            {
                cout<< it->second << endl;
            }
        }
        cout << endl;
    }


    return 0;
}

