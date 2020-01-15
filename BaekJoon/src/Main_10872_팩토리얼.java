package acmic;

import java.util.Scanner;

public class Main_10872_ÆÑÅä¸®¾ó {
	static long f(int n) {
		if(n==1) {
			return 1;
		}
		if(n==0)
			return 1;
		return n*f(n-1);
	}
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		System.out.println(f(n));
	}
}
