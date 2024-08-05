#include <iostream>
using namespace std;

class vector{
 public:
    int size;
    int capacity;
    int *arr;
  vector(){
    size = 0;
    capacity = 1;
    arr = new int[1];
  }
  // for create a array and increase size.
  void add(int ele){
    if(size==capacity){
        capacity*=2;
        int * arr2 = new int[capacity];
        for(int i=0 ; i<size ; i++){
            arr2[i] = arr[i];
        }
        arr = arr2;
    }
    arr[size++] = ele;
  }

 // for print the whole array.
  void print(){
    for(int i=0 ; i<size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
  }
 // for getting the indexed value.
  void get(int idx){
    if(size == 0){
        cout << "vector is empty" << endl;
    }
    else if(idx>=size || idx<0){
        cout << "invalid index"<< endl;
    }
    else cout << arr[idx] << endl;
  }

  //for removing the ele from array
  void remove(){
    if(size == 0){
        cout << "vector is empty" << endl;
    }
    size--;
  }
};

int main(){
    vector v;
    cout << v.size << " " << v.capacity << endl;//0 1
    v.add(10);
    v.print();
     cout << v.size << " " << v.capacity << endl;//1 1
    v.add(20);
    v.print();
     cout << v.size << " " << v.capacity << endl;//2 2
    v.add(30);
    v.print();
     cout << v.size << " " << v.capacity << endl;//3 4
    v.add(40);
    v.print();
     cout << v.size << " " << v.capacity << endl;//4 4
    // to get the indexed value.
    v.get(10);
    v.get(3);
    // to remove.
    v.remove();
    v.print();
 return 0;
}