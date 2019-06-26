//cin, cout은 시간이 오래걸림. 자꾸 timeout 뜰때 scanf, printf 활용
#include <iostream>
using namespace std;

int N;
int arr[10001];

int main() {
	scanf("%d", &N);
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		arr[input]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while(arr[i]--){
			printf("%d\n",i);
		}
	}
}