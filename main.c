/*
* Append (push back)
* Prepend (push front)
* Reverse
* Add a value to the specific index 
* Remove a value the from index 
* Sort the linked list, with re-arranging the cells, not just copying values
* Search for a value
* Join two linked lists
* Backwards traversal, use double-linked-list 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *next;
};

struct Node *head = NULL;


/*
* Finds the node at the position n.
* n - the position of the node
*/
struct Node* find(int n){
    if (n < 0) {
        printf("Warning: n exceeds the boundaries of linked list\n");
        return NULL;
    } 

    int i = 0;
    struct Node *current = head;
    while(current != NULL && i < n){
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Warning: n exceeds the boundaries of linked list\n");
        return NULL;
    }

    return current;
}

/*
* Adds to the tail a node with key k
* k - key of the node
*/ 
void append(int k){
    struct Node *current = head;
    while (current->next != NULL){
        current = current->next;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = k;
    new_node->next = NULL;
    current->next = new_node;
}

/*
* Inserts the node with key k in position pos, thus extending the linkedList.
* Ex: 2->3->4->5 
* insert(1, 2022)
* 2->2022->3->4->5
* 
* If pos exceeds the boundaries of linked list, it raises an error message.
* 
* pos - position in which will be inserted the node
*       possible values for pos: 0, 1, ..., len(linkedList) - 1;
* k - key of the node
*/
void insert(int pos, int k){
    int i = 0;
    struct Node *current = head;
    while(current->next->next != NULL && i < pos){
        current = current->next;
        i++;
    }

    if (i < pos) {
        printf("pos exceeds the boundaries of linked list!\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = k;
    new_node->next = current->next;
    current->next = new_node;
}

/*
* Inserts node in the front of linked list.
* k – key of the node
*/
void prepend(int k){
    insert(0, k);
}

/*
* Deletes the node from position n. If n exceeds the boundaries of linked list, it raises an error.
* n - position of node
*/
void delete(int n){

    struct Node *node_to_be_deleted = find(n);

    if (node_to_be_deleted == NULL){
        printf("The node with position n does not exist!\n");
        return;
    }

    struct Node *current = head;
    while(current->next != node_to_be_deleted){
        current = current->next;
    }

    current->next = current->next->next;
    node_to_be_deleted->next = NULL;
}

/*
* Swaps the nodes with positions n and m. If n or m are out of bounds, and error message is raised.
* 
* n - pos of the first node
* m - pos of the second node
*/
void swap(int n, int m){

    struct Node *node_pred_n = find(n-1);
    if (node_pred_n == NULL){
        printf("Warning: n exceeds the boundaries of linked list\n");
    }
    
    struct Node *node_pred_m = find(m-1);
    if (node_pred_m == NULL) {
        printf("Warning: m exceeds the boundaries of linked list\n");
        return;
    }

    struct Node *node_n = find(n);
    struct Node *node_m = find(m);
    struct Node *tmp;

    tmp = node_pred_n->next;
    node_pred_n->next = node_pred_m->next;
    node_pred_m->next = tmp;

    tmp = node_n->next;
    node_n->next = node_m->next;
    node_m->next = tmp;
}


/*
* Sort the keys in linked list in ascending order.
*/
void sort(){

    struct Node *current = head->next;
    
    int i = 0;
    while (current != NULL){
        current = current->next;
        i++;
    }

    int l = i;

    for (int i = 1; i <= l; ++i){
        for (int j = 1; j <= l - i; ++j){
            struct Node *a = find(j); 
            struct Node *b = find(j + 1);
            if (a->key > b->key){
                swap(j, j+1);
            }
        }
    }
}

void traverse(){
    /*
    Outputs the keys from the linked list.
    */

    struct Node *current = head->next;
    while(current->next != NULL){
        printf("%d --> ", current->key);
        current = current->next;
    }
    printf("%d\n", current->key);
    printf("\n");
}

int main(){
    struct Node *pseudohead = (struct Node*)malloc(sizeof(struct Node));
    pseudohead->key = 0;
    pseudohead->next = NULL;
    head = pseudohead;

    int A[10] = {2, 4, 6, 1, 3, 8, 9, 7, 10, 5};
    
    for (int i=0; i<10; ++i){
        append(A[i]);
    }
    
    sort();
    traverse();
    delete(2);
    traverse();

    // for (int i=0; i<4; ++i){
    //     int n, m;
    //     cin >> n >> m;
    //     swap(n, m);
    //     traverse();
    // }
    return 0;
}