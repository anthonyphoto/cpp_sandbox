#include<iostream>
#include<vector>
using namespace std;

class Queue {
    public: 
        virtual ~Queue() {  // 얘는 abstract가 안됨
            cout << "Destructor: Queue" << endl;
        }
        // {

        // };
        virtual void pushBack(int val) = 0;
        virtual int at(int ind) = 0;
        // virtual void printInfo() = 0;
};

struct Item {
    int val;
    Item* next;
    Item(int v) {
        val = v;
        next = NULL;
    }
};

class LinkedList: public Queue {
    public:
        LinkedList() {
            head = NULL;
        }
        ~LinkedList() {
            cout << "Destrctor: LinkedList" << endl;
            Item* tmp = head;
            
            while(tmp != NULL) {
                Item* prev = tmp;
                tmp = tmp->next;
                delete prev;
            }
        }
        void pushBack(int val) {
            Item* item = new Item(val);
            if (head == NULL) {
                head = item;
                return;
            }
            Item* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = item;
        }
        int at(int ind) {
            Item* tmp = head;
            for (int i = 0; i < ind; i++){
                if (tmp->next == NULL) return -1;
                tmp = tmp->next;
            }
            return tmp->val;

        }
        // void printInfo(){
        //     Item* tmp = head;
        //     while(tmp != NULL) {
        //         cout << tmp->val << " ";
        //         tmp = tmp->next;
        //     }
        //     cout << endl;
        // }
    private:
        Item* head;
};

class MyVector: public Queue {
    public:
        ~MyVector() {
            cout << "Destructor: MyVector" << endl;
        }
        void pushBack(int val) {
            v_.push_back(val);
        }
        // void printInfo() {
        //     for (unsigned int i = 0; i < v_.size(); i++) {
        //         cout << v_[i] << " ";
        //     }
        //     cout << endl;
        // }
        int at(int ind) {
            return v_[ind];
        }

        int getFirstItem(){
            return v_.size() == 0 ? -1 : v_[0];
        }

    private:
        vector<int> v_;
};

void makeDouble(Queue* q) {
    for (int i = 0; i < 3; i++) {
        cout << q->at(i) * 2 << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    // LinkedList ll;
    // Queue* q1 = &ll;
    // Queue q;    //에러 abstract가 하나라도 있으면 안됨
    Queue* q1 = new LinkedList;
    q1->pushBack(1);
    q1->pushBack(2);
    q1->pushBack(3);
    makeDouble(q1);

    // q1->printInfo();
    
    MyVector* v = new MyVector;
    Queue* q2 = v;
    q2->pushBack(1);
    q2->pushBack(2);
    q2->pushBack(3);
    makeDouble(q2);

    // q2->printInfo();
    // cout << q2->getFirstItem() << endl;
    cout << v->getFirstItem() << endl;  // 상송된거에만 적용됨

    

    delete q1;
    delete q2;

    return 0;
}