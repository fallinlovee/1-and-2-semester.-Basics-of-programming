#include <iostream>
using namespace std;

struct node{
	int num;
	node* left;
	node* right;
};

void addNode(node* nod, int data){
	if (data < nod->num)
		if (nod->left)
			addNode(nod->left, data);
		else
		{
		    node* newNode = new node;
			newNode->num = data;
			newNode->left = newNode->right = NULL;	
			nod->left = newNode;
		}
	else
		if (nod->right)
			addNode(nod->right, data);
		else
		{
		    node* newNode = new node;
			newNode->num = data;
			newNode->left = newNode->right = NULL;	
			nod->right = newNode;
		}		
}

void printInorder(node* root) {
    if (root == NULL)
        return;

    const int MAX_SIZE = 100;
    node* stack[MAX_SIZE];
    int top = -1;

    node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];

        cout << current->num << " "; 

        current = current->right;
    }
}

int main(){
	
	int arr[14] = {9,14,5,7,13,16,3,12,20,4,11,6,15,16};
	node* root = new node;
	root->left = root->right = NULL;
	root->num = 10;
	for (int i = 0; i < 14; i++)
	addNode(root, arr[i]);

	printInorder(root);
	return 0;
}
