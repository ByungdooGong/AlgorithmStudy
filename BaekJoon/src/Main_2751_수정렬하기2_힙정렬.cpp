#include <iostream>
using namespace std;
//힙 정렬(배열 이용)

int arr[1000001];
int N;
int lastIndex = -1;
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void insertMinHeap(int arr[], int num) {
	arr[lastIndex + 1] = num;
	
	int index = lastIndex + 1;
	while (index > 0 && arr[index] < arr[(index - 1) / 2]) {
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
	lastIndex++;
}

void deleteMinHeap(int arr[]) {
	
	cout << arr[0] << "\n";
	arr[0] = arr[lastIndex];
	arr[lastIndex--] = 1000001;

	int index = 0;
	
	while (1) {
		if (index * 2 + 1 > lastIndex)
			break;
		
		if (index * 2 + 1 == lastIndex) {
			if (arr[index * 2 + 1] < arr[index]) {
				swap(arr[index], arr[index * 2 + 1]);
				index = index * 2 + 1;
			}
			break;
		}

		if (arr[index * 2 + 1] < arr[index] || arr[index * 2 + 2] < arr[index]) {
			if (arr[index * 2 + 1] < arr[index * 2 + 2]) {
				swap(arr[index], arr[index * 2 + 1]);
				index = index * 2 + 1;
			}
			else {
				swap(arr[index], arr[index * 2 + 2]);
				index = index * 2 + 2;
			}
		}
		else
			break;
	}
}

int main() {
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		insertMinHeap(arr, tmp);
	}
	while(lastIndex>=0)
		deleteMinHeap(arr);
}