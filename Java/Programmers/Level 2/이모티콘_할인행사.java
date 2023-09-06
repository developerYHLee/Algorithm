package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 이모티콘_할인행사 {
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int[][] users = new int[N][2];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			users[i][0] = Integer.parseInt(st.nextToken());
			users[i][1] = Integer.parseInt(st.nextToken());
		}
		
		int M = Integer.parseInt(br.readLine());
		int[] emoticons = new int[M];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < M; i++) emoticons[i] = Integer.parseInt(st.nextToken());
		
		int[] answer = new Solution().solution(users, emoticons);
		System.out.println(answer[0] + " " + answer[1]);
	}

	static class Solution {
	    int[][] user;
	    int[] emo, buy;
	    int m_plus, m_price, user_len, emo_len;
	    
	    public int[] solution(int[][] users, int[] emoticons) {
	        user_len = users.length;
	        user = users;
	        buy = new int[user_len];
	        
	        emo_len = emoticons.length;
	        emo = emoticons;
	        
	        solve(0);
	        int[] answer = {m_plus, m_price};
	        return answer;
	    }
	    
	    void solve(int index) {
	        if(index == emo_len) {
	            int count_plus = 0, total_price = 0;
	            for(int i = 0; i < user_len; i++) {
	               if(buy[i] >= user[i][1]) count_plus++;
	               else total_price += buy[i];
	            }
	            
	            if(count_plus > m_plus) {
	                m_plus = count_plus;
	                m_price = total_price;
	            }
	            else if(count_plus == m_plus) m_price = Math.max(m_price, total_price);
	            
	            return;
	        }
	        
	       for(int i = 1; i <= 4; i++) {
	           int price = emo[index] - emo[index] * i / 10;
	         
	           for(int j = 0; j < user_len; j++) {
	               int d_r = user[j][0];
	               if(d_r <= i * 10) buy[j] += price;
	            }
	           
	           solve(index + 1);
	           
	           for(int j = 0; j < user_len; j++) {
	               int d_r = user[j][0];
	               if(d_r <= i * 10) buy[j] -= price;
	            }
	        }
	    }
	}
}