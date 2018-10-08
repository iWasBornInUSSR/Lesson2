
#ifndef LESSON2_SETASLIST_H
#define LESSON2_SETASLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;

class SetAsList {
private:
    static int N;
    int n;
    char S;
    struct Node {
        Node *next;
        char info;
    };
    Node *head = nullptr;
    void createHead();

    void add(char);
    //friend void addAllToList(SetAsList::nodeHead *head, char *array);
    //friend void freeAll(SetAsList::nodeHead *head);
public:
    SetAsList();

    explicit SetAsList(char s);

    explicit SetAsList(const SetAsList &);
    void show();

    SetAsList &operator&=(const SetAsList &B);

    SetAsList SetAsList::operator&(const SetAsList &B) const;
};

//default constructor
SetAsList::SetAsList() : S('0'), n(0), head(new Node) {
    add('0');
}

//init random list
SetAsList::SetAsList(char s) : S(s), n(0), head(new Node) {
    for (int i = 0; i < N; i++)
        if (rand() % 2) add(i + 'A');
}

//init with co
SetAsList::SetAsList(const SetAsList &copy) {
    *head = *copy.head;
    S = copy.S;
    n = copy.n;
    for (Node *i = copy.head; i != nullptr; i = i->next) {
        add(i->info);
    }
}

//! конструктор для копирования с переносом?
SetAsList &SetAsList::operator&=(const SetAsList &B) {
    int flag;
    for (Node *b = B.head; b != nullptr; b = b->next) {
        flag = 1;
        for (Node *a = head; a != nullptr; a = a->next) {
            if (a->info == b->info) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            add(b->info);
        }
    }
    return (*this);
}

SetAsList SetAsList::operator&(const SetAsList &B) const {
    SetAsList C(*this);
    return (C &= B);
}
void SetAsList::createHead() {

    //SetAsList::nodeHead *head = (SetAsList::nodeHead *) malloc(sizeof(SetAsList::nodeHead));
    this->head = new Node();
    head = nullptr;
}
void SetAsList::show() {

    cout << "List realization:" << endl;
    for (SetAsList::Node *i = head; i != nullptr; i = i->next) {
        cout << i->info << " ";
    }
    cout << endl;
}
/*void addAllToList(SetAsList::nodeHead *head, char *array) {
    for (int i = 0; array[i]; ++i) {
        SetAsList::Node *node;
        node = createNode(array[i]);
        add(head,node);
    }
}*/

/*void checkLinList(SetAsList::nodeHead *head)
{
    struct SetAsList::Node *p = head->first;
    while (p != nullptr)
    {   printf("it contain: %c\n",p->info);
        if(p->next == nullptr)
            printf("next: NULL ");
        else
            printf("next: %c ",p->next->info);
        printf("\n");
        p = p->next;
    }
    printf("-------------------------------\n");
}*/
void SetAsList::add(char charInfo) {
    //update counter
    n++;
    // create Node
    SetAsList::Node *node = new SetAsList::Node();
    //SetAsList::Node *newNode = (SetAsList::Node *) malloc(sizeof(SetAsList::Node));
    node->next = nullptr;
    node->info = charInfo;
    // add to List
    if (head == nullptr)
        head = node;
    else {
        SetAsList::Node *endNode = head;
        while (endNode->next != nullptr)
            endNode = endNode->next;
        endNode->next = node;
    }
}
/*void freeAll(SetAsList::nodeHead *head) {
    SetAsList::Node *c;
    SetAsList::Node *p = head->first;
    while (p != nullptr) {
        c = p->next;
        free(p);
        p = c;
    }
    free(head);
}*/
#endif //LESSON2_SETASLIST_H
