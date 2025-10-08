class Solution {
    static void moveZeroes(int[] arr) {
    int idx = 0;
    for (int num : arr) if (num != 0) arr[idx++] = num;
    while (idx < arr.length) arr[idx++] = 0;
}
}