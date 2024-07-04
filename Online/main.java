import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");

        int n = input.length;
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int result = -1;
        int left_sum = 0;
        int right_sum = 0;
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            if (left_sum == right_sum && i < j) {
                left_sum += arr[i];
                right_sum += arr[j];
                i++;
                j--;
            } else if (left_sum == right_sum && i == j) {
                result = arr[i];
                i++;
                j--;
            } else if (left_sum < right_sum) {
                left_sum += arr[i];
                i++;
            } else {
                right_sum += arr[j];
                j--;
            }
        }

        System.out.println(result);
        scanner.close();
    }
}
