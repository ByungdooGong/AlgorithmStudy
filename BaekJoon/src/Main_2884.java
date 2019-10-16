import java.util.Scanner;

public class Main_2884 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int h, m;
		h = s.nextInt();
		m = s.nextInt();
		m = m - 45;
		if(m<0) {
			m += 60;
			h--;
		}
		if(h<0) {
			h+=24;
		}
		System.out.println(h + " " + m);		
	}
}
