#include <iostream>
#include <vector>
using namespace std;
 
bool isPrime(int n){
    if(n<2)
        return false;
    else if(n==2)
        return true;
     
    if(n%2==0)
        return false;
     
    for (int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return false;
     
    return true;
     
         
}
 
int main(int argc, const char * argv[])
{
    int n,i;
    cin >> n;
    int tmp;
    vector<int> input;
    for(i=0;i<n;i++){
        cin >> tmp;
        input.push_back(tmp);
    }
    int count=0;
    for (i=0; i<n; i++) {
        if(isPrime(input[i]))
            count++;
    }
    cout << count << endl;
     
    return 0;
}