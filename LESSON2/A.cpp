#include <iostream>
using namespace std;
 
int main(int argc, const char * argv[])
{
    int i,j;
    int count=0;
    int num;
    cin >> num;
    int element[num];
    for(i=0;i<num;i++){
        cin >> element[i];
    }
    int tmp;
    for(i=0;i<num;i++){
        for(j=num-1;j>i;j--){
            if(element[j-1]>element[j]){
                count++;
                tmp = element[j];
                element[j] = element[j-1];
                element[j-1] = tmp;
            }
        }
    }
    for(i=0;i<num;i++){
        cout << element[i];
        if(i!=num-1)
            cout << ' ';
    }
    cout << endl << count <<endl;
     
    return 0;
}