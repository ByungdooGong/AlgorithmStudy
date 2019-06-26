import java.util.Arrays;
import java.util.Scanner;

public class Main_1753 {
	static int V;
	static int E;
	static int st;
	static int[][] adj;
	static int[] dp;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		V = s.nextInt();
		E = s.nextInt();
		st = s.nextInt();
		adj = new int[V+1][V+1];
		for(int i=1; i<=V; i++) {
			for(int j=1; j<=V; j++) {
				if(i!=j) {
					adj[i][j] = 9999;
				}
			}
		}
		for(int i=0; i<E; i++) {
			int t1 = s.nextInt();
			int t2 = s.nextInt();
			int t3 = s.nextInt();
			adj[t1][t2] = t3;
		}
		
		dp = new int[V+1];
		for(int i=1; i<=V; i++) {
			dp[i] = adj[1][i];
		}
		for(int i=1; i<=V; i++) {
			for(int j=2; j<=V; j++) {
				dp[j] = Math.min(dp[j], adj[i][j]+dp[i]);
			}
		}
		for(int i=1; i<=V; i++) {
			if(dp[i]==9999)
				System.out.println("INF");
			else
				System.out.println(dp[i]);
		}
		
	}
}
