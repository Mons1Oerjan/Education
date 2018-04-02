package ArrayList;

import java.util.Arrays;

class ArrayList {
	private int[] arr;
	private int size;

	public ArrayList() {
		this.arr = new int[10];
		this.size = 0;
	}

	public ArrayList(final int[] values) {
		this.arr = values;
		this.size = values.length;
	}

	private boolean isFull() {
		if (size == arr.length) {
			return true;
		}
		return false;
	}

	public boolean isEmpty() {
		return size == 0;
	}
	
	private void scaleUp() {
		int[] newArr = Arrays.copyOf(arr, size * 2);
		this.arr = newArr;
	}

	private void scaleDown() {
		int[] newArr = new int[arr.length / 2];

		for (int i = 0; i < newArr.length; i++) {
			newArr[i] = arr[i];
		}

		this.arr = newArr;
		this.size = newArr.length;
	}

	public int get(final int index) {
		if (index >= 0 && index < arr.length) {
			return arr[index];
		}
		return -1;
	}

	public void add(final int value) {
		if (this.isFull()) {
			this.scaleUp();
		}
		arr[size] = value;
		size++;
	}

	public void remove(final int index) {
		if (this.isEmpty()) {
			return;
		}

		arr[size - 1] = -1;
		size--;

		if (arr.length > 0 && size <= arr.length / 2) {
			this.scaleDown();
		}
	}

	public int size() {
		return this.size;
	}
	
	public void print() {
		System.out.println(Arrays.toString(arr));
	}
}
