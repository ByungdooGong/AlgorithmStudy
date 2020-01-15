package acmic;

import java.util.Scanner;

public class Main_10870_피보나치수5 {
	static int fibo(int n) {
		if(n==0) return 0;
		else if(n==1 || n==2) return 1;
		else {
			return fibo(n-1)+fibo(n-2);
		}
	}
	public static void main(String[] args) {
		//Scanner s = new Scanner(System.in);
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		System.out.println(fibo(n));
		
	}
}
