#include <iostream>
using namespace std;

int arr[10000001];

void swap(int *a, int* b) {
	int *tmp = a;
	*a = *b;
	*b = *tmp;
}
void f(int pivot, int left, int right) {
	if (left > right) {
		return;
	}

	int j = pivot + 1;
	for (int i = left; i <= right; i++) {
		if (arr[i] < arr[pivot]) {
			swap(arr[i], arr[j]);
			j++;
		}
	}
	swap(arr[j - 1], arr[pivot]);
	pivot = j - 1;

	f(left, left, pivot - 1);
	f(pivot + 1, pivot + 1, right);
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	f(0, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
