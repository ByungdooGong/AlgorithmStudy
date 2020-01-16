package acmic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class adj2 implements Comparable<adj2>{
	int x;
	int y;
	int dist;
	adj2(int x, int y, int dist){
		this.x = x;
		this.y = y;
		this.dist = dist;
	}
	@Override
	public int compareTo(adj2 o) {
		return this.dist-o.dist;
	}
}
public class Main_1647_도시분할계획 {
	static int N;
	static int M;
	static Queue<adj2> pq;
	static int p[];
	static int rank[];
	static int findParent(int i) {
		if(p[i]==i) return p[i]=i;
		else return p[i]=findParent(p[i]);
	}
	static void union(int x, int y) {
		int px = findParent(x);
		int py = findParent(y);
		
		if(px==py) return;
		p[py] = px;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		pq = new PriorityQueue<adj2>();
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			pq.add(new adj2(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		p = new int[N+1];
		int hap = 0;
		int cnt = 0;
		for(int i=1; i<=N; i++) {
			p[i] = i;
		}
		for(int i=0; i<M; i++) {
			adj2 A = pq.poll();
			if(findParent(A.x)==findParent(A.y)) {
				continue;
			}
			union(A.x, A.y);
			hap+=A.dist;
			cnt++;
			if(cnt==N-2) break;
		}
		System.out.println(hap);
	}
}
