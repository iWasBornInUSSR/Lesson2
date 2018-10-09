
#ifndef LESSON2_SETASLIST_H
#define LESSON2_SETASLIST_H

#include <cstdlib>
#include <iostream>
// head is Node or another class???
using namespace std;
struct Node {
    Node *next;
    char info;
};

class SetAsList {
private:
    static int N;
    int n;
    char S;
    Node *head = nullptr;

    void createHead();

    void add(char);
    //friend void addAllToList(SetAsList::nodeHead *head, char *array);
    //friend void freeAll(SetAsList::nodeHead *head);
public:

    SetAsList();

    explicit SetAsList(char s);

    SetAsList(const SetAsList &);

    void show();

    SetAsList &operator|=(const SetAsList &B);

    SetAsList operator|(const SetAsList &B) const;

    SetAsList operator&(const SetAsList &);

    SetAsList &operator&=(const SetAsList &);

    SetAsList &operator=(const SetAsList &);

    virtual ~SetAsList();
};

//default constructor
SetAsList::SetAsList() : S('0'), n(0), head(new Node) { cout << "List " << S << " constructed" << endl; }

//init random list
SetAsList::SetAsList(char s) : S(s), n(0), head(new Node) {
    for (int i = 0; i < N; i++)
        if (rand() % 2) add(i + 'A');
    cout << "List " << S << " constructed" << endl;
}

//init with co
SetAsList::SetAsList(const SetAsList &copy) {
    head = new Node();
    S = copy.S;
    n = copy.n;
    for (Node *i = copy.head->next; i != nullptr; i = i->next) {
        add(i->info);
    }
    cout << "List " << S << " constructed with copy " << copy.S << endl;
}

//! конструктор для копирования с переносом?
//operators
SetAsList &SetAsList::operator=(const SetAsList &copy) {
    n = copy.n;
    //cleaning old data in object
    Node *c;
    Node *p = head->next;
    while (p != nullptr) {
        c = p->next;
        delete (p);
        p = c;
    }
    head->next = nullptr;
    // adding new data
    for (Node *i = copy.head->next; i != nullptr; i = i->next) {
        add(i->info);
    }
    return *this;
}

SetAsList &SetAsList::operator|=(const SetAsList &B) {

    for (Node *b = B.head->next; b != nullptr; b = b->next) {
        int flag = 1;
        for (Node *a = head->next; a != nullptr; a = a->next) {
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

SetAsList SetAsList::operator|(const SetAsList &B) const {
    SetAsList C(*this);
    return (C |= B);
}

SetAsList &SetAsList::operator&=(const SetAsList &B) {
    int flag;
    SetAsList C();
    for (Node *b = B.head->next; b != nullptr; b = b->next) {
        flag = 0;
        for (Node *a = head->next; a != nullptr; a = a->next) {
            if (a->info == b->info) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            add(b->info);
        }
    }
    return (*this);

}

void SetAsList::show() {

    cout << "List id:" << S << " List content:" << endl;
    for (Node *i = head->next; i != nullptr; i = i->next) {
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
    Node *node = new Node();
    //SetAsList::Node *newNode = (SetAsList::Node *) malloc(sizeof(SetAsList::Node));
    node->next = nullptr;
    node->info = charInfo;
    // add to List
    if (head->next == nullptr)
        head->next = node;  //warning conditional jump or depends on uninitialised value
    else {
        Node *endNode = head->next;
        while (endNode->next != nullptr)
            endNode = endNode->next;
        endNode->next = node;
    }
}

//destructor
SetAsList::~SetAsList() {
    Node *c;
    Node *p = head->next;
    while (p != nullptr) {
        c = p->next;
        delete (p);
        p = c;
    }
    delete (head);
    cout << "List " << S << " deleted" << endl;
}
/*void freeAll(SetAsList::head) {

        Node *c;
        Node *p = Set.head->next;
        while (p != nullptr) {
            c = p->next;
            free(p);
            p = c;
        }
        free(Set.head);

}*/
#endif //LESSON2_SETASLIST_H
