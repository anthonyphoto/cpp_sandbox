#include <iostream>
using namespace std;

template <typename T>
struct Item {
    T val;
    Item<T> *next;
    Item() {
        next = NULL;
    };
    Item(T v) {
        val = v;
        next = NULL;
    };
};

template <typename T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void add(T val);
        void print();
        void removeHead();
        void addNth(T val, int index);
    private:
        Item<T> *head;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}
template <typename T>
void LinkedList<T>::add(T val) {
    if (head) {
        Item<T> *tmp = head;
        while (tmp->next) {     // tmp->next != NULL 하고 같나?
            tmp = tmp->next;
        }
        
        tmp->next = new Item<T>;
        tmp->next->val = val;
        tmp->next->next = NULL;

    } else {
        Item<T> *newItem = new Item<T>;
        newItem->val = val;
        newItem->next = NULL;
        head = newItem;
    }
}

template <typename T>
void LinkedList<T>::addNth(T val, int index) {
    if (index == 0) {
        Item<T> *newItem = new Item<T>(val);
        newItem->next = head;
        head = newItem;

    } else {
        Item<T> *tmp = head;
        int i = 0;
        while (tmp->next && i != index - 1) {
            // cout << "--" << i << endl;
            tmp = tmp->next;
            i++;
        }
        if (i != index - 1) {
            cout << "ERR: invalid index" << endl;
            return;
        }
        Item<T>* newItem = new Item<T>(val);
        newItem->next = tmp->next;
        tmp->next = newItem;
        // cout << "To replace" << tmp->val << endl;

    }

    // if (index == 0) {
    //     Item* newItem = new Item(val);
    //     newItem->next = head->next;
    //     head = newItem;
    // }
}
template <typename T>
void LinkedList<T>::removeHead() {
    Item<T> *tmp = head;
    head = head->next;
    delete tmp;
}

template <typename T>
void LinkedList<T>::print(){
    Item<T> *tmp = head;

    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main() {
    LinkedList<int> ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    // ll.removeHead();
    ll.print();
    // ll.addNth(9, 0);
    // ll.print();
    ll.addNth(9, 3);
    ll.print();




    return 0;
}