#include <iostream>
#include <string>
#include <istream>
using namespace std;

string arr[1000010];
string test[1000010];
int N;
int M;

int vector[10000003];
int mod = 10000003;
int input[1000010];
int output[1000010];

int main() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int idx = 0;
	for (int i = 0; i < 1000010; i++) {
		if (str1[i] == ' ') {
			idx++;
			continue;
		}
		else if (str1[i] == '$') {
			N = idx;
			break;
		}
		arr[idx] += str1[i];
	}
	idx = 0;
	for (int i = 0; i < 1000010; i++) {
		if (str2[i] == ' ') {
			idx++;
			continue;
		}
		else if (str2[i] == '$') {
			M = idx;
			break;
		}
		test[idx] += str2[i];
	}
	
	for (int i = 0; i < M; i++) {
		cout << test[i] << " ";
	}
	/*
	idx = 0;
	for (int i = 0; i < 100001; i++) {
		if (b[i] == ' ') {
			idx++;
			continue;
		}
		else if (b[i] == '$') {
			break;
		}
		test[idx] += b[i];
	}
	for (int i = 0; i < 12; i++) {
		cout << b[i] << " ";
	}*/
	/*string tmp;
	for (int i = 0; ; i++) {
		cin >> tmp;
		if (tmp[0] == '$') {
			N = i;
			break;
		}
		else {
			arr[i] = tmp;
		}
	}
	for (int i = 0; ; i++) {
		cin >> tmp;
		if (tmp[0] == '$') {
			M = i;
			break;
		}
		else {
			test[i] = tmp;
		}
	}
	int idx = 1;
	for (int i = 0; i < M; i++) {
		int hash = test[i][0]-'a';
		int d = 1;
		for (int j = 1; j < test[i].size(); j++) {
			hash *= 29;
			hash %= mod;
			hash += (test[i][j]-'a');
			hash %= mod;
			d *= 29;
			d %= mod;
		}
		if (vector[hash] != 0) {
			output[i] = vector[hash];
			continue;
		}
		vector[hash] = idx;
		output[i] = idx++;
	}
	
	int ans = 0;
	idx = 1;
	for (int i = 0; i < mod; i++) {
		vector[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int hash = arr[i][0] - 'a';
		int d = 1;
		for (int j = 1; j < arr[i].size(); j++) {
			hash *= 29;
			hash %= mod;
			hash += (arr[i][j] - 'a');
			hash %= mod;
			d *= 29;
			d %= mod;
		}
		if (vector[hash] != 0) {
			input[i] = vector[hash];
			continue;
		}
		vector[hash] = idx;
		input[i] = idx++;
	}
	int cnt = 1;
	if (M == 1) {
		ans = 1;
	}
	else {
		for (int i = 0; i <= N - M; i++) {
			cnt = 1;
			for (int j = 0; j + 1 < M; j++) {
				if ((input[i + j] - output[j]) == (input[i + j + 1] - output[j + 1])) {
					cnt++;
				}
				else {
					break;
				}
				if (cnt == M) {
					ans = i + 1;
					break;
				}
			}
			if (cnt == M) {
				break;
			}

		}
	}
	cout << ans;*/
	return 0;
}