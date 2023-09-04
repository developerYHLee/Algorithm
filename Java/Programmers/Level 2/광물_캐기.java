package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class ±¤¹°_Ä³±â {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int[] picks = new int[3];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < 3; i++) picks[i] = Integer.parseInt(st.nextToken());
		
		String str = br.readLine();
		str = str.replaceAll("[\",]", "");
		String[] minerals = str.split(" ");
	
		System.out.println(new Solution().solution(picks, minerals));
	}
	
	static class Solution {
	    public int solution(int[] picks, String[] minerals) {
	        int answer = 0, size = minerals.length;
	        int count_pick = 0;
	        for(int i = 0; i < 3; i++) count_pick += picks[i];
	        
	        int[][] count_mineral = new int[size / 5 + 1][3];
	        int count = 0, index = 0;
	        for(int i = 0; i < size; i++) {
	            if(minerals[i].equals("diamond")) count_mineral[index][0]++;
	            else if(minerals[i].equals("iron")) count_mineral[index][1]++;
	            else count_mineral[index][2]++;
	            
	            if(++count == 5) {
	                count = 0;
	                index++;
	            }
	            
	            if(index == count_pick) break;
	        }
	        
	        Arrays.sort(count_mineral, new Comparator<int[]>() {
	            @Override
	            public int compare(int[] o1, int[] o2) {
	                if(o1[0] == o2[0]) return o2[1] - o1[1];
	                return o2[0] - o1[0];
	            }
	        });
	        
	        size = count_mineral.length;
	        for(int i = 0; i < size; i++) {
	            if(picks[0] > 0) {
	                picks[0]--;
	                answer += count_mineral[i][0] + count_mineral[i][1] + count_mineral[i][2];
	            }
	            else if(picks[1] > 0) {
	                picks[1]--;
	                answer += count_mineral[i][0] * 5 + count_mineral[i][1] + count_mineral[i][2];
	            }
	            else if(picks[2] > 0) {
	                picks[2]--;
	                answer += count_mineral[i][0] * 25 + count_mineral[i][1] * 5 + count_mineral[i][2];
	            }
	            else {
	                System.out.println("´õ ÀÌ»ó °î±ªÀÌ ¾øÀ½!\n");
	                break;
	            }
	        }
	        
	        return answer;
	    }   
	}
}
