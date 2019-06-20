import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main_2247 {
	static class pair {
		int x;
		int y;
		pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int N;
	static pair[] arr;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		arr = new pair[N]; 
		for(int i=0; i<N; i++) {
			arr[i] = new pair(s.nextInt(), s.nextInt());
		}
		Arrays.sort(arr, new Comparator<pair>() {
			@Override
			public int compare(pair o1, pair o2) {
				return o1.y-o2.y;
			}
		});
		int st=0;
		int end=0;
		int max = 0;
		
		
		ArrayList<pair> al = new ArrayList<>();
		al.add(new pair(arr[0].x, arr[0].y));
		int idx = 1;
		while(idx<N) {
			boolean flag = false;
			for(int i=0; i<al.size(); i++) {
				if(!(al.get(i).y<arr[idx].x)) {
					al.get(i).x = Math.min(al.get(i).x, arr[idx].x);
					al.get(i).y = Math.max(al.get(i).y, arr[idx].y);
					flag = true;
				}
			}
			if(!flag) {
				al.add(new pair(arr[idx].x, arr[idx].y));
			}
			idx++;
		}
		int max2 = 0;
		for(int i=0; i<al.size(); i++) {
			st = al.get(i).x;
			end = al.get(i).y;
			for(int j=i+1; j<al.size(); j++) {
				if(end<al.get(j).x) {
					if(max2<al.get(j).x-end) {
						max2 = al.get(j).x-end;
					}
					break;
				}else {
					end = al.get(j).y;
				}
			}
			if(max<end-st) {
				max = end-st;
			}
		}
		
		
		System.out.println(max + " " + max2);
	}	
}
