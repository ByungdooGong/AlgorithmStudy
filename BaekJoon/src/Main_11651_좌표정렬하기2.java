package acmic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Pair{
	int x;
	int y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}
public class Main_11651_좌표정렬하기2 {
	static int N;
	static Pair arr[];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new Pair[N];
		for(int k=0; k<N; k++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[k] = new Pair(x, y);
		}
		Arrays.sort(arr, new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				if(o1.y==o2.y) return o1.x-o2.x;
				return o1.y-o2.y;
			}
		});
		for(int i=0; i<N; i++) {
			System.out.println(arr[i].x + " " + arr[i].y);
		}
		
	}
}
