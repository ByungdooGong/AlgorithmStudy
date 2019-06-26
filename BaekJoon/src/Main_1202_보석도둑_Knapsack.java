import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1202 {
	static class pair implements Comparable<pair>{
		int x;
		int y;
		pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(pair o) {
			if(this.x==o.x) {
				return this.y-o.y;
			}
			return this.x-o.x;
		}
	}
	
	public static void main(String[] args) throws Exception {
		int n, k;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		pair[] m = new pair[n];
		int[] c = new int[k];
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			m[i] = new pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		for(int i=0; i<k; i++) {
			c[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(m);
		Arrays.sort(c);
		
		long hap = 0;
		Queue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
		for(int j=0, i=0; j<k; j++) {
			while(i<n && m[i].x<=c[j]) {
				q.add(m[i++].y);
			}
			if(!q.isEmpty()) {
				hap+=q.poll();
			}
		}
		System.out.println(hap);
	}
}
