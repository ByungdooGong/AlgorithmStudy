package acmic;

import java.util.Scanner;

public class Main_15652_N°úM4 {
	static int N;
	static int M;
	static int arr[];
	static int top = 0;
	static StringBuilder sb = new StringBuilder();
	static void f(int idx) {
		if(top==M) {
			for(int i=0; i<M; i++) {
				sb.append(arr[i]+" ");
			}
			sb.append("\n");
			return;
		}
		for(int i=idx; i<=N; i++) {
			arr[top++] = i;
			f(i);
			top--;
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		M = s.nextInt();
		arr = new int[M];
		f(1);
		System.out.println(sb);
	}
}
