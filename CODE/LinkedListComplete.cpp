#include<bits/stdc++.h>
using namespace std;

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} Node;

Node*createNode(int data, Node*next) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = next;
    return temp;
}
Node* addElement(int data, Node* head) {
    if (head == NULL) {
        head = createNode(data, NULL);
    }
    else {
        Node*temp = head;
        while (temp->next != NULL)temp = temp->next;
        temp->next = createNode(data, NULL);
    }
    return head;
}
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int middleElement(Node *head) {
    // Node *sp = head,*fp = head;
    // auto can be used to describe functions return type
    auto sp = head, fp = head;
    while (fp != NULL && fp->next != NULL) {
        fp = fp->next->next;
        sp = sp->next;
    }
    return sp->data;
}
Node* deleteMiddle(Node *head) {
    auto sp = head, fp = head, prev = sp;
    while (fp && fp->next) {
        prev = sp;
        fp = fp->next->next;
        sp = sp->next;
    }
    prev->next = sp->next;
    delete sp;
    return head;
}
int sizeofList(Node *head) {
    auto temp = head;
    int cnt = 0;
    while (temp)cnt++, temp = temp->next;
    return cnt;
}
Node* deleteList(Node *head) {
    auto prev = head;
    head = head->next;
    if (head == NULL)delete prev;
    while (head != NULL) {
        delete prev;
        prev = head;
        head = head->next;
    }
    return head;
}
void printReverse(Node *head) {
    // using recursion inbuilt stack
    if (head == NULL)return;
    printReverse(head->next);
    cout << head->data << " ";
}
Node* reverseList(Node *head) {
    //   1 2 3 4
    // p c
    //   n
    /*  1->2->3
        p  c  n   =>  c.next = p and so..
    */
    auto cur = head, next = head;
    Node *prev = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev; // ***
}
bool isPalin(Node *&left, Node *right) {
    if (right == NULL)return 1;
    if (!isPalin(left, right->next))return 0;
    bool check = (left->data == right->data);
    left = left->next;
    // to change left, we pass by reference..
    return check;
}
Node* removeDuplicatesSorted(Node *head) {
    // 1->2->2->3->4;
    auto cur = head;
    while (cur->next != NULL) {
        if (cur->data == cur->next->data) {
            // delete next;
            auto temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        else cur = cur->next;
    }
    return head;

}
Node* removeDuplicates(Node *head) {
    map<int, int> vs;
    auto cur = head, prev = head;
    while (cur) {
        if (vs[cur->data]) {
            prev->next = cur->next;
            delete cur;
        }
        else {
            vs[cur->data] = 1;
            prev = cur;
        }
        cur = prev->next;
    }
    return head;
}
bool detectLoop(Node *head) {
    // fp!null fp.n!null.. fp+=2, sp++ if(equal)return 1;

    auto fp = head, sp = head;
    while (fp != NULL && fp->next != NULL) {
        fp = fp->next->next;
        sp = sp->next;
        if (sp == fp)return 1;
    }
    return 0;
}
Node* removeLoop(Node *head) {
    auto fp = head, sp = head;
    while (fp && fp->next) {
        fp = fp->next->next;
        sp = sp->next;
        if (sp == fp) {
            sp = head;
            while (sp->next != fp->next) {
                fp = fp->next;
                sp = sp->next;
            }
            fp->next = NULL;
            return head;
        }
    }
    return head;
}
int intersectionPoint(Node *head1, Node *head2) {
    auto cur1 = head1, cur2 = head2;
    while (cur1 != cur2) {
        if (cur1 == NULL)cur1 = head2;
        if (cur2 == NULL)cur2 = head1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1->data;
}
Node* odd_even(Node *head) {
    // 1 2 3 4 5
    // 1 3 5o
    // 2 4e
    auto o = head, e = head->next, temp = e;
    while (e && e->next) {
        o->next = e->next;
        o = o->next;
        e->next = o->next;
        e = e->next;
    }
    o->next = temp;
    return head;
}
Node* merge(Node *h1, Node *h2) {
    if (h1 == NULL || h2 == NULL) {
        return (h1 == NULL) ? h2 : h1;
    }
    if (h1->data < h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}
Node* mergeSort(Node *head) {
    if (head == NULL || head->next == NULL)return head;
    auto sp = head, fp = head, prev = sp;
    while (fp && fp->next) {
        prev = sp;
        fp = fp->next->next;
        sp = sp->next;
    }
    prev->next = NULL;
    // head is different list, sp is different list
    Node *h1 = mergeSort(head);
    auto h2 = mergeSort(sp);
    return merge(h1, h2);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Linked List is : \n";
    Node *head = NULL;
    head = addElement(1, head);
    head = addElement(2, head);
    head = addElement(2, head);
    head = addElement(4, head);
    head = addElement(5, head);
    printList(head);
    cout << "Middle Element is : " << middleElement(head) << endl;
    deleteMiddle(head);
    cout << "List after middle element died : ";
    printList(head);
    head = deleteList(head);
    cout << "The whole list is now dead LOL: ";
    printList(head);
    cout << "Can You see the list?? -> size of list = " << sizeofList(head) << endl;
    cout << "Adding some element in list since list is dead... \n";
    for (int i = 1; i <= 5; i++) {
        head = addElement(i, head);
    }
    cout << "New revived list : ";
    printList(head);
    cout << "Here's a recursively reversed list : ";
    printReverse(head);
    cout << "\nLOL the linked is really reversed now.. XD : ";
    head = reverseList(head);
    printList(head);
    cout << "Turn back to normal list : ";
    head = reverseList(head);
    printList(head);
    for (int i = 5; i >= 1; i--) {
        head = addElement(i, head);
    }
    cout << "Checking if its palindrome : ";
    auto temp = head;
    // *If pass head reference directly then the head will change
    cout << isPalin(temp, temp) << endl;
    printList(head);
    head = removeDuplicatesSorted(head);
    printList(head);
    head = removeDuplicates(head);
    printList(head);
    cout << "So That was removal of duplicates huh\n";
    cout << "Is there a Loop in our linked list : " << detectLoop(head) << endl;
    cout << "Creating loop...\n";
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // temp->data = 5;
    temp->next = head->next->next;
    cout << "Now checking loop.. : " << detectLoop(head) << endl;
    cout << "Loop Detected!! Now removing loop...\n";
    head = removeLoop(head);
    printList(head);
    cout << "detecting loop after removal : " << detectLoop(head) << endl;

    cout << "Making new linked  list...\n";
    Node *head2 = NULL;
    for (int i = 1; i <= 3; i++)head2 = addElement(3, head2);
    temp = head;
    while (temp->data != 3) {
        temp = temp->next;
    }
    auto cur = head2;
    while (cur->next)cur = cur->next;
    cur->next = temp;
    cout << "Intersection Point (3) : " << intersectionPoint(head, head2) << endl;

    cout << "Odd Even Linked list :\n";
    head = odd_even(head);
    printList(head);
    for (int i = 1; i <= 5; i++)head = addElement(i, head);

    printList(head);
    head = mergeSort(head);
    cout << "Sorted List : ";
    printList(head);
    return 0;
}
