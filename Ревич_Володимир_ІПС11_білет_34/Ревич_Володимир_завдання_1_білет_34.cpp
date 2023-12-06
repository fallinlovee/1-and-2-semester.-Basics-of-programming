#include <iostream>
#include <math.h>
using namespace std;

struct node {
    int data;
    node* next;
};

void addListLast(node** head, int data) {
    node* temp;
    if (!*head) {
        temp = new node;
        temp->data = data;
        temp->next = NULL;
        *head = temp;
    } else {
        node* current = *head;
        while (current->next) {
            current = current->next;
        }
        temp = new node;
        temp->data = data;
        temp->next = NULL;
        current->next = temp;
    }
}

void moveSmallest(node** head) {
	
    if (!*head || !(*head)->next) 
        return;
    

    // «находимо найменший елемент та його попередник
    node* Prev = NULL;
    node* smallest = *head;
    node* current = *head;
    while (current->next) {
    	
    if (current->next->data < smallest->data) {
    	
            Prev = current;
            smallest = current->next;
            
        }
        current = current->next;
    }

    // якщо найменший елемент вже знаходитьс€ на початку списку, немаЇ потреби в перем≥щенн≥.
    if (smallest == *head) {
        return;
    }

    // ѕерем≥щуЇмо найменший елемент на початок списку
    Prev->next = smallest->next;
    smallest->next = *head;
    *head = smallest;
}

void showList(node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "List elements: ";
    node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
	node* head;
	head = NULL;
	for (int i = 10; i > 0; i--)
		addListLast(&head, i);	

    cout << "Before moving" << endl;
    showList(head);

    moveSmallest(&head);

    cout << "After moving" << endl;
    showList(head);

    return 0;
}
