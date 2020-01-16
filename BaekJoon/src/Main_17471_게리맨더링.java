package acmic;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main_17471_게리맨더링 {
	static int N;
	static int arr[];
	static int adj[][];
	static int p[];
	static boolean flag = false;
	static int min = Integer.MAX_VALUE;
	static int rank[];
	
	static int findParent(int i) {
		if(p[i]==i) return i;
		else return p[i] = findParent(p[i]);
	}
	
	static void union(int x, int y) {
		int px = findParent(x);
		int py = findParent(y);
		
		if(px==py) return;
		if(rank[px]>rank[py]) p[py] = px;
		else if(rank[px]==rank[py]) {
			rank[px]++;
			p[py] = px;
		}else
			p[px] = py;
	}
	// 비트마스킹
	static void f() {
		here: for (int i = 1; i < (1 << N)-1; i++) {
			ArrayList<Integer> group1 = new ArrayList<>();
			ArrayList<Integer> group0 = new ArrayList<>();
			int hap1 = 0;
			int hap0 = 0;
			
			for (int j = 0; j < N; j++) {
				if ((i & (1 << j)) == (1 << j)) { // 1그룹
					group1.add(j + 1);
					hap1 += arr[j + 1];
				} else { // 0그룹
					group0.add(j + 1);
					hap0 += arr[j + 1];
				}
			}
			for(int j=1; j<=N; j++) p[j] = j;
			rank = new int[N+1];
			for(int j=1; j<=N; j++) {
				for(int p=1; p<=N; p++) {
					if(adj[j][p]==1) {
						int fg = 0;
						for(int k=0; k<group1.size(); k++) {
							if(group1.get(k)==j || group1.get(k)==p) {
								fg++;
							}
							if(fg==2)	union(j, p);
						}
						fg = 0;
						for(int k=0; k<group0.size(); k++) {
							if(group0.get(k)==j || group0.get(k)==p) {
								fg++;
							}
							if(fg==2) union(j, p);
						}
					}
				}
			}
			for(int j=1; j<group1.size(); j++) {
				if(findParent(group1.get(j))!=findParent(group1.get(j-1)) ) {
					continue here;
				}
			}
			for(int j=1; j<group0.size(); j++) {
				if(findParent(group0.get(j))!=findParent(group0.get(j-1)) ) {
					continue here;
				}
			}
			
//			System.out.println(group1 + " " + group0);
			if (Math.abs(hap1 - hap0) < min) {
				min = Math.abs(hap1 - hap0);
				flag = true;
			}
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		arr = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			arr[i] = s.nextInt();
		}
		adj = new int[N + 1][N+1];
		p = new int[N+1];
		
		for (int i = 1; i <= N; i++) {
			int n = s.nextInt();
			for (int j = 0; j < n; j++) {
				int tmp = s.nextInt();
				adj[i][tmp] = adj[tmp][i] = 1;
			}
		}
		f();
		if(!flag) System.out.println(-1);
		else System.out.println(min);
	}
}
