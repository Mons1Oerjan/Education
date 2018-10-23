public class q8 {
	private static void printMatrix(final int[][] matrix) {
		for (int row = 0; row < matrix.length; row++) {
			for (int col = 0; col < matrix[0].length; col++) {
				System.out.print(matrix[row][col] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	/**
	 * Given an M x N matrix, if an element is 0, this algorithm
	 * sets its entire row and column to 0.
	 * 
	 * Time complexity: O(M * N)
	 * Space complexity: O(M + N)
	 */
	private static void zeroMatrix(final int[][] matrix) {
		final int M = matrix.length;
		final int N = matrix[0].length;
		final boolean[] zeroFlagCols = new boolean[N];
		final boolean[] zeroFlagRows = new boolean[M];

		// find all 0s in the matrix and flag indices
		for (int row = 0; row < M; row++) {
			for (int col = 0; col < N; col++) {
				if (matrix[row][col] == 0) {
					zeroFlagCols[col] = true;
					zeroFlagRows[row] = true;
				}
			}
		}

		// set rows to 0
		for (int row = 0; row < M; row++) {
			if (zeroFlagRows[row]) {
				for (int col = 0; col < N; col++) {
					matrix[row][col] = 0;
				}
			}
		}

		// set cols to 0
		for (int col = 0; col < N; col++) {
			if (zeroFlagCols[col]) {
				for (int row = 0; row < M; row++) {
					matrix[row][col] = 0;
				}
			}
		}
	}

	public static void main(String... args) {
		final int[][] matrix = {
			{1, 2, 3}, 
			{4, 5, 6}, 
			{7, 8, 9}, 
			{10, 0, 11}
		};
		zeroMatrix(matrix);
		printMatrix(matrix);
	}
}
