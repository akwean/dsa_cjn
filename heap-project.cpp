#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;  // Vector to store the elements of the heap

    // Heapify up to maintain the heap property after insertion
    void heapifyUp(int index) {
        // Check if the current index is not the root and if the parent's value is greater than the current element
        if (index && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);  // Swap the current element with the parent
            heapifyUp(parent(index));  // Recursively heapify up the parent
        }
    }

    // Heapify down to maintain the heap property after deletion
    void heapifyDown(int index) {
        int left = leftChild(index);  // Index of the left child
        int right = rightChild(index);  // Index of the right child
        int smallest = index;  // Assume the smallest element is the current element

        // If the left child is smaller than the current element, update smallest
        if (left < size() && heap[left] < heap[index])
            smallest = left;

        // If the right child is smaller than the smallest element, update smallest
        if (right < size() && heap[right] < heap[smallest])
            smallest = right;

        // If the smallest element is not the current element, swap and continue heapifying down
        if (smallest != index) {
            swap(heap[index], heap[smallest]);  // Swap with the smallest child
            heapifyDown(smallest);  // Recursively heapify down the smallest child
        }
    }

public:
    unsigned int size() { return heap.size(); }  // Return the current size of the heap
    bool empty() { return size() == 0; }  // Return true if the heap is empty
    int parent(int i) { return (i - 1) / 2; }  // Calculate the index of the parent
    int leftChild(int i) { return (2 * i + 1); }  // Calculate the index of the left child
    int rightChild(int i) { return (2 * i + 2); }  // Calculate the index of the right child

    // Insert an element into the heap and maintain the heap property
    void insert(int key) {
        heap.push_back(key);  // Add the new element to the heap
        int index = size() - 1;  // Get the index of the newly added element
        heapifyUp(index);  // Heapify up to maintain the heap property
    }

    // Insert multiple elements into the heap
    void insertMultiple(const vector<int>& values) {
        for (int value : values) {  // Loop through the values and insert each into the heap
            insert(value);
        }
    }

    // Delete the minimum element (root) from the heap
    void deleteMin() {
        if (size() == 0) return;  // If the heap is empty, do nothing
        heap[0] = heap.back();  // Replace the root with the last element
        heap.pop_back();  // Remove the last element
        heapifyDown(0);  // Heapify down to restore the heap property
    }

    // Get the minimum element (root) of the heap
    int getMin() { return size() == 0 ? -1 : heap.front(); }  // Return the root, or -1 if the heap is empty

    // Print the heap's elements
    void printHeap() {
        for (int i : heap)  // Loop through the heap and print each element
            cout << i << " ";
        cout << endl;
    }

    // Visualize the heap in a tree-like structure (recursive)
    void visualizeHeap(int index = 0, int depth = 0) {
        if (index >= size()) return;  // If the index is out of bounds, stop recursion

        visualizeHeap(rightChild(index), depth + 1);  // Recurse on the right child

        for (int i = 0; i < depth; ++i) cout << "    ";  // Print indentation for tree levels
        cout << heap[index] << endl;  // Print the current node

        visualizeHeap(leftChild(index), depth + 1);  // Recurse on the left child
    }
};

class MaxHeap {
    vector<int> heap;  // Vector to store the elements of the heap

    // Heapify up to maintain the heap property after insertion
    void heapifyUp(int index) {
        // Check if the current index is not the root and if the parent's value is less than the current element
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);  // Swap the current element with the parent
            heapifyUp(parent(index));  // Recursively heapify up the parent
        }
    }

    // Heapify down to maintain the heap property after deletion
    void heapifyDown(int index) {
        int left = leftChild(index);  // Index of the left child
        int right = rightChild(index);  // Index of the right child
        int largest = index;  // Assume the largest element is the current element

        // If the left child is greater than the current element, update largest
        if (left < size() && heap[left] > heap[index])
            largest = left;

        // If the right child is greater than the largest element, update largest
        if (right < size() && heap[right] > heap[largest])
            largest = right;

        // If the largest element is not the current element, swap and continue heapifying down
        if (largest != index) {
            swap(heap[index], heap[largest]);  // Swap with the largest child
            heapifyDown(largest);  // Recursively heapify down the largest child
        }
    }

public:
    unsigned int size() { return heap.size(); }  // Return the current size of the heap
    bool empty() { return size() == 0; }  // Return true if the heap is empty
    int parent(int i) { return (i - 1) / 2; }  // Calculate the index of the parent
    int leftChild(int i) { return (2 * i + 1); }  // Calculate the index of the left child
    int rightChild(int i) { return (2 * i + 2); }  // Calculate the index of the right child

    // Insert an element into the heap and maintain the heap property
    void insert(int key) {
        heap.push_back(key);  // Add the new element to the heap
        int index = size() - 1;  // Get the index of the newly added element
        heapifyUp(index);  // Heapify up to maintain the heap property
    }

    // Insert multiple elements into the heap
    void insertMultiple(const vector<int>& values) {
        for (int value : values) {  // Loop through the values and insert each into the heap
            insert(value);
        }
    }

    // Delete the maximum element (root) from the heap
    void deleteMax() {
        if (size() == 0) return;  // If the heap is empty, do nothing
        heap[0] = heap.back();  // Replace the root with the last element
        heap.pop_back();  // Remove the last element
        heapifyDown(0);  // Heapify down to restore the heap property
    }

    // Get the maximum element (root) of the heap
    int getMax() { return size() == 0 ? -1 : heap.front(); }  // Return the root, or -1 if the heap is empty

    // Print the heap's elements
    void printHeap() {
        for (int i : heap)  // Loop through the heap and print each element
            cout << i << " ";
        cout << endl;
    }

    // Visualize the heap in a tree-like structure (recursive)
    void visualizeHeap(int index = 0, int depth = 0) {
        if (index >= size()) return;  // If the index is out of bounds, stop recursion

        visualizeHeap(rightChild(index), depth + 1);  // Recurse on the right child

        for (int i = 0; i < depth; ++i) cout << "    ";  // Print indentation for tree levels
        cout << heap[index] << endl;  // Print the current node

        visualizeHeap(leftChild(index), depth + 1);  // Recurse on the left child
    }
};

// Function for user interaction with Min-Heap
void minHeapUserInteraction() {
    MinHeap heap;
    vector<int> defaultValues = {23, 45, 56, 78, 65, 98};  // Default values for the Min-Heap
    heap.insertMultiple(defaultValues);  // Insert the default values into the heap
    cout << "Default values added to the Min-Heap: 23, 45, 56, 78, 65, 98\n";

    int choice;
    string input;
    while (true) {
        cout << "\n--- Min-Heap Arena ---\n"
             << "1. Add Elements to Your Heap\n"
             << "2. Destroy the Smallest Priority\n"
             << "3. Reveal the Smallest Priority\n"
             << "4. Visualize the Heap\n"
             << "5. Exit the Arena\n"
             << "Enter your choice: ";
        cin >> choice;  // Get the user's choice
        cin.ignore();  // Ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter values to insert (separated by spaces): ";
                getline(cin, input);  // Get the input as a string
                {
                    stringstream ss(input);  // Create a stringstream to parse the input
                    vector<int> values;
                    int value;
                    while (ss >> value) {  // Read the values from the stringstream
                        values.push_back(value);  // Add them to the vector
                    }
                    heap.insertMultiple(values);  // Insert the values into the heap
                }
                cout << "Values inserted successfully.\n";
                break;
            case 2:
                heap.deleteMin();  // Delete the smallest priority element
                cout << "Smallest priority destroyed.\n";
                break;
            case 3:
                cout << "The smallest priority is: " << heap.getMin() << "\n";  // Reveal the smallest element
                break;
            case 4:
                cout << "Heap Visualization:\n";
                heap.visualizeHeap();  // Visualize the heap structure
                break;
            case 5:
                return;  // Exit the function
            default:
                cout << "Invalid choice!\n";  // Handle invalid input
        }
    }
}

// Function for user interaction with Max-Heap
void maxHeapUserInteraction() {
    MaxHeap heap;
    vector<int> defaultValues = {23, 45, 56, 78, 65, 98};  // Default values for the Max-Heap
    heap.insertMultiple(defaultValues);  // Insert the default values into the heap
    cout << "Default values added to the Max-Heap: 23, 45, 56, 78, 65, 98\n";

    int choice;
    string input;
    while (true) {
        cout << "\n--- Max-Heap Arena ---\n"
             << "1. Add Elements to Your Heap\n"
             << "2. Destroy the Largest Priority\n"
             << "3. Reveal the Largest Priority\n"
             << "4. Visualize the Heap\n"
             << "5. Exit the Arena\n"
             << "Enter your choice: ";
        cin >> choice;  // Get the user's choice
        cin.ignore();  // Ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter values to insert (separated by spaces): ";
                getline(cin, input);  // Get the input as a string
                {
                    stringstream ss(input);  // Create a stringstream to parse the input
                    vector<int> values;
                    int value;
                    while (ss >> value) {  // Read the values from the stringstream
                        values.push_back(value);  // Add them to the vector
                    }
                    heap.insertMultiple(values);  // Insert the values into the heap
                }
                cout << "Values inserted successfully.\n";
                break;
            case 2:
                heap.deleteMax();  // Delete the largest priority element
                cout << "Largest priority destroyed.\n";
                break;
            case 3:
                cout << "The largest priority is: " << heap.getMax() << "\n";  // Reveal the largest element
                break;
            case 4:
                cout << "Heap Visualization:\n";
                heap.visualizeHeap();  // Visualize the heap structure
                break;
            case 5:
                return;  // Exit the function
            default:
                cout << "Invalid choice!\n";  // Handle invalid input
        }
    }
}

int main() {
    cout << "Welcome to HeapMaster: Prioritize Your Data!\n";
    cout << "Choose Your Heap Kingdom:\n"
         << "1. Min-Heap (Minimizing Your Chaos)\n"
         << "2. Max-Heap (Maximizing Your Gains)\n"
         << "Enter your choice: ";

    int choice;
    cin >> choice;  // Get the user's choice

    if (choice == 1) {
        minHeapUserInteraction();  // Call the Min-Heap interaction function
    } else if (choice == 2) {
        maxHeapUserInteraction();  // Call the Max-Heap interaction function
    } else {
        cout << "Invalid choice!\n";  // Handle invalid input
    }

    return 0;
}
