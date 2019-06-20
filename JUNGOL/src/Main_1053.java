import java.util.Scanner;

public class Main_1053 {
	static class matrix{
		long a;
		long b;
		long c;
		long d;
		matrix(long a, long b, long c, long d){
			this.a = a;
			this.b = b;
			this.c = c;
			this.d = d;
		}
	}
	
	static matrix f(matrix m, long n) {
		if(n==1) {
			return new matrix(m.a, m.b, m.c, m.d);
		}
		
		long a=0, b=0, c=0, d=0;
		a = (m.a*m.a)%10000 + (m.b*m.c)%10000;
		b = (m.a*m.b)%10000 + (m.b*m.d)%10000;
		c = (m.a*m.c)%10000 + (m.c*m.d)%10000;
		d = (m.b*m.c)%10000 + (m.d*m.d)%10000;
		if(n%2==0) {
			return f(new matrix(a, b, c, d), n/2);
		}else {
			matrix nm = f(new matrix(a, b, c, d), n/2);
			a = (nm.a*m.a)%10000 + (nm.b*m.c)%10000;
			b = (nm.a*m.b)%10000 + (nm.b*m.d)%10000;
			c = (nm.c*m.a)%10000 + (nm.d*m.c)%10000;
			d = (nm.c*m.b)%10000 + (nm.d*m.d)%10000;
			return new matrix(a, b, c, d);
		}
		
	}
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while(true) {
			long t = s.nextLong();
			if(t==-1) {
				return;
			}
			if(t==0) {
				System.out.println(0);
				continue;
			}
			System.out.println(f(new matrix(1, 1, 1, 0), t).b%10000);
		}
	}
}
