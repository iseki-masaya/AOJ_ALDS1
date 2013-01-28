#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
 
using namespace std;
 
/*---------------------------------------------*/
vector<string> split(string str, string delim)
{
    vector<string> result;
    int cutAt;
    while( (cutAt = (int) str.find_first_of(delim)) != str.npos )
    {
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0)
    {
        result.push_back(str);
    }
    return result;
}
int stringToInt(string str){
    int number;
    stringstream ss;
    ss << str;
    ss >> number;
    return number;
}
/*---------------------------------------------*/
 
/*---------------------------------------------*/
//stack???????????????
int stack_get(stack<int> st){
    int ret;
    if(st.empty()){
        cout << "????????????????????????????????§??????";
        return -1;
    }
    ret = st.top();
    return ret;
}
/*---------------------------------------------*/
 
int main(int argc, const char * argv[])
{
    string input;
    getline(cin, input);
    vector<string> inputList = split(input, " ");
     
    int i,buff1,buff2;
    stack<int> st;
    for (i=0; i<inputList.size(); i++) {
        if(inputList[i]=="+" || inputList[i]=="-" || inputList[i]=="*"){
            buff2 = stack_get(st);
            st.pop();
            buff1 = stack_get(st);
            st.pop();
            if(inputList[i]=="+")
                st.push(buff1+buff2);
            else if(inputList[i]=="-")
                st.push(buff1-buff2);
            else
                st.push(buff1*buff2);
        }
        else{
            st.push(stringToInt(inputList[i]));
        }
    }
     
    cout << st.top() << endl;
     
    return 0;
}