#include <iostream>
using namespace std;

class vector {
public:
    int size;
    int capacity;
    int* arr;

    vector() {
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    ~vector() {
        delete[] arr;
    }

    void add(int ele) {
        if (size == capacity) {
            capacity *= 2;
            int* arr2 = new int[capacity];
            for (int i = 0; i < size; ++i) {
                arr2[i] = arr[i];
            }
            delete[] arr;
            arr = arr2;
        }
        arr[size++] = ele;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void get(int idx) {
        if (size == 0) {
            cout << "vector is empty" << endl;
        } else if (idx >= size || idx < 0) {
            cout << "invalid index" << endl;
        } else {
            cout << arr[idx] << endl;
        }
    }

    void remove() {
        if (size == 0) {
            cout << "vector is empty" << endl;
            return;
        }
        size--;
    }
};

int main() {
    vector v;
    cout << v.size << " " << v.capacity << endl;
    v.add(10);
    v.print();
    cout << v.size << " " << v.capacity << endl;
    v.add(20);
    v.print();
    cout << v.size << " " << v.capacity << endl;
    v.add(30);
    v.print();
    cout << v.size << " " << v.capacity << endl;
    v.add(40);
    v.print();
    cout << v.size << " " << v.capacity << endl;

    v.get(10);
    v.get(3);

    v.remove();
    v.print();
    return 0;
}
