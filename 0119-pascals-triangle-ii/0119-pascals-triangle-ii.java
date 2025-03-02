class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> rows = new ArrayList<>(Collections.nCopies(rowIndex + 1, 0));
        rows.set(0, 1);

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                rows.set(j, rows.get(j) + rows.get(j - 1));
            }
        }

        return rows;
    }
}