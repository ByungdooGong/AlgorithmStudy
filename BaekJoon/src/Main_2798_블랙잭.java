package acmic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2798_∫Ì∑¢¿Ë {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, M;
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		str = br.readLine();
		st = new StringTokenizer(str);
		int arr[] = new int[N+1];
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int max = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				for(int k=0; k<N; k++) {
					if(i==k || j==k) continue;
					if(max<arr[i]+arr[j]+arr[k] && arr[i]+arr[j]+arr[k] <=M ) {
						max = arr[i]+arr[j]+arr[k];
					}
				}
			}
		}
		System.out.println(max);
		
	}
}
