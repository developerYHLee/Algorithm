package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 혼자서_하는_틱택토 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] board = new String[3];
		for(int i = 0; i < 3; i++) board[i] = br.readLine();
		
		System.out.println(new Solution().solution(board));
	}
	
	static class Solution {
	    public int solution(String[] board) {
	        int count_O = 0, count_X = 0;
	        for(int i = 0; i < 3; i++) {
	            for(int j = 0; j < 3; j++) {
	                if(board[i].charAt(j) == 'O') count_O++;
	                else if(board[i].charAt(j) == 'X') count_X++;
	            }
	        }
	        
	        if(count_O == count_X || count_O == count_X + 1) {
	            //X 하나만 승리해야 1
	            if(count_O == count_X && solve(board, 'O') == 0) return 0;
	            //O 하나만 승리해야 1
	            else if(count_O == count_X + 1 && solve(board, 'X') == 0) return 0; 
	            
	            return 1;
	        }
	        
	        return 0;
	    }
	    
	    int check(String str) {
	        char c = str.charAt(0);
	        
	        if(c == '.') return 1;
	        
	        for(int i = 1; i < 3; i++) if(c != str.charAt(i)) return 1;
	        
	        return 0;
	    }
	    
	    int solve(String[] board, char c) {
	        for(int i = 0; i < 3; i++) {
	            if(check(board[i]) == 0) {
	                if(board[i].charAt(0) == c) return 0;
	            }
	                
	            String new_str = "";
	            for(int j = 0; j < 3; j++) new_str += board[j].charAt(i);
	           
	            if(check(new_str) == 0) {
	                if(new_str.charAt(0) == c) return 0;
	            }
	        }
	        
	            
	        String new_str1 = "", new_str2 = "";
	        for(int i = 0; i < 3; i++) {
	            new_str1 += board[i].charAt(i);
	            new_str2 += board[i].charAt(2 - i);
	        }
	        
	        if(check(new_str1) == 0) {
	            if(new_str1.charAt(0) == c) return 0;
	        }
	        if(check(new_str2) == 0) {
	            if(new_str2.charAt(0) == c) return 0;
	        }
	        
	        return 1;
	    }
	}
}
