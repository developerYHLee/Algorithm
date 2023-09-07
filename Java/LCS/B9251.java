package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B9251 { //LCS
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str1 = br.readLine(), str2 = br.readLine();
		int size1 = str1.length(), size2 = str2.length();
		
		int[][] dp = new int[size1 + 1][size2 + 1];
		dp[0][0] = 0;
		
		for(int i = 1; i <= size1; i++) {
			char word1 = str1.charAt(i - 1);
			
			for(int j = 1; j <= size2; j++) {
				char word2 = str2.charAt(j - 1);
				
				if(word1 == word2) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		
		System.out.println(dp[size1][size2]);
	}
}