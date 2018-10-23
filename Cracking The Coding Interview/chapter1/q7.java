public class q7 {
	
	private static void printMatrix(final int[][] matrix) {
		for (int i = 0; i < matrix.length; i++) {
			final int[] row = matrix[i];

			for (int j = 0; j < row.length; j++) {
				System.out.print(row[j] + " ");
			}
			System.out.println();
		}
	}

	/**
	 * Rotates a square matrix by 90 degrees in O(n^2) time and O(n^2) space
	 */
	private static int[][] rotateMatrix(final int[][] matrix) {
		final int size = matrix.length;
		final int[][] result = new int[size][size];

		for (int col = 0; col < size; col++) {
			for (int row = 0; row < size; row++) {
				result[col][row] = matrix[size - 1 - row][col];
			}
		}

		return result;
	}

	/**
	 * Rotates a square matrix by 90 degrees in O(n^2) time and O(1) space
	 */
	private static void rotateMatrixInPlace(final int[][] matrix) {
		final int size = matrix.length;

		for (int i = 0; i < size / 2; i++) {
			final int rightIndex = size - 1 - i;

			for (int j = i; j < size - 1 - i; j++) {
				final int top = matrix[i][j];
				final int leftIndex = size - 1 - j;

				// move left to top
				matrix[i][j] = matrix[leftIndex][i];

				// move bottom to left
				matrix[leftIndex][i] = matrix[rightIndex][leftIndex];

				// move right to bottom
				matrix[rightIndex][leftIndex] = matrix[j][rightIndex];

				// move top to right
				matrix[j][rightIndex] = top;
			}
		}
	}

	public static void main(String... args) {
		final int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		printMatrix(rotateMatrix(matrix));
		
		System.out.println();

		rotateMatrixInPlace(matrix);
		printMatrix(matrix);
	}
}
