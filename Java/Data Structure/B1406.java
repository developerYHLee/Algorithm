package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class B1406 { //¿¡µðÅÍ
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		Stack<Character> left = new Stack<>(), right = new Stack<>();
		String str = br.readLine();
		
		for(int i = 0; i < str.length(); i++) left.add(str.charAt(i));
		int N = Integer.parseInt(br.readLine());
		while(N-- > 0) {
			str = br.readLine();
			char c = str.charAt(0);
			
			if(c == 'L' && !left.isEmpty()) right.push(left.pop());
			else if(c == 'D' && !right.isEmpty()) left.push(right.pop());
			else if(c == 'B' && !left.isEmpty()) left.pop();
			else if(c == 'P') left.push(str.charAt(2));
		}
		
		while(!left.isEmpty()) right.push(left.pop());
		while(!right.isEmpty()) sb.append(right.pop());
		
		System.out.println(sb);
	}
}