import java.util.Scanner;

// test case
//4
//w
//xbwwb
//xbwxwbbwb
//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

// results
//w
//xwbbw
//xxbwwbbbw
//xxwbxwwxbbwwbwbxwbwwxwwwxbbwb




class QUADTREE {

    static String str;

    static String dcvq(int pos) {
        if (str.charAt(pos) == 'b' || str.charAt(pos) == 'w') return str.substring(pos, pos + 1);

        int nowPos = pos + 1;

        String lh = dcvq(nowPos);
        nowPos += lh.length();
        String rh = dcvq(nowPos);
        nowPos += rh.length();
        String ll = dcvq(nowPos);
        nowPos += ll.length();
        String rl = dcvq(nowPos);
        return "x" + ll + rl + lh + rh;
    }

    static void driver() {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        for (int i = 0; i < tc; ++i) {
            str = sc.next();
            System.out.println(dcvq(0));
        }
    }

    static void test() {
        String testStr = "abcde";


        System.out.println(testStr.substring(1, 2));
    }


    public static void main(String[] args) {
//        System.out.println();
        driver();
//        test();
    }
}

