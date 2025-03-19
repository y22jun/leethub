class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer> checkNums = new HashSet<>();

        for (int num : nums) {
            if(!checkNums.add(num)) {
                return true;
            }
        }

        return false;
    }
}