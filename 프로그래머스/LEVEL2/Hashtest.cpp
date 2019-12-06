#include <iostream>
#include <map>
#include <iterator>
using namespace std;

/* c++ 에서는 해시를 map, set 같은 걸로 쓰는듯. unordered_map은 집어넣은 순서대로 정렬되어 있고 map 같은 경우는 크기순으로 정렬되어있음.*/
int main() {
	map<string, int> map;

	map["110"] = 4;
	map["8901"] = 1;
	map["1000"] = 5;

	//unordered_map<int, int>::iterator iter;
	/* 숫자같은경우 앞에서 부터 작은순서대로 정렬됨.. 그 숫자가 아무리 크던가 해도 상관없음.*/

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		cout << iter->first.c_str() << endl;
	}

}