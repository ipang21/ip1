#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int val;
} Node;

typedef struct qnode {
    Node *n;
    struct qnode *next;
} qNode;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

Node *createRandTree(int num)
{
    int i, j, tmp;
    Node **arr = malloc(sizeof(Node *) * num);
    Node *root;
    Node *temp;
    srand(time(NULL));
    for (i=0; i<num;i++) {
        arr[i] = newNode(i);
    }

    for (i=num-1; i>0; i--) {
        j = rand() % (i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    root = arr[0];
    tmp = 2;

    for (i=1; i<num; i++) {
        //printf("pos %d: val %d\n", i, arr[i]->val);
    }

    free(arr);
    return root;   
}

int getMaxIndent(Node *root)
{
    int left, right;
    if (root->left) left = 1+getMaxIndent(root->left);
    else left = 0;
    if (root->right) right = 1+getMaxIndent(root->right);
    else right = 0;
    if (left > right) return left;
    else return right;
}

void printTree(Node *root)
{
    int id = getMaxIndent(root);
    int i;
    qNode *qHead, *qTail;
    printf("got indent = %d\n", id);
}

int main()
{
    Node *root = createRandTree(16);
    Node *test = newNode(0);
    test->left = newNode(1);
    test->right = newNode(2);
    test->right->left = newNode(15);
    test->right->left->left = newNode(30);
    printTree(test);
    return 0;
}

