import java.io.*;
import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.util.Arrays;
class flyodwarshall{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0){
			int v = Integer.parseInt(br.readLine());
			int[][] graph = new int[v][v];
			for(int i = 0; i < v; i++){
				String data[] = br.readLine().trim().split(" ");
				for(int j = 0; j < v; j++){
					graph[i][j] = Integer.parseInt(data[j]);
				}
			}
			flyodwarshall obj = new flyodwarshall();
			obj.findDist(graph, v);
		}
	}
	public void findDist(int[][] graph, int v){
		int[][] dist = new int[v][v];
		int INF = 10000000;
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(graph[i][j] >= INF){
					dist[i][j] = INF;
				}
				else{
					dist[i][j] = graph[i][j];
				}
			}
		}
		for(int k = 0; k < v; k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					if(dist[i][k] == INF || dist[k][j] == INF){
						continue;
					}
					if(dist[i][k] + dist[k][j] < dist[i][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		printDist(dist);
	}
	public void printDist(int[][] dist){
		int n = dist.length;
		int INF = 10000000;
		StringBuffer br = new StringBuffer();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][j] == INF){
					br.append("INF ");
				}
				else{
					br.append(dist[i][j] + " ");
				}
			}
			br.append("\n");
		}
		System.out.println(br.toString().trim());
	}
}