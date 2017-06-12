import java.util.Scanner;

public class Sort {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int repeat = in.nextInt();
    while (repeat -- != 0) {
      int n = in.nextInt();
      int[] nums = new int[n];
      for (int i = 0; i < n; ++ i)
        nums[i] = in.nextInt();
      // You can alternatively call insertionSort or bubbleSort here.
      insertionSort(nums);
      // bubbleSort(nums);
      for (int num: nums)
        System.out.print(num + " ");
      System.out.println();
    }
    in.close();
  }
  
  // Reference:
  //   1. http://www.algolist.net/Algorithms/Sorting/Insertion_sort
  //   2. https://en.wikipedia.org/wiki/Insertion_sort
  private static void insertionSort(int[] nums) {
    for (int i = 1; i < nums.length; ++ i)
      for (int j = i; j - 1 >= 0; -- j)
        if (nums[j - 1] > nums[j])
          swap(nums, j - 1, j);
  }
  
  // Reference:
  //   1. http://www.algolist.net/Algorithms/Sorting/Bubble_sort
  //   2. https://en.wikipedia.org/wiki/Bubble_sort
  private static void bubbleSort(int[] nums) {
    boolean hasSwapped = true;
    // This loop will terminate when there is NO swap operation happens during
    // the whole iterations of an array.
    while (hasSwapped) {
      hasSwapped = false;
      for (int i = 0; i < nums.length - 1; ++ i)
        if (nums[i] > nums[i + 1]) {
          hasSwapped = true;
          swap(nums, i, i + 1);
        }
    }
  }

  // Swap the two elements, nums[i] and nums[j], in the array -- nums
  private static void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}