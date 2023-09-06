package Programmers;

import java.util.Scanner;

public class 마법의_엘리베이터 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println(new Solution().solution(sc.nextInt()));
	}
	
	static class Solution {
	    public int solution(int storey) {
	        int answer = 0;
	        
	        while(storey > 0) {
	            int num = storey % 10;
	            storey /= 10;
	            
	            if((num > 5) || (num == 5 && storey % 10 >= 5))  {
	                storey++;
	                num = 10 - num;
	            }
	            
	            answer += num;
	        }
	        
	        return answer;
	    }
	}
}