package acmic;

import java.util.Scanner;

class person{
	int w;
	int h;
	int order = 1;
	person(int w, int h){
		this.w = w;
		this.h = h;
	}
}
public class Main_7568_µ¢Ä¡ {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		person p[] = new person[N+1];
		for(int i=0; i<N; i++) {
			int x = s.nextInt();
			int y = s.nextInt();
			p[i] = new person(x, y);
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				if(p[i].h < p[j].h  && p[i].w < p[j].w) {
					p[i].order++;
				}
			}
		}
		for(int i=0; i<N; i++) {
			System.out.print(p[i].order+" ");
		}
		
	}
}
