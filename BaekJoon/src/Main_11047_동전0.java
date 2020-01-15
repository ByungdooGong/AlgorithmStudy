package acmic;

import java.util.Scanner;

public class Main_11047_µ¿Àü0 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int K= s.nextInt();
		int arr[] = new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = s.nextInt();
		}
		int cnt=0;
		int top = N-1;
		while(K!=0) {
			if(arr[top]<=K) {
				K-=arr[top];
				cnt++;
			}else {
				top--;
			}
		}
		System.out.println(cnt);
	}
}
