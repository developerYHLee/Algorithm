package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 뒤에_있는_큰_수_찾기 {
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		int[] num = Arrays.stream(str.replace(",", "").split(" ")).mapToInt(Integer::parseInt).toArray();
		System.out.println(Arrays.stream(new Solution().solution(num)).mapToObj(String::valueOf).reduce("", (s1, s2) -> s1.equals("") ? s2 : s1 + ", " + s2));
	}
	
	static class Solution {
	    public int[] solution(int[] num) {
	        int size = num.length;

	        int[] ans = new int[size], p = new int[size];
	        Arrays.fill(ans, -1);
	        Arrays.fill(p, -1);

	        for(int i = size - 2; i >= 0; i--) {
	            for(int j = i + 1; j < size;) {
	                if(num[i] < num[j]) {
	                    ans[i] = num[j];
	                    p[i] = j;
	                    break;
	                }
	                else if(p[j] == -1) break;
	                j = p[j];
	            }
	        }

	        return ans;
	    }
	}
}
