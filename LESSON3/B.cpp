#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
 
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
 
int main(int argc, const char * argv[])
{
    int i;
    int num,cost;
    queue<pair<string,int> > q;
    cin >> num;
    cin >> cost;
     
    string name;
    int time;
    for(i=0;i<num;i++){
        cin >> name;
        cin >> time;
        q.push(pair<string,int>(name,time));
    }
     
    int sum=0;
    vector<pair<string,int> > result;
    while(!q.empty()){
        name = q.front().first;
        time = q.front().second;
        if(time>cost){
            time -= cost;
            sum += cost;
            q.pop();
            q.push(make_pair(name, time));
        }
        else{
            sum += time;
            q.pop();
            result.push_back(make_pair(name, sum));
        }
    }
     
    for(i=0;i<result.size();i++){
        cout << result[i].first << " " << result[i].second << endl;
    }
     
    return 0;
}