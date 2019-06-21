#include <iostream>
using namespace std;

int n;
int arr[1000001];
int* arr2;
void merge(int left, int right) {
	
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i<=mid && j<=right) {
		if (arr[i] < arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		arr2[k++] = arr[i++];
	}
	while (j <= right) {
		arr2[k++] = arr[j++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}

}

void partition(int left, int right) {

	int mid = (left + right) / 2;
	if (left < right) {
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr2 = new int[n];

	//mergesort
	partition(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	//endl쓰면 시간초과 뜸;;;;;;;;;
}

