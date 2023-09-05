package Programmers;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class 숫자_변환하기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		int n = sc.nextInt();
		
		System.out.println(new Solution().solution(x, y, n));
	}
	
	static class Solution {
	    int[] dx = {2, 3};
	    boolean[] vis;
	    Queue<int[]> Q;
	    
	    public int solution(int x, int y, int n) {
	        vis = new boolean[y + 1];
	        Q = new LinkedList<>();
	        Q.add(new int[] {x, 0});
	        
	        while(!Q.isEmpty()) {
	            int[] cur = Q.remove();
	            int cur_x = cur[0], count = cur[1];
	            
	            if(cur_x == y) return count;
	            
	            for(int i = 0; i < 2; i++) {
	                int num = cur_x * dx[i];
	                
	                check(num, y, count);
	            }
	            
	            int num = cur_x + n;
	            check(num, y, count);
	        }
	        
	        return -1;
	    }
	    
	    void check(int num, int y, int count) {
	        if(num > y || vis[num]) return;
	        vis[num] = true;
	        Q.add(new int[] {num, count + 1});
	    }
	}
}
