package acmic;

import java.util.Scanner;

public class Main_15651_N°úM3 {
	static int N;
	static int M;
	static int arr[];
	static int top = 0;
	static StringBuilder sb = new StringBuilder();
	static void f() {
		if(top==M) {
			for(int i=0; i<M; i++) {
				sb.append(arr[i]+" ");
			}
			sb.append("\n");
			return;
		}
		for(int i=1; i<=N; i++) {
			arr[top++] = i;
			f();
			top--;
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		M = s.nextInt();
		arr = new int[M];
		f();
		System.out.println(sb);
	}
}
