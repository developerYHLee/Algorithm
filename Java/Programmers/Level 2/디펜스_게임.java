package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class µ∆ÊΩ∫_∞‘¿” {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		int[] enemy = Arrays.stream(br.readLine().replace(",", "").split(" ")).mapToInt(Integer::parseInt).toArray();
		
		System.out.println(new Solution().solution(n, k, enemy));
	}
	
	static class Solution {
	    public int solution(int n, int k, int[] enemy) {
	        int ans = 0;
	        
	        PriorityQueue<Integer> PQ = new PriorityQueue<>(Collections.reverseOrder());
	        for(int i = 0; i < enemy.length; i++) {
	            n -= enemy[i];
	            PQ.add(enemy[i]);
	            ans++;
	            
	            while(n < 0 && k > 0) {
	                int cur = PQ.remove();
	                k--;
	                n += cur;
	            }
	            
	            if(n < 0) return ans - 1;
	        }
	        
	        return ans;
	    }
	}
}