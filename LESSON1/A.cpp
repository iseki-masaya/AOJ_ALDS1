#include <iostream>
#include <vector>
using namespace std;
 
int main(int argc, const char * argv[])
{
    int element;
    cin >> element;
    vector<int> series;
    int input;
    for (int i=0; i<element; i++) {
        cin >> input;
        series.push_back(input);
    }
     
    for (int j=0; j<element; j++){
        if (j != element -1)
            cout << series[j] << " ";
        else
            cout << series[j] << endl;
    }
     
    int pos;
    int value;
    for (int i = 1; i < element; i++) {
        value = series[i];
        pos = i - 1;
        while( i>=0 && series[pos]>value){
            series[pos+1] = series[pos];
            pos = pos - 1;
        }
        series[pos+1] = value;
        for (int j=0; j<element; j++){
            if (j != element -1)
                cout << series[j] << " ";
            else
                cout << series[j] << endl;
        }
    }
    return 0;
}