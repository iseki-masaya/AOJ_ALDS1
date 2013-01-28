#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main(int argc, const char * argv[])
{
    int i,j;
    int num;
    cin >> num;
    string tmp;
    vector<string> element;
    vector<string> element_sel;
    for(i=0;i<num;i++){
        cin >> tmp;
        element.push_back(tmp);
        element_sel.push_back(tmp);
    }
     
    //bubble sort
    for(i=0;i<num;i++){
        for(j=num-1;j>i;j--){
            if(element[j-1][1]>element[j][1]){
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
    cout << endl << "Stable" <<endl;
    //selection sort
    int minpos;
    bool isChanged = false;
    for(i=0;i<num;i++){
        minpos = i;
        for(j=i+1;j<num;j++){
            if(element_sel[minpos][1]>element_sel[j][1]){
                minpos = j;
                isChanged = true;
            }
        }
        if(isChanged){
            tmp = element_sel[minpos];
            element_sel[minpos] = element_sel[i];
            element_sel[i] = tmp;
            isChanged = false;
        }
    }
 
    bool isBroken = false;
    for(i=0;i<num;i++){
        cout << element_sel[i];
        if(i!=num-1)
            cout << ' ';
        if(element[i][0]!=element_sel[i][0])
            isBroken = true;
    }
    cout << endl;
    if(isBroken)
        cout << "Not stable" << endl;
    else
        cout << "Stable" << endl;
     
    return 0;
}