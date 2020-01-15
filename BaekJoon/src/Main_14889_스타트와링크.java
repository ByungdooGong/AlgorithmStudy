package acmic;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_14889_스타트와링크 {
	static int N;
	static int dist[][];
	static int visited[];
	static int min = 1000;

	static void f(int cnt) {
		if (cnt > N)
			return;
		if(cnt>=1) {
			int hap1 = 0;
			int hap2 = 0;
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(i==j) continue;
					if(visited[i]==1 && visited[j]==1) {
						hap1 += dist[i][j];
					}
					if(visited[i]==0 && visited[j]==0) {
						hap2 += dist[i][j];
					}
				}
			}
			if(min>Math.abs(hap1-hap2)) {
				min = Math.abs(hap1-hap2);
			}
		}
//		System.out.println(Arrays.toString(visited));
		for (int i = cnt+1; i <= N; i++) {
			visited[i] = 1;
			f(i);
			visited[i] = 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		Scanner s = new Scanner(System.in);
		N = Integer.parseInt(br.readLine());
		dist = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			for (int j = 1; j <= N; j++) {
				dist[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		visited = new int[N + 1];
		f(0);
		System.out.println(min);
	}
}
