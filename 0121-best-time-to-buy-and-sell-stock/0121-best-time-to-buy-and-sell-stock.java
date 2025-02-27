class Solution {
    public int maxProfit(int[] prices) {
        int maxPrice = 0;
        int minPrice = Integer.MAX_VALUE;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                maxPrice = Math.max(maxPrice, price - minPrice);
            }
        }

        return maxPrice;
    }
}