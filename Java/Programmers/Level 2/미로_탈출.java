package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class πÃ∑Œ_≈ª√‚ {
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		String[] maps = str.replace("\"", "").replace(",", " ").split(" ");
		
		System.out.println(new Solution().solution(maps));
	}
	
	static class Solution {
	    int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
	    
	    public int solution(String[] maps) {
	        int answer = 0;
	        
	        int switch_row = 0, switch_col = 0, exit_row = 0, exit_col = 0;
	        int N = maps.length, M = maps[0].length();
	        
	        boolean[][] vis = new boolean[N][M];
	        Queue<int[]> Q = new LinkedList<>();
	        for(int i = 0; i < N; i++) {
	            for(int j = 0; j < M; j++) {
	                char c = maps[i].charAt(j);
	                
	                if(c == 'S') {
	                    Q.add(new int[] {i, j, 0});
	                    vis[i][j] = true;
	                }
	                else if(c == 'E') {
	                    exit_row = i;
	                    exit_col = j;
	                }
	                else if(c == 'L') {
	                    switch_row = i;
	                    switch_col = j;
	                }
	            }
	        }
	        
	        while(!Q.isEmpty()) {
	            int[] cur = Q.remove();
	            int row = cur[0], col = cur[1], count = cur[2];
	            
	            if(row == switch_row && col == switch_col) {
	                Q.clear();
	                Q.add(new int[] {row, col, count});
	                vis = new boolean[N][M];
	                vis[row][col] = true;
	                
	                switch_row = -1;
	                switch_col = -1;
	                continue;
	            }
	            
	            if(row == exit_row && col == exit_col) {
	                if(switch_row == -1 && switch_col == -1) return count;
	            }
	            
	            for(int i = 0; i < 4; i++) {
	                int r = row + dx[i];
	                int c = col + dy[i];
	                
	                if(r < 0 || c < 0 || r >= N || c >= M || maps[r].charAt(c) == 'X' || vis[r][c]) continue;
	                
	                Q.add(new int[] {r, c, count + 1});
	                vis[r][c] = true;
	            }
	        }
	        
	        return -1;
	    }
	}
}
