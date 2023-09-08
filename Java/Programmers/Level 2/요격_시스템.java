package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 요격_시스템 {
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int[][] targets = new int[N][2];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			
			targets[i][0] = s;
			targets[i][1] = e;
		}
		
		System.out.println(new Solution().solution(targets));
	}

	static class Solution {
	    public int solution(int[][] targets) {
	        int answer = 0;
	        
	        Arrays.sort(targets, new Comparator<int[]>(){
	            @Override
	            public int compare(int[] o1, int[] o2) {
	                if(o1[1] == o2[1]) return o1[0] - o2[0];
	                
	                return o1[1] - o2[1];
	            }
	        });
	        
	        int end = 0;
	        for(int i = 0; i < targets.length; i++) {
	            if(targets[i][0] < end) continue;
	            
	            answer++;
	            end = targets[i][1];
	        }
	        
	        return answer;
	    }
	}
}