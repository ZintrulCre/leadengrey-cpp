import java.util.Map;
import java.util.HashMap;
import java.util.PriorityQueue;

public class leetcode {
    public static void leetcode() {
        Solution s = new Solution();
        int hand[] = {1,2,3,6,2,3,4,7,8};
        System.out.println(s.isNStraightHand(hand, 3));
    }
}

// 846
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        Map<Integer, Integer> m = new HashMap<>();
        PriorityQueue<Integer> h = new PriorityQueue<>((a,b)->a-b);
        for (int k : hand) {
            m.put(k, m.getOrDefault(k, 0) + 1);
            h.add(k);
        }
        while (!h.isEmpty()) {
            int k = h.poll();
            // System.out.println(k);
            if (m.get(k) == 0)
                continue;
            for (int i = k; i < k + groupSize; ++i) {
                int j = m.getOrDefault(i, 0);
                // System.out.println(j);
                if (j == 0)
                    return false;
                m.put(i, j - 1);
            }
        }
        return true;
    }
}