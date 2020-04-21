#include <iostream>
#include <memory>

#ifndef MYLIST4STUDENTS_MYLIST_H
#define MYLIST4STUDENTS_MYLIST_H

template<typename T>
class MyList {
public:
    /** Node */
    struct Node {
        T value;
        std::unique_ptr<Node> next;
    public:
        Node(T value): value(value), next(nullptr) {}
    };
    /** Iterator */
    struct Iterator {
        typedef Iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
    public:
        Node* node = nullptr;
        Iterator(Node* node=nullptr): node(node) {}

        reference operator*() const { return node->value; }
        pointer operator->() const { return &(node->value); }
        self_type& operator++() {
            node = node->next.get();
            return *this;
        }
        self_type operator++(int) {
            auto res = *this;
            node = node->next.get();
            return res;
        }
        bool operator==(const Iterator& other) const { return this->node == other.node; }
        bool operator!=(const Iterator& other) const { return this->node != other.node; }

        friend class MyList;
    };
    struct ConstIterator {
        typedef ConstIterator self_type;
        typedef T value_type;
        typedef const T& reference;
        typedef const T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
    public:
        Node* node = nullptr;
        ConstIterator(Node* node=nullptr): node(node) {}

        reference operator*() const { return node->value; }
        pointer operator->() const { return &(node->value); }
        self_type& operator++() {
            node = node->next.get();
            return *this;
        }
        self_type operator++(int) {
            auto res = *this;
            node = node->next.get();
            return res;
        }
        bool operator==(const ConstIterator& other) const { return this->node == other.node; }
        bool operator!=(const ConstIterator& other) const { return this->node != other.node; }

        friend class MyList;
    };
    /** MyList */
    typedef T value_type;
    std::unique_ptr<Node> head;
    MyList(): head(nullptr) {}
    MyList(const MyList& otherList) = delete;

    void push_front(T newValue);
    T pop_front();
    T front() const { return head->value; }
    void remove(T valToRemove);
    size_t size() const;

    Iterator begin() { return Iterator(head.get()); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator begin() const { return ConstIterator(head.get()); }
    ConstIterator end() const { return ConstIterator(nullptr); }

    MyList& operator=(MyList& otherList) = delete;
    template<class Y>
    friend std::ostream& operator<<(std::ostream& out, const MyList<Y>& list);

    ~MyList() {
        while(head) {
            head = std::move(head->next);
        }
    }
};

/** MyList section */
template<typename T>
void MyList<T>::push_front(T newValue) {
    auto newNode = std::make_unique<Node>(newValue);
    if(head) {
        newNode->next = std::move(head);
    }
    head = std::move(newNode);
}

template<typename T>
T MyList<T>::pop_front() {
    if(!head) {
        throw std::out_of_range("List has already come to an end\n");
    }
    T res = head->value;
    head = std::move(head->next);
    return res;
}

template<typename T>
size_t MyList<T>::size() const{
    size_t res = 0;
    for(auto it = this->begin(); it != this->end(); ++it) {
        res++;
    }
    return res;
}

template<typename T>
void MyList<T>::remove(T valToRemove) {
    while(head) {
        if(head->value == valToRemove) {
            head = std::move(head->next);
        } else {
            break;
        }
    }
    if(!head) {
        return;
    }
    Node* curr = head.get();
    while(curr->next) {
        if(curr->next->value == valToRemove) {
            curr->next = std::move(curr->next->next);
        } else{
            curr = curr->next.get();
        }
    }
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const MyList<T>& list) {
    auto it = list.begin();
    out<<"[ "<<*it;
    ++it;
    for(it; it != list.end(); ++it) {
        out<<", "<<*it;
    }
    out<<" ]"<<std::endl;
    return out;
}

#endif //MYLIST4STUDENTS_MYLIST_H