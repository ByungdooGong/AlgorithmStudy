package acmic;

import java.util.Scanner;

public class Main_2747_피보나치수 {
//	static int fibo(int k) {
//		if(k==1) return 1;
//		else if(k==2) return 1;
//		else
//			return fibo(k-1) + fibo(k-2);
//	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		long  arr[] = new long [50];
		arr[1] = 1;
		arr[2] = 1;
		for(int i=3; i<=n; i++) {
			arr[i] = arr[i-1] + arr[i-2];
		}
		System.out.println(arr[n]);
	}
}
