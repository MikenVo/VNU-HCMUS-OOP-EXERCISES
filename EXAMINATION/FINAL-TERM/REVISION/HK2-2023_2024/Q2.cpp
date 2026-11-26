#include <iostream>
#include <vector>
using namespace std;

class IStack {
public:
    virtual ~IStack() {};

    virtual void push(int newnum) = 0;
    virtual int pop() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
};

class IntStack : public IStack {
private:
    std::vector<int> stack;

public:
    void push(int newnum) override {
        stack.push_back(newnum);
    }

    int pop() override {
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    int size() override {
        return stack.size();
    }

    void clear() override {
        stack.clear();
    }

    ~IntStack() override {
        stack.clear();
    }
};

struct Node {
    int data;
    Node* next;

    Node(int num, Node* nextp) : data(num), next(nextp) {}
};

class StackByLinkedList : public IStack {
private:
    Node* head;
    int count = 0;
    void AddHead(int data) {
        Node* newnode = new Node(data, nullptr);
        if (head == nullptr) {
            head = newnode;
            count++;
            return;
        }

        newnode->next = head;
        head = newnode;
        count++;
    }

    void RemoveHead() {
        if (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
            count--;
        }
    }

public:
    void push(int newnum) override {
        AddHead(newnum);
    }

    int pop() override {
        int top = head->data;
        RemoveHead();
        return top;
    }

    int size() override {
        return count;
    }

    void clear() override {
        if (head != nullptr) {
            Node* temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
            count = 0;
            temp = nullptr;
        }
    }

    ~StackByLinkedList() override {
        if (head != nullptr) {
            clear();
        }
    }
};