import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

final class ProblemC {
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    static FastScanner sc = new FastScanner();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {

        int tc = sc.nextInt();
        while (tc-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();

            Arrays.sort(a);
            Boolean[] used = new Boolean[n + 1];
            for (int i = 0; i < n + 1; i++)
                used[i] = false;
            Boolean ok = true;
            for (int i = n - 1; i >= 0 && ok; i--) {
                while (a[i] > n || used[a[i]])
                    a[i] /= 2;
                if (a[i] == 0)
                    ok = false;
                used[a[i]] = true;
            }

            if (ok)
                bw.write("YES\n");
            else
                bw.write("NO\n");
        }

        bw.flush();
        bw.close();
    }

    public static int inputInt() throws IOException {
        return sc.nextInt();
    }

    public static long inputLong() throws IOException {
        return sc.nextLong();
    }

    public static void print(String a) throws IOException {
        bw.write(a);
    }

    public static void printSp(String a) throws IOException {
        bw.write(a + " ");
    }

    public static void println(String a) throws IOException {
        bw.write(a + "\n");
    }
}