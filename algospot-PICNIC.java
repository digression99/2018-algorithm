import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.LinkedList;
import java.util.Scanner;

// test case
//3
//2 1
//0 1
//4 6
//0 1 1 2 2 3 3 0 0 2 1 3
//6 10
//0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5


class Main {

    private static int n, m;
    private static int cnt;
    private static LinkedList<Integer> graph[];

    private static boolean isVisited(int visited, int idx) {
        return(visited & (1 << idx)) > 0;
    }

    private static int setVisited(int visited, int idx) {
        return visited | (1 << idx);
    }

    private static int unsetVisited(int visited, int idx) {
        int mask = (1 << 10) - 1;
        mask ^= (1 << idx);
        return visited & mask;
    }

    private static void exhaustive(int visited) {
        if (visited == (1 << n) - 1) {
            ++cnt;
            return;
        }

        int first = -1;

        for (int i = 0; i < graph.length; ++i) {
            if (!isVisited(visited, i)) {
                first = i;
                break;
            }
        }

        visited = setVisited(visited, first);

        for (int i = 0; i < graph[first].size(); ++i) {
            int idx = graph[first].get(i);
            if (!isVisited(visited, idx)) {
//                visited = setVisited(visited, graph[first.ge])
                visited = setVisited(visited, idx);
                exhaustive(visited);
                visited = unsetVisited(visited, idx);
            }
        }
    }

    public static void driver() {
        Scanner reader = new Scanner(System.in);
        int tc = reader.nextInt();

        for (int i = 0; i < tc; ++i) {
            n = reader.nextInt();
            m = reader.nextInt();
            graph = new LinkedList[n];
            cnt = 0;

            for (int j = 0; j < n; ++j) graph[j] = new LinkedList<>();

            for (int j = 0; j < m; ++j) {
                int u, v;
                u = reader.nextInt();
                v = reader.nextInt();

                graph[u].addFirst(v);
                graph[v].addFirst(u);
            }
            exhaustive(0);

            System.out.println(cnt);

            for (int j = 0; j < n; ++j) graph[j].clear();
        }
    }

    public static void main(String[] args) throws IOException {

        driver();


//        Scanner reader = new Scanner(System.in);
//
////        int t = reader.nextInt();
////
////        System.out.println(exhaustive(t));
//        System.out.println("hello");
//
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
////        br.readLine();
//        String s = br.readLine();
//        System.out.println("input string is : " + s);
//
//        String[] words = s.split(" ");
////        System.out.println(words);
//
//        for (String str : words) {
//            System.out.println(str);
//        }
    }
}

