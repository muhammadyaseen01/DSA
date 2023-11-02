#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int L_child(int index) {
    return (2 * index + 1);
}

int R_child(int index) {
    return (2 * index + 2);
}

int parent(int index) {
    return ((index - 1) / 2);
}

void min_heapify(int *arr, int index, int size) {
    int left_child = L_child(index);
    int right_child = R_child(index);
    int smallest = index;

    if (left_child < size && arr[left_child] < arr[smallest])
        smallest = left_child;

    if (right_child < size && arr[right_child] < arr[smallest])
        smallest = right_child;

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        min_heapify(arr, smallest, size);
    }
}

void build_heap(int arr[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        min_heapify(arr, i, size);
    }
}

void print_1(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int insert(int *arr, int new_val, int capacity, int &size) {
    if (size == capacity)
        return 0;
    size++;
    arr[size - 1] = new_val;
    for (int i = (size - 1); i != 0 && arr[parent(i)] > arr[i];) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    return size;
}

int main() {
    int capacity, n, new_val, size = 0;
    cout << "Define the capacity of the array: ";
    cin >> capacity;
    int *arr = new int[capacity];
    cout << "Enter how many numbers you want to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value you want to insert: ";
        cin >> new_val;
        size = insert(arr, new_val, capacity, size);
    }

    cout << "Before heapify" << endl;
    print_1(arr, size);

    cout << "After heapify" << endl;
    build_heap(arr, size);

    print_1(arr, size);

    // delete[] arr; // Don't forget to release the memory allocated with 'new'.

    return 0;
}
