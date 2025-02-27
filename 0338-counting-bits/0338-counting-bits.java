class Solution {
    public int[] countBits(int n) {
        int[] list = new int[n + 1];
        list[0] = 0;
        for (int i = 1; i <= n; i++) {
            list[i] = list[i / 2] + (i % 2);
        }
        return list;
    }
}