#include <iostream>
using namespace std;

int arr[20];
int N;

void swap(int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void quickSort(int st, int end) {
	if (st>=end) {
		return;
	}
	int pivot = (st + end) / 2;
	int i = st;
	int j = st;
	while (i <= end) {
		if (i == pivot) {
			i++;
			continue;
		}
		if (arr[i] > arr[pivot]) {
			if (pivot == j) {
				pivot = i;
			}
			swap(i, j++);
		}
		i++;
	}
	swap(pivot, j);
	quickSort(st, j - 1);
	quickSort(j + 1, end);
}

int main() {
	int input;
	cin >> input;
	int idx = 0;
	while (input > 0) {
		arr[idx++] = input % 10;
		input /= 10;
	}
	N = idx;
	
	quickSort(0, N);

	for (int i = 0; i < N; i++) {
		cout << arr[i];
	}
}
