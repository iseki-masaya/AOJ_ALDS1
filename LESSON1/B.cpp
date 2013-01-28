#include <iostream>
using namespace std;
 
int main(int argc, const char * argv[])
{
    int x,y,tmp;
    cin >> x >> y;
    if(x<y){
        tmp=x;
        x=y;
        y=tmp;
    }
 
    while (y!=0) {
        tmp = y;
        y = x%y;
        x = tmp;
    }
     
    cout << x << endl;
    return 0;
}