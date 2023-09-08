package Programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Ç¥_º´ÇÕ {
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] commands = br.readLine().replaceAll("[\\[\\]\"]", "").split(", ");
		String res = Arrays.stream(new Solution().solution(commands)).reduce("", (s1, s2) -> s1.equals("") ? s2 : s1 + ", " + s2);
		System.out.println(res);
	}
	
	static class Solution {
	    String ans = "";
	    int[] parent = new int[2501];
	    String[] map = new String[2501];
	    
	    public String[] solution(String[] commands) {
	        initiate();

	        for(int i = 0; i < commands.length; i++) {
	            StringTokenizer st = new StringTokenizer(commands[i]);
	            
	            String command = st.nextToken();
	            solve(command, st);    
	        }
	        
	        String[] answer = ans.split(" ");
	        return answer;
	    }
	    
	    void solve(String command, StringTokenizer st) {
	        if(command.equals("UPDATE")) {
	            if(st.countTokens() == 2) {
	                String v1 = st.nextToken();
	                String v2 = st.nextToken();
	                
	                for(int i = 1; i <= 2500; i++) {
	                    if(map[find(i)].equals(v1)) map[i] = v2;
	                }
	            }
	            else {
	                int r = Integer.parseInt(st.nextToken());
	                int c = Integer.parseInt(st.nextToken());
	                String v = st.nextToken();
	                
	                int x = convert(r, c);
	                map[find(x)] = v;
	            }
	        }
	        else if(command.equals("MERGE")) {
	            int r1 = Integer.parseInt(st.nextToken());
	            int c1 = Integer.parseInt(st.nextToken());
	            int r2 = Integer.parseInt(st.nextToken());
	            int c2 = Integer.parseInt(st.nextToken());
	            
	            int x1 = convert(r1, c1), x2 = convert(r2, c2);
	            x1 = find(x1);
	            x2 = find(x2);
	            if(map[x1].equals("EMPTY") && !map[x2].equals("EMPTY")) union(x2, x1);
	            else union(x1, x2);
	        }
	        else if(command.equals("UNMERGE")) {
	            int r = Integer.parseInt(st.nextToken());
	            int c = Integer.parseInt(st.nextToken());
	            
	            int x = convert(r, c);
	            x = find(x);
	            String str = map[x];
	            
	            ArrayList<Integer> list = new ArrayList<>();
	            for(int i = 1; i <= 2500; i++) {
	                if(find(i) == x) list.add(i);
	            }
	            for(int i : list) {
	                map[i] = "EMPTY";
	                parent[i] = i;
	            }
	            
	            x = convert(r, c);
	            map[x] = str;
	        }
	        else if(command.equals("PRINT")) {
	            int r = Integer.parseInt(st.nextToken());
	            int c = Integer.parseInt(st.nextToken());
	            int x = convert(r, c);
	            
	            ans += map[find(x)] + " ";
	        }
	    }
	    
	    int convert(int r, int c) {
	        return (r - 1) * 50 + c;
	    }
	    
	    int find(int x) {
	        if(x == parent[x]) return x;
	        
	        return find(parent[x]);
	    }
	    
	    void union(int x, int y) {
	        int a = find(x);
	        int b = find(y);
	        
	        parent[b] = a;
	    }
	    
	    void initiate() {
	        for(int i = 1; i <= 2500; i++) {
	            parent[i] = i;
	            map[i] = "EMPTY";
	        }
	    }
	}
}
