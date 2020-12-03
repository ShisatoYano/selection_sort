#include <iostream>
using namespace std;

// function to print array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// function to find index of minimum element
// this function is called recursively
int find_min_index(int array[], int index, int size) {
    if (index == size) {
        return index;
    }

    int min_index = find_min_index(array, index + 1, size);

    return array[index] < array[min_index] ? index : min_index;
}

// function to sort array by selection sort algorithm
// this function is called recursively
void selection_sort(int array[], int size, int index = 0) {
    if (index == size) {
        return;
    }

    int min_index = find_min_index(array, index, size - 1);
    if (min_index != index) {
        swap(array[index], array[min_index]);
    }

    selection_sort(array, size, index + 1);
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Given array: ";
    print_array(array, size);

    selection_sort(array, size);

    cout << "Sorted array: ";
    print_array(array, size);

    return 0;
}
