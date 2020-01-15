package acmic;

import java.util.Scanner;

public class Main_1436_¿µÈ­°¨µ¶¼ò {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int cnt = 0;
		here:for(int i=666; ; i++) {
			String str = i+"";
			int flag = 0;
			for(int j=0; j<str.length(); j++) {
				if(str.charAt(j)=='6') {
					if(j==0) continue;
					if(str.charAt(j)!=str.charAt(j-1)) {
						flag = 0;
					}else {
						flag++;
					}
					if(flag==2) {
						cnt++;
						if(cnt==N) {
							System.out.println(str);
							break here;
						}
						break;
					}
				}
			}
		}
	}
}
