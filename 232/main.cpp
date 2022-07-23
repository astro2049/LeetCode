#include <iostream>
#include "stack"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyQueue {
public:
    stack<int> aux;
    stack<int> worker;

    MyQueue() {
    }

    void push(int x) {
        while (!worker.empty()) {
            int val = worker.top();
            aux.push(val);
            worker.pop();
        }
        worker.push(x);
        while (!aux.empty()) {
            int val = aux.top();
            worker.push(val);
            aux.pop();
        }
    }

    int pop() {
        int returnVal = worker.top();
        worker.pop();
        while (!worker.empty()) {
            int val = worker.top();
            aux.push(val);
            worker.pop();
        }
        while (!aux.empty()) {
            int val = aux.top();
            worker.push(val);
            aux.pop();
        }
        return returnVal;
    }

    int peek() {
        return worker.top();
    }

    bool empty() {
        return worker.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
