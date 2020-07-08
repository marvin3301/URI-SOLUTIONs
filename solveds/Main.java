import java.util.Scanner;

public class Main {
    int[][] dp;
    int[][] flag;
    int M, N;

    int[] dx = new int[] {-1, 0, 1, 0};
    int[] dy = new int[] {0, -1, 0, 1};
    public int longestIncreasingContinuousSubsequenceII(int[][] A) {
        if (A == null || A.length == 0 || A[0].length == 0) {
            return 0;
        }
        M = A.length;
        N = A[0].length;
        dp = new int[M][N];
        flag = new int[M][N];

        int ans = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = search(i, j, A);
                ans = Math.max(ans, dp[i][j]);
            }
        }

        return ans;
    }

    public int search(int x, int y, int[][] A) {
        if (flag[x][y] != 0) {
            return dp[x][y];
        }

        int ans = 1;
        int nx, ny;
        for (int i = 0; i < dx.length; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (insideBoundary(nx, ny) && (A[x][y] > A[nx][ny])) {
                ans = Math.max(ans, search(nx, ny, A) + 1);
            }
        }

        flag[x][y] = 1;
        dp[x][y] = ans;

        return ans;
    }

    public boolean insideBoundary(int x, int y) {
        return (x >=0 && x < M && y >= 0 && y < N);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m;

        while(true){
            n=sc.nextInt();
            m=sc.nextInt();
            if(n==0 && m==0) break;
            int a[][] = new int[n][m];
            Main mainClass = new Main();
            for (int i =0; i<n ;i++ ) {
                for (int j = 0;j<m ;j++ ) {
                    a[i][j] = sc.nextInt();
                }
            }
            System.out.println(mainClass.longestIncreasingContinuousSubsequenceII(a));
        }
        
    }
}