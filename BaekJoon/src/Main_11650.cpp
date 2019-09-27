#include <iostream>
using namespace std;

int N;
pair<int, int> point[100001];

void swap(pair<int, int> &a, pair<int, int> &b) {
	pair<int, int> tmp;
	tmp.first = a.first;
	tmp.second = a.second;
	a.first = b.first;
	a.second = b.second;
	b.first = tmp.first;
	b.second = tmp.second;
}

void quickSort(int st, int end)
{
	if (st >= end) return;
	int pivot = (st + end) / 2;
	int i = st;
	int j = st;
	while (i <= end) {
		if (point[i].first < point[pivot].first) {
			if (j==pivot) {
				pivot = i;
			}
			swap(point[i], point[j++]);
		}
		else if (point[i].first == point[pivot].first) {
			if (point[i].second < point[pivot].second) {
				if (j==pivot) {
					pivot = i;
				}
				swap(point[i], point[j++]);
			}
		}
		i++;
	}
	swap(point[pivot], point[j]);
	quickSort(st, j - 1);
	quickSort(j + 1, end);

}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> point[i].first >> point[i].second;
	}
	
	quickSort(0, N-1);
	for (int i = 0; i < N; i++) {
		cout << point[i].first << " " << point[i].second << '\n';
	}
	
}
