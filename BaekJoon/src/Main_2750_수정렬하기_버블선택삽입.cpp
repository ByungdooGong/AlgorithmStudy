#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//buble sort
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}*/

	//selection sort(한번 루프 돌때마다 제일 작은거 찾아서 제일 앞으로 둠)
	/*for (int i = 0; i < N; i++) {
		int min = 9999;
		int idx = -1;
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j] && arr[j]<min) {
				min = arr[j];
				idx = j;
			}
		}
		if (idx != -1) {
			int tmp = arr[i];
			arr[i] = min;
			arr[idx] = tmp;
		}
	}*/
	//insertion sort(한번 루프돌때 자기자신이 들어갈 위치에 삽입)
	for (int i = 1; i < N; i++) {
		int idx = -1;
		int tmp = -1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				idx = j;
				tmp = arr[i];
				break;
			}
		}
		if (idx == -1) continue;
		for (int j = i; j > idx; j--) {
			arr[j] = arr[j - 1];
		}
		arr[idx] = tmp;
		
	}



	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

}