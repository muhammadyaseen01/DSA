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

void min_heapify(int arr [], int index, int size) {
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

void min_build_heap(int arr[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        min_heapify(arr, i, size);
    }
}

int min_insert(int arr [], int new_val, int capacity, int &size) {
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

void deletion(int arr[], int &size) {
    if (size == 0) {
        cout << "Heap is empty. Deletion not possible." << endl;
        return;
    }

    // Replace the root node with the last element.
    swap(arr[0], arr[size - 1]);
    size--;

    // Restore the max-heap property by calling max_heapify on the root node.
    min_heapify(arr, 0, size);
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main(){
    int capacity, n, new_val, size = 0;
    cout<<"enter capacity :";
    cin >> capacity;
    int arr[capacity];
    cout<<"enter how many number you want to enter: ";
    cin>>n;

    for (int i = 0; i < n && size != capacity; i++) {
        cout << "Enter the value you want to insert: ";
        cin >> new_val;
        arr[i] = new_val;
        size ++;
    }
    cout << "Before heapify" << endl;
    print(arr, size);
    cout<<endl;
    cout << "After heapify" << endl;
    min_build_heap(arr, size);

    print(arr, size);
    cout<<endl;

    deletion(arr,size);
    deletion(arr,size);

    cout << "After deletion" << endl;
    print(arr, size);
    cout<<endl;

    return 0;
}