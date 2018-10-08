
#ifndef LESSON2_SETASLIST_H
#define LESSON2_SETASLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;

class SetAsList {
private:
    static int N;
    int n;
    struct Node {
        Node *next;
        char info;
    };
    Node *head = nullptr;

    void createHead();

    friend SetAsList::Node *createNode(char charInfo);

    void add(SetAsList::Node *node);
    //friend void addAllToList(SetAsList::nodeHead *head, char *array);
    //friend void freeAll(SetAsList::nodeHead *head);
public:
    SetAsList();
    void show();

};

SetAsList::SetAsList() {

}

void SetAsList::createHead() {

    //SetAsList::nodeHead *head = (SetAsList::nodeHead *) malloc(sizeof(SetAsList::nodeHead));
    this->head = new Node();
    head = nullptr;
}

SetAsList::Node *createNode(char charInfo) {

    //SetAsList::Node *newNode = (SetAsList::Node *) malloc(sizeof(SetAsList::Node));
    SetAsList::Node *newNode = new SetAsList::Node();
    newNode->next = nullptr;
    newNode->info = charInfo;
    return newNode;
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
void SetAsList::add(SetAsList::Node *node) {
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
