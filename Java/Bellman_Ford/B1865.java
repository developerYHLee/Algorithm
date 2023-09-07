package Practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B1865 { //¿úÈ¦
	static ArrayList<int[]>[] map;
	static int N;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		while(T-- > 0) {
			initiate(br);
			if(Bellman_Ford()) sb.append("YES\n");
			else sb.append("NO\n");
		}
		
		System.out.println(sb);
	}
	
	static void initiate(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int W = Integer.parseInt(st.nextToken());

		map = new ArrayList[N + 1];
		for(int i = 1; i <= N; i++) map[i] = new ArrayList<>();
	
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			
			map[n1].add(new int[] {n2, d});
			map[n2].add(new int[] {n1, d});
		}
		
		for(int i = 0; i < W; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			int d = -Integer.parseInt(st.nextToken());

			map[n1].add(new int[] {n2, d});
		}
	}
	
	static boolean Bellman_Ford() {
		int[] dis = new int[N + 1];
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				for(int[] k : map[j]) {
					int next = k[0], d = k[1];
					
					if(dis[next] > dis[j] + d) {
						dis[next] = dis[j] + d;
						
						if(i == N) return true;
					}
				}
			}
			
		}
		
		return false;
	}
}