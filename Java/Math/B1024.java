package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B1024 { //수열의 합
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		
		for(int i = L; i <= 100; i++) {
			StringBuilder sb = new StringBuilder();
			int num = N / i, sum = 0;
			
			num -= ((i % 2 == 0) ? i - 2 : i - 1) / 2;
			
			if(num < 0) {
				System.out.println(-1);
				return ;
			}
			
			for(int j = 0; j < i; j++) {
				sum += num;
				sb.append(num++).append(' ');
			}
			
			if(sum == N) {
				System.out.println(sb);
				return;
			}	
		}
			
		System.out.println(-1);
	}
}