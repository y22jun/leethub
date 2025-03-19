class Solution {
    public int majorityElement(int[] nums) {
        int check = nums[0], cnt = 0;

        for (int num : nums) {
            if (cnt == 0) {
                cnt = num;
            }

            cnt += (num == check) ? 1 : -1;
        }

        return check;
    }
}