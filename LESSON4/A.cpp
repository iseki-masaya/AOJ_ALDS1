#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	
	int i,j;
	int tmp;
	int count = 0;
	int firstNum,secondNum;
	vector<int> firstInput,secondInput,matchList;
	
	//データの入力
	cin >> firstNum;
	for(i=0;i<firstNum;i++){
		cin >> tmp;
		firstInput.push_back(tmp);
	}
	cin >> secondNum;
	for(i=0;i<secondNum;i++){
		cin >> tmp;
		secondInput.push_back(tmp);
	}
	
	//重複している部分をまとめる。
	sort(firstInput.begin(),firstInput.end());
	firstInput.erase(unique(firstInput.begin(),firstInput.end()),firstInput.end());
	sort(secondInput.begin(), secondInput.end());
	secondInput.erase(unique(secondInput.begin(), secondInput.end()),secondInput.end());
	
	//要素数を更新する
	firstNum = (int)firstInput.size();
	secondNum = (int)secondInput.size();
	
	int first,second;
	for(i=0;i<firstNum;i++){
		for(j=0;j<secondNum;j++){
			first = firstInput[i];
			second = secondInput[j];
			if(first==second){
				count++;
				break;
			}
			else if(first<second){
				break;
			}
		}
	}
	
	cout << count << endl;
    return 0;
}

