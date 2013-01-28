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
    int minpos,tmp;
    bool isChanged = false;
    for(i=0;i<num;i++){
        minpos = i;
        for(j=i+1;j<num;j++){
            if(element[minpos]>element[j]){
                minpos = j;
                isChanged = true;
            }
        }
        if(isChanged){
            tmp = element[minpos];
            element[minpos] = element[i];
            element[i] = tmp;
            count++;
            isChanged = false;
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