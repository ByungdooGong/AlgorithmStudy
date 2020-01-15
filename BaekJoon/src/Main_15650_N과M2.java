package acmic;

import java.util.Scanner;

public class Main_15650_N°úM2 {
	static int N;
	static int M;
	static int arr[];
	static int visited[];
	static int top = 0;
	static void f(int idx) {
		if(top==arr.length) {
			for(int i=0; i<arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			return;
		}
		for(int i=idx+1; i<=N; i++) {
			if(visited[i]==0) {
				visited[i] = 1;
				arr[top++] = i;
				f(i);
				visited[i] = 0;
				top--;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		M = s.nextInt();
		arr = new int[M];
		visited = new int[N+1];
		f(0);
	}
}
