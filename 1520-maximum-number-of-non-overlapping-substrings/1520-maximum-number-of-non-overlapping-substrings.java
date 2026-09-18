import java.util.*;

class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);

        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        List<int[]> chosen = new ArrayList<>();
        int prevEnd = -1;

        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (i != first[c]) continue;

            int end = getEnd(s, i, first, last);
            if (end == -1) continue;

            if (chosen.isEmpty() || i > prevEnd) {
                chosen.add(new int[]{i, end});
            } else {
                chosen.set(chosen.size() - 1, new int[]{i, end});
            }
            prevEnd = end;
        }

        List<String> result = new ArrayList<>();
        for (int[] seg : chosen) {
            result.add(s.substring(seg[0], seg[1] + 1));
        }
        return result;
    }

    private int getEnd(String s, int start, int[] first, int[] last) {
        int right = last[s.charAt(start) - 'a'];
        for (int j = start; j <= right; j++) {
            int c = s.charAt(j) - 'a';
            if (first[c] < start) return -1;
            right = Math.max(right, last[c]);
        }
        return right;
    }
}