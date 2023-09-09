package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B12851 { //¼û¹Ù²ÀÁú 2
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int[] count = new int[100001], save = new int[100001];
		Arrays.fill(save, Integer.MAX_VALUE);
		Queue<int[]> Q = new LinkedList<>();
		Q.add(new int[] {N, 0});
		
		count[N]++;
		while(!Q.isEmpty()) {
			int[] cur = Q.remove();
			
			if(cur[0] == K) break;
			
			int x1 = cur[0] + 1;
			int x2 = cur[0] - 1;
			int x3 = cur[0] * 2;
			
			if(x1 <= 100000 && save[x1] >= cur[1] + 1) {
				Q.add(new int[] {x1, cur[1] + 1});
				count[x1]++;
				save[x1] = cur[1] + 1;
			}
			if(x2 >= 0 && save[x2] >= cur[1] + 1) {
				Q.add(new int[] {x2, cur[1] + 1});
				count[x2]++;
				save[x2] = cur[1] + 1;
			}
			if(x3 <= 100000 && save[x3] >= cur[1] + 1) {
				Q.add(new int[] {x3, cur[1] + 1});
				count[x3]++;
				save[x3] = cur[1] + 1;
			}
		}
		
		System.out.println((save[K] == Integer.MAX_VALUE ? 0 : save[K]) + "\n" + count[K]);
	}
}