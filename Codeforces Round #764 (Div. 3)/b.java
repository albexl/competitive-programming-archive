import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

final class ProblemB {
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
            int n = 3;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            Boolean ok = false;

            for (int i = 0; i < n; i++) {
                int diff = 0;
                if (i == 0) {
                    diff = a[2] - a[1];
                    int x = a[1] - diff;
                    if (x % a[i] == 0 && x / a[i] > 0)
                        ok = true;
                } else if (i == 2) {
                    diff = a[1] - a[0];
                    int x = a[1] + diff;
                    if (x % a[i] == 0 && x / a[i] > 0)
                        ok = true;
                } else {
                    diff = a[2] - a[0];
                    if (diff % 2 != 0)
                        continue;
                    diff /= 2;
                    int x = a[0] + diff;
                    if (x % a[i] == 0 && x / a[i] > 0)
                        ok = true;
                }
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