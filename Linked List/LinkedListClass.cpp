#include <bits/stdc++.h>
using namespace std;

template <class t>
class LinkedList {
    class Node {
    public:
        t data;
        Node* next;
    };

    Node* start;
    int len;

public:
    LinkedList() : start(nullptr), len(0) {}

    ~LinkedList() {
        Node* current = start;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    t push_back(t data) {
        if (start == nullptr) {
            start = new Node{data, nullptr};
            len = 1;
            return data;
        }

        Node* itr = start;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = new Node{data, nullptr};
        len++;

        return data;
    }

    t push_front(t data)
    {
        if (start == nullptr) {
            start = new Node{data, nullptr};
            len = 1;
            return data;
        }

        Node* itr = new Node{data, start};
        start = itr;

        return data;
    }

    void insert(int ind, t data) {
        if (ind < 0 || ind > len) {
            cerr << "Invalid index." << endl;
            return;
        }

        if (ind == 0) {
            Node* n = new Node{data, start};
            start = n;
            len++;
            return;
        }

        Node* itr = start;
        for (int i = 0; i < ind - 1; ++i) {
            itr = itr->next;
        }

        Node* n = new Node{data, itr->next};
        itr->next = n;
        len++;
    }

    int size() const {
        return len;
    }

    friend ostream& operator<< (ostream& os, const LinkedList& l) {
        Node* itr = l.start;
        while (itr != nullptr) {
            os << itr->data << ' ';
            itr = itr->next;
        }
        return os;
    }
};

int main() {
    LinkedList<string> ls;

    ls.push_back("anna");
    ls.push_back("joe");
    ls.push_back("kevin");
    ls.push_back("alice");

    cout << ls.size() << endl;
    cout << ls;

    cout << endl;

    ls.insert(2, "bob");
    ls.push_front("allen");
    cout << ls;
}
