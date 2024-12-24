#include <iostream>
using namespace std;

class LQueue {
    typedef int ElemType;

private:
    struct QNode {
        ElemType data;
        QNode* next;
    };
    QNode* front;
    QNode* rear;

public:
    LQueue() {
        front = new QNode;
        front->next = nullptr;
        rear = front;
    }
    ~LQueue() {
        destroyQueue();
    }

    bool getFront(ElemType& e) const {
        if (isEmpty()) {
            cerr << "Error: Queue is empty." << endl;
            return false;
        }
        e = front->next->data;
        return true;
    }

    void enQueue(ElemType e) {
        QNode *newNode = new QNode;
        newNode->data = e;
        newNode->next = nullptr;
        rear->next = newNode;
        rear = newNode;
    }

    bool deQueue(ElemType &e) {
        if (isEmpty()) {
            cerr << "Error: Queue is empty." << endl;
            return false;
        }
        QNode* temp = front->next;
        e = temp->data;
        front->next = temp->next;
        if (rear == temp) {
            rear = front;
        }
        delete temp;
        return true;
    }

    bool isEmpty() const {
        return front == rear;
    }

    void destroyQueue() {
        while (front != nullptr) {
            QNode* temp = front->next;
            delete front;
            front = temp;
        }
        rear = nullptr;
    }
};

class DQueue {
    typedef int QElemType;
    typedef int Position;

private:
    int capacity;
    Position front;
    Position rear;
    QElemType *data;

public:
    DQueue(int qsize = 10) {
        capacity = qsize + 1;
        data = new QElemType[capacity];
        front = rear = 0;
    }

    ~DQueue() {
        delete[] data;
    }

    bool isEmpty() const {
        return rear == front;
    }

    bool isFull() const {
        return (rear + 1) % capacity == front;
    }

    bool enQueueFront(QElemType x) {
        if (isFull()) {
            cerr << "Error: Queue is full." << endl;
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = x;
        return true;
    }

    bool deQueueFront(QElemType &x) {
        if (isEmpty()) {
            cerr << "Error: Queue is empty." << endl;
            return false;
        }
        x = data[front];
        front = (front + 1) % capacity;
        return true;
    }

    bool enQueueBack(QElemType x) {
        if (isFull()) {
            cerr << "Error: Queue is full." << endl;
            return false;
        }
        data[rear] = x;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deQueueBack(QElemType &x) {
        if (isEmpty()) {
            cerr << "Error: Queue is empty." << endl;
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        x = data[rear];
        return true;
    }
};