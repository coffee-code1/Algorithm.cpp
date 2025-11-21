#include <iostream>
using namespace std;

class MyQueue {
private:
    int *data;      // 存储数据的数组
    int front;      // 队头指针
    int rear;       // 队尾指针
    int currentSize; // 当前队列大小（避免命名冲突）
    int capacity;   // 队列容量

public:
    // 构造函数
    MyQueue(int x) {
        capacity = x;
        data = new int[capacity];
        front = 0;
        rear = 0;
        currentSize = 0;
    }

    // 析构函数（防止内存泄漏）
    ~MyQueue() {
        delete[] data;
    }

    // 获取队列大小
    int getSize() {
        return currentSize;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return currentSize == 0;
    }

    // 判断队列是否已满
    bool isFull() {
        return currentSize == capacity;
    }

    // 入队操作
    void push(int x) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        data[rear] = x;
        rear = (rear + 1) % capacity;  // 循环队列
        currentSize++;
    }

    // 出队操作
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;  // 循环队列
        currentSize--;
    }

    // 获取队头元素
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;  // 返回错误值
        }
        return data[front];
    }

    // 打印队列（用于调试）
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue: ";
        int count = 0;
        int index = front;
        
        while (count < currentSize) {
            cout << data[index] << " ";
            index = (index + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};