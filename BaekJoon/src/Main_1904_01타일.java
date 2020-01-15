package acmic;

import java.util.Scanner;

public class Main_1904_01≈∏¿œ {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int dp[] = new int[1000001];
		dp[1] = 1;
		dp[2] = 2;
		for(int i=3; i<=N; i++) {
			dp[i] = (dp[i-1] + dp[i-2])%15746;
		}
		System.out.println(dp[N]);
	}
}
