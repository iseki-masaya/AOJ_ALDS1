#include <iostream>
#include <string>
#include <vector>

using namespace std;

class doubleHash{
public:
	int hashSize1;
	int hashSize2;
	int collision;
	
	vector<string> hashTable;
	
	doubleHash(){
		int i=0;
		hashSize1 = 2500003;
		collision = 0;
		for(i=0;i<hashSize1;i++){
			hashTable.push_back("");
		}
	};
	
	int		getChar(char ch);
	int	getWordNum(string str);
	int getWordNum2(string str);
	bool	insert(string str);
	bool	find(string str);
};

int doubleHash::getChar(char ch){
	if(ch=='A') return 17;
	else if(ch=='C') return 73;
	else if(ch=='G') return 269;
	else if(ch=='T') return 401;
	return 0;
}

int doubleHash::getWordNum(string str){
	int sum=0,p=1;
	int i;
	
	for(i=0;i<str.size();i++){
		sum += p*(getChar(str[i]));
		p *= 2;
	}
	return sum;
}

int doubleHash::getWordNum2(string str){
	int sum=0,p=2;
	int i;
	
	for(i=0;i<str.size();i++){
		sum += p*(getChar(str[i]));
		p += 6;
	}
	return sum;
}

bool doubleHash::insert(string str){
	int wordNum = getWordNum(str);
	int step = getWordNum2(str);
	int count = wordNum;
	while(hashTable[count] != ""){
		if(count>hashSize1)
			count -= hashSize1;
		collision++;
		count += step;
	}
	hashTable[count] = str;
	return true;
}

bool doubleHash::find(string str){
	int wordNum = getWordNum(str);
	int step = getWordNum2(str);
	int count = wordNum;
	while(hashTable[count] != str){
		if(count>hashSize1)
			count -= hashSize1;
		if(hashTable[count]=="")
			return false;
		count += step;
	}
	return true;
}


int main(int argc, const char * argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	doubleHash hash;	
	vector<bool> result;

	int i;
	int num=0;
	string operation;
	string word;
	cin >> num;

	for(i=0;i<num;i++){
		cin >> operation;
		cin >> word;
		
		if(operation=="insert"){
			hash.insert(word);
		}
		else{
			if(hash.find(word))
				result.push_back(true);
			else
				result.push_back(false);
		}
	}
	
	for(i=0;i<result.size();i++){
		if (result[i])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
    return 0;
}

