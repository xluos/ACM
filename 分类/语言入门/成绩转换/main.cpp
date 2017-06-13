#include<iostream>
using namespace std;
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int m;
        cin>>m;
        switch(m/10)
        {
            case 10:case 9:cout << "A" << endl;break;
            case 8:cout << "B" << endl;break;
            case 7:cout << "C" << endl;break;
            case 6:cout << "D" << endl;break;
            default:cout << "E" << endl;;break;
        }
    }
    return 0;
}
