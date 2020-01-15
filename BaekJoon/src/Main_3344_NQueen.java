package acmic;

import java.util.Scanner;

public class Main_3344_NQueen {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int[] even = new int[N];
		int[] odd = new int[N];
		int x = 0;
		int y = 0;
		for (int i = 1; i <= N; i++) {
			if (i % 2 == 0) {
				even[x++] = i;
			} else {
				odd[y++] = i;
			}
		}
		if(N%6==2) {
			odd[0] = 3;
			odd[1] = 1;
			odd[2] = 0;
			odd[y++] = 5;
		}
		if(N%6==3) {
			even[0] = 0;
			even[x++] = 2;
			odd[0] = 0;
			odd[1] = 0;
			odd[y++] = 1;
			odd[y++] = 3;
		}
		for(int i=0; i<x; i++) {
			if(even[i]!=0)
				System.out.println(even[i]);
		}
		for(int i=0; i<y; i++) {
			if(odd[i]!=0) {
				System.out.println(odd[i]);
			}
		}
	}
}
