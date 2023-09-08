package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B17144 { //미세먼지 안녕!
	static int R, C, T; //R : row, C : col, T : 초
	static int[] air_cleaner = new int[2];
	static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	static Node[][] map;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		int air_cleaner_index = 0;
		map = new Node[R][C];
		for(int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j = 0; j < C; j++) {
				map[i][j] = new Node();
				map[i][j].set_dust(Integer.parseInt(st.nextToken()));
				
				if(map[i][j].get_dust() == -1) air_cleaner[air_cleaner_index++] = i;
			}
		}

		while(T-- > 0) {
			spread();	
			move();
		}
		
		int ans = 2; //공기 청정기에서 -1이 두번 되는 것을 고려
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				ans += map[i][j].get_dust();
			}
		}
		
		System.out.println(ans);
	}
	
	static void print_dust() {
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) System.out.print(map[i][j].get_dust() + " ");
			System.out.println();
		}
	}
	
	static void move() {
		move_left();
		move_right();
		move_up();
		move_down();
		finish_move();
	}
	
	static void move_left() {
		for(int i = C - 1; i > 0; i--) {
			int dust = map[0][i].get_dust();
			map[0][i].set_dust(-dust);
			map[0][i - 1].moved(dust);
			
			dust = map[R - 1][i].get_dust();
			map[R - 1][i].set_dust(-dust);
			map[R - 1][i - 1].moved(dust);
		}
	}
	
	static void move_right() {
		for(int i = 1; i < C - 1; i++) {
			int dust = map[air_cleaner[0]][i].get_dust();
			map[air_cleaner[0]][i].set_dust(-dust);
			map[air_cleaner[0]][i + 1].moved(dust);
			
			dust = map[air_cleaner[1]][i].get_dust();
			map[air_cleaner[1]][i].set_dust(-dust);
			map[air_cleaner[1]][i + 1].moved(dust);
		}
	}
	
	static void move_up() {
		for(int i = R - 1; i > air_cleaner[1]; i--) {
			int dust = map[i][0].get_dust();
			map[i][0].set_dust(-dust);
			map[i - 1][0].moved(dust);
		}
		
		map[air_cleaner[1]][0].reset();
		
		for(int i = air_cleaner[0]; i > 0; i--) {
			int dust = map[i][C - 1].get_dust();
			map[i][C - 1].set_dust(-dust);
			map[i - 1][C - 1].moved(dust);
		}
	}
	
	static void move_down() {
		for(int i = 0; i < air_cleaner[0]; i++) {
			int dust = map[i][0].get_dust();
			map[i][0].set_dust(-dust);
			map[i + 1][0].moved(dust);
		}
		
		map[air_cleaner[0]][0].reset();
		
		for(int i = air_cleaner[1]; i < R - 1; i++) {
			int dust = map[i][C - 1].get_dust();
			map[i][C - 1].set_dust(-dust);
			map[i + 1][C - 1].moved(dust);
		}
	}

	static void finish_move() {
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) map[i][j].after_move();
		}
	}
	
	static void spread() {
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(map[i][j].get_dust() < 5) continue;
				
				int num = map[i][j].get_dust() / 5;
				for(int k = 0; k < 4; k++) {
					int r = i + dx[k];
					int c = j + dy[k];
					
					if(r < 0 || c < 0 || r >= R || c >= C || map[r][c].get_dust() == -1) continue;
					
					map[r][c].moved(num);
					map[i][j].set_dust(-num);
				}
			}
		}
		
		finish_move();
	}
	
	static class Node {
		private int dust = 0, add_dust = 0;
		
		void set_dust(int num) {
			dust += num;
		}
		
		int get_dust() { return dust; }
		
		void after_move() {
			dust += add_dust;
			add_dust = 0;
		}
		
		void moved(int num) {
			add_dust += num;
		}
		
		void reset() {
			add_dust = 0;
		}
	}
}