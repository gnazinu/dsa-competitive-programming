import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class B {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static boolean inBraces(String s, int pos) {
        int cnt = 0;
        for (int i = 0; i < pos; i++) {
            if (s.charAt(i) == '{') cnt++;
            else if (s.charAt(i) == '}') cnt--;
        }
        return cnt > 0;
    }

    static String transform(String num) {
        int zeros = 0;
        for (int i = num.length() - 1; i >= 0 && num.charAt(i) == '0'; i--) {
            zeros++;
        }

        if (zeros < 4) return num;

        if (num.charAt(0) == '1' && zeros == num.length() - 1) {
            return "10^{" + zeros + "}";
        }

        String m = num.substring(0, num.length() - zeros);
        if (m.length() > 1) {
            m = m.charAt(0) + "." + m.substring(1);
        }
        return m + "\\cdot10^{" + (num.length() - 1) + "}";
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(reader.readLine());

        for (int i = 0; i < n; i++) {
            String line = reader.readLine();
            String result = "";

            for (int j = 0; j < line.length(); j++) {
                if (Character.isDigit(line.charAt(j))) {
                    int start = j;
                    while (j < line.length() && Character.isDigit(line.charAt(j))) {
                        j++;
                    }
                    String num = line.substring(start, j);
                    j--;

                    int zeros = 0;
                    for (int k = num.length() - 1; k >= 0 && num.charAt(k) == '0'; k--) {
                        zeros++;
                    }

                    boolean alphaBefore = (start > 0 && Character.isLetter(line.charAt(start - 1)));
                    boolean alphaAfter = (j + 1 < line.length() && Character.isLetter(line.charAt(j + 1)));

                    if (zeros >= 4 && !inBraces(line, start) && !alphaBefore && !alphaAfter) {
                        result += transform(num);
                    } else {
                        result += num;
                    }
                } else {
                    result += line.charAt(j);
                }
            }

            System.out.println(result);
        }
    }
}
