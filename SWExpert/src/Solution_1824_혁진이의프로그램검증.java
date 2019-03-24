import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution_1824_혁진이의프로그램검증 {
	static int N;
	static int M;
	static int[][] map;
	static int mem;
	static boolean visited[][][][];
	static int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	static class pair{
		int x;
		int y;
		int m;
		int d;
		pair(int x, int y, int m, int d){
			this.x = x;
			this.y = y;
			this.m = m;
			this.d = d;
		}
	}
	static boolean bfs() {
		Queue<pair> q = new LinkedList<>();
		q.add(new pair(0, 0, 0, 0));
		visited[0][0][0][0] = true;
		while(!q.isEmpty()) {
			pair p = q.poll();
			
			if(map[p.x][p.y]=='@') {
				return true;
			}
			
			if(map[p.x][p.y]=='?') {
				for(int i=0; i<4; i++) {
					int nx = p.x + dir[i][0];
					int ny = p.y + dir[i][1];
					if(nx==N) nx = 0;
					if(ny==M) ny = 0;
					if(nx==-1) nx = N-1;
					if(ny==-1) ny = M-1;
					if(!visited[nx][ny][p.m][i]) {
						q.add(new pair(nx, ny, p.m, i));
						visited[nx][ny][p.m][i] = true;
					}
				}
			}
			if(map[p.x][p.y]>='0' && map[p.x][p.y]<='9') {
				int nx = p.x + dir[p.d][0];
				int ny = p.y + dir[p.d][1];
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				
				if(!visited[nx][ny][map[p.x][p.y]-'0'][p.d]) {
					visited[nx][ny][map[p.x][p.y]-'0'][p.d] = true;
					q.add(new pair(nx, ny, map[p.x][p.y]-'0', p.d));
				}
			}
			if(map[p.x][p.y]=='>') {
				int nx = p.x;
				int ny = p.y + 1;
				int nd = 0;
				if(ny==M) ny = 0;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd]= true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			if(map[p.x][p.y]=='<') {
				int nx = p.x;
				int ny = p.y -1;
				int nd = 2;
				if(ny==-1) ny=M-1;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd] = true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			if(map[p.x][p.y]=='^') {
				int nx = p.x-1;
				int ny = p.y;
				int nd = 3;
				if(nx==-1) nx=N-1;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd] = true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			if(map[p.x][p.y]=='v') {
				int nx = p.x+1;
				int ny = p.y;
				int nd = 1;
				if(nx==N) nx = 0;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd] = true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			if(map[p.x][p.y]=='+') {
				int nx = p.x + dir[p.d][0];
				int ny = p.y + dir[p.d][1];
				int nm = p.m+1;
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				if(nm==16) nm=0;
				if(!visited[nx][ny][nm][p.d]) {
					visited[nx][ny][nm][p.d] = true;
					q.add(new pair(nx, ny, nm, p.d));
				}
			}
			if(map[p.x][p.y]=='-') {
				int nx = p.x + dir[p.d][0];
				int ny = p.y + dir[p.d][1];
				int nm = p.m-1;
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				if(nm==-1) nm=15;
				if(!visited[nx][ny][nm][p.d]) {
					visited[nx][ny][nm][p.d] = true;
					q.add(new pair(nx, ny, nm, p.d));
				}
			}
			if(map[p.x][p.y]=='.') {
				int nx = p.x + dir[p.d][0];
				int ny = p.y + dir[p.d][1];
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				if(!visited[nx][ny][p.m][p.d]) {
					visited[nx][ny][p.m][p.d] = true;
					q.add(new pair(nx, ny, p.m, p.d));
				}
			}
			if(map[p.x][p.y]=='_') {
				int nx = 0;
				int ny = 0;
				int nd = 0;
				if(p.m==0) {
					nd = 0;
					ny = p.y + dir[0][1];
					nx = p.x + dir[0][0];
				}
				else {
					nd = 2;
					nx = p.x + dir[2][0];
					ny = p.y + dir[2][1];
				}
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd] = true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			if(map[p.x][p.y]=='|') {
				int nx = 0;
				int ny = 0;
				int nd = 0;
				if(p.m==0) {
					nd = 1;
					ny = p.y + dir[1][1];
					nx = p.x + dir[1][0];
				}
				else {
					nd = 3;
					nx = p.x + dir[3][0];
					ny = p.y + dir[3][1];
				}
				if(nx==N) nx = 0;
				if(ny==M) ny = 0;
				if(nx==-1) nx = N-1;
				if(ny==-1) ny = M-1;
				if(!visited[nx][ny][p.m][nd]) {
					visited[nx][ny][p.m][nd] = true;
					q.add(new pair(nx, ny, p.m, nd));
				}
			}
			
		}
		return false;
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for(int k=1; k<=tc; k++) {
			N = s.nextInt();
			M = s.nextInt();
			map = new int[N][M];
			for(int i=0; i<N; i++) {
				String str = s.next();
				for(int j=0; j<M; j++) {
					map[i][j] = str.charAt(j);
				}
			}
			visited = new boolean[N][M][16][4];
			if(bfs()) System.out.println("#" + k + " YES");
			else System.out.println("#" + k + " NO");
			
		}
	}
	
	
}