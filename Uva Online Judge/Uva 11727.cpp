#include <iostream>
using namespace std;
int main ()
{
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
            int e,f,c,total_em;
            cin>>e>>f>>c;
            total_em=e+f;
            int n=0;


        while(total_em>=c){
                int mod;
            total_em=total_em/c;
            mod=total_em%c;
            if(mod!=0 && mod<c ){
                total_em+=mod;
            }
            n=n+total_em;

        }
        cout<<n<<endl;
    }
    return 0;
}
