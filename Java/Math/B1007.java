package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class B1007 { //º¤ÅÍ ¸ÅÄª
	static int[][] P;
	static double min;
	static int N;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		while(T-- > 0) {
			N = Integer.parseInt(br.readLine());
			
			int x = 0, y = 0;
			min = Double.MAX_VALUE;
			P = new int[N][2];
			for(int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				P[i][0] = Integer.parseInt(st.nextToken());
				P[i][1] = Integer.parseInt(st.nextToken());
				x += P[i][0];
				y += P[i][1];
			}
			solve(0, x, y, 0);
			
			DecimalFormat df = new DecimalFormat("0.000000000000");
			String formattedNumber = df.format(min);
			
			sb.append(formattedNumber).append("\n");
		}
		
		System.out.println(sb);
	}

	//if dir_x is +, it means the direction is to the right
	//so the next direction has to be the left
	static void solve(int index, int x, int y, int count) {
		if(count == N / 2) {
			min = Math.min(min, cal_dir(x, y));
			return;
		}
		
		for(int i = index; i < N; i++) solve(i + 1, x - 2 * P[i][0], y - 2 * P[i][1], count + 1);
	}
	
	static double cal_dir(int x, int y) {
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	}
}