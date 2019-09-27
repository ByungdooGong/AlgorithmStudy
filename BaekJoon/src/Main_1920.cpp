#include <iostream> 
#include <cstdio>
using namespace std;

int N;
int M;
int mod = 1007;
int p = 29;

int vec[1007][400];
int coun[1007];

int hashkey(int num) {
	//num = num < 0 ? -num : num;
	int hap = num % 10;
	int temp = num;
	while (temp > 0) {
		hap *= p;
		temp /= 10;
		hap += (temp % 10);
	}
	hap = (hap < 0) ? -hap : hap;
	hap %= mod;
	return hap;
}

int main() {
	// int a = -12314;
	// cout << hashkey(a);
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		// scanf("%d", &tmp);
		tmp = 1;
		int temp = hashkey(tmp);
		vec[temp][coun[temp]] = tmp;
		coun[temp]++;
	}

	scanf("%d", &M);
	int tmp2;
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp2);
		int temp = hashkey(tmp2);
		if (coun[temp] > 0) {
			int flag = 0;
			for (int j = 0; j < coun[temp]; j++) {
				if (tmp2 == vec[temp][j]) {
					printf("1\n");
					//cout << 1 << '\n';
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("0\n");
				//cout << 0 << '\n';
			}
		}
		else {
			printf("0\n");
			//cout << 0 << '\n';
		}
	}
	printf("%d", vec[hashkey(1) + 1][0]);
}