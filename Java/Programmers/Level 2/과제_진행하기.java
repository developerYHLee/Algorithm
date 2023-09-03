package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 과제_진행하기 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		String[][] plans = new String[N][3];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			plans[i][0] = st.nextToken();
			plans[i][1] = st.nextToken();
			plans[i][2] = st.nextToken();
		}
		

		String[] ans = new Solution().solution(plans);
		for(int i = 0; i < N; i++) System.out.print(ans[i] + " ");
	}

	static class Solution {
	    String[] answer;
	    String[][] plans;
	    boolean[] vis;
	    int size, ans_index = 0;
	    
	    public String[] solution(String[][] plan) {
	       plans = plan;
	        Arrays.sort(plans, new Comparator<String[]>(){
	            @Override
	            public int compare(String[] o1, String[] o2) {
	                return o1[1].compareTo(o2[1]);
	            }
	        });
	        
	        size = plans.length;
	        answer = new String[size];
	        vis = new boolean[size];
	        
	        for(int i = 0; i < size; i++){
	            if(!vis[i]) solve(plans[i][0], plans[i][1], Integer.parseInt(plans[i][2]), i);
	        }
	        return answer;
	    }
	    
	    int solve(String name, String clock, int time, int index) {
	        vis[index] = true;
	        
	        for(int i = index + 1; i < size; i++) {
	            String finish = cal(clock, time);
	            String next_clock = plans[i][1];
	            
	            if(finish.compareTo(next_clock) <= 0) {
	                answer[ans_index++] = name;
	                return time;
	            }
	            else {
	                if(!vis[i]) time += solve(plans[i][0], next_clock, Integer.parseInt(plans[i][2]), i);
	            }
	        }
	        
	        answer[ans_index++] = name;
	        return time;
	    }
	    
	    String cal(String clock, int time) {
	        int index = clock.indexOf(':');
	        
	        int h = Integer.parseInt(clock.substring(0,index));
	        int m = Integer.parseInt(clock.substring(index + 1));
	        
	        m += time;
	        if(m >= 60) {
	            h += m / 60;
	            m %= 60;
	        }
	        
	        String new_h = "";
	        String new_m = "";
	        
	        if(h < 10) new_h += "0";
	        new_h += h;
	        if(m < 10) new_m += "0";
	        new_m += m;
	            
	        return new_h + ":" + new_m;
	    }
	}
}
