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
    struct Node *prev;
};


/*
* Finds the node at the position n.
* head - pointer to the head of linked list
* n - the index of the node
*/
struct Node* find(struct Node* head, int n){
    if (n < -1) {
        //printf("Warning: n exceeds the boundaries of linked list\n");
        return NULL;
    } 

    int i = -1;
    struct Node *current = head;
    while(current != NULL && i < n){
        current = current->next;
        i++;
    }

    if (current == NULL) {
        //printf("Warning: n exceeds the boundaries of linked list\n");
        return NULL;
    }

    return current;
}

/*
* Adds to the tail a node with key k
* head - pointer to the head of linked list
* k - key of the node
*/ 
void append(struct Node* head, int k){
    struct Node *current = head;
    while (current->next != NULL){
        current = current->next;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = k;
    new_node->next = NULL;
    current->next = new_node;
    new_node->prev = current;
}

/*
* Inserts the node with key k in position pos, thus extending the linkedList.
* Ex: 2 -> 3 -> 4 -> 5 
* insert(1, 2022)
* 2 -> 2022 -> 3 -> 4 -> 5
* 
* If pos exceeds the boundaries of linked list, it raises an error message.
* head - pointer to the head of linked list
* pos - position in which will be inserted the node
*       possible values for pos: 0, 1, ..., len(linkedList) - 1;
* k - key of the node
*/
void insert(struct Node* head, int pos, int k){
    int i = 0;
    struct Node *current = head;
    while(current->next->next != NULL && i < pos){
        current = current->next;
        i++;
    }

    if (i < pos) {
        printf("Index exceeds the boundaries of linked list!\n");
        return;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = k;
    new_node->next = current->next;
    current->next = new_node;
    new_node->prev = current;
    new_node->next->prev = new_node; 
}

/*
* Inserts node in the front of linked list.
* head - pointer to the head of linked list
* k – key of the node
*/
void prepend(struct Node* head, int k){
    insert(head, 0, k);
}

/*
* Deletes the node from position n. If n exceeds the boundaries of linked list, it raises an error.
* head - pointer to the head of linked list
* n - index of node (n = 0, 1, 2, ..., len(linkedList)-1)
*/
void delete(struct Node* head, int n){

    struct Node *del = find(head, n);

    if (del == NULL){
        printf("The node with position %d does not exist!\n", n);
        return;
    }

    /* base case */
    if (head == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (head == del)
        head = del->next;
 
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);

    // struct Node *current = head;
    // while(current->next != node_to_be_deleted){
    //     current = current->next;
    // }

    // current->next = current->next->next;
    // node_to_be_deleted->next = NULL;
}

/* 
* Search for a value k. 
* If value exists, it outputs its position index. Otherwise it returns -1.
* head - pointer to the head of linked list
*/
int findValue(struct Node* head, int k) {
    struct Node *current = head->next;
    int i = 0;
    while(current != NULL && current->key != k) {
        current = current->next;
        i++;
    }
    if(current == NULL) {
        return -1;
    } else {
        return i;
    }

}

/*
* Swaps the nodes with indices n and m. If n or m are out of bounds, and error message is raised.
* head - pointer to the head of linked list
* n - index of the first node
* m - index of the second node
*/
void swap(struct Node* head, int n, int m){

    if (head == NULL || head->next == NULL || n == m) return;
 
    struct Node* Node1 = find(head, n);
    struct Node* Node2 = find(head, m);
    struct Node* tail = head->next;

    while (tail->next != NULL){
        tail = tail->next;
    }

    if (Node1 == head)
        head = Node2;
    else if (Node2 == head)
        head = Node1;
    if (Node1 == tail)
        tail = Node2;
    else if (Node2 == tail)
        tail = Node1;
 
    // Swapping Node1 and Node2
    struct Node* temp;
    temp = Node1->next;
    Node1->next = Node2->next;
    Node2->next = temp;
 
    if (Node1->next != NULL)
        Node1->next->prev = Node1;
    if (Node2->next != NULL)
        Node2->next->prev = Node2;
 
    temp = Node1->prev;
    Node1->prev = Node2->prev;
    Node2->prev = temp;
 
    if (Node1->prev != NULL)
        Node1->prev->next = Node1;
    if (Node2->prev != NULL)
        Node2->prev->next = Node2;
    // struct Node *node_n = find(head, n);
    // if (node_n == NULL) {
    //     printf("Warning: n exceeds the boundaries of linked list\n");
    //     return;
    // }

    // struct Node *node_m = find(head, m);
    // if (node_m == NULL) {
    //     printf("Warning: m exceeds the boundaries of linked list\n");
    //     return;
    // }
    
    // struct Node *current = head;
    // while(current->next != NULL) {
    //     current = current->next;
    // }

    // struct Node* dummyNode = (struct Node*)malloc(sizeof(struct Node));
    // dummyNode->key = 0;
    // dummyNode->next = NULL;
    // current->next = dummyNode;
    // dummyNode->prev = current;
    
    
    // struct Node *tmp;

    // struct Node *node_pred_n = node_n->prev;
    // struct Node *node_pred_m = node_m->prev;
    // struct Node *node_suc_n = node_n->next;
    // struct Node *node_suc_m = node_m->next;

    // // struct Node* dummyNode;
    // // dummyNode->key = 0;
    // // dummyNode->next = NULL;
    // // dummyNode->prev = (node_suc_n == NULL) ? node_n : node_m;

    // tmp = node_pred_n->next;
    // node_pred_n->next = node_pred_m->next;
    // node_pred_m->next = tmp;

    // tmp = node_n->next;
    // node_n->next = node_m->next;
    // node_m->next = tmp;

    // // if (node_suc_m == NULL) {
    // //     tmp = node_suc_n->prev;
    // //     node_suc_n->prev = dummyNode->prev;
    // //     dummyNode->prev = tmp;
    // // } else if (node_suc_n == NULL) {
    // //     tmp = dummyNode->prev;
    // //     dummyNode->prev = node_pred_m->prev;
    // //     node_pred_m->prev = tmp;
    // // }
    // // dummyNode = NULL;

    // tmp = node_suc_n->prev;
    // node_suc_n->prev = node_suc_m->prev;
    // node_suc_m->prev = tmp;

    // tmp = node_n->prev;
    // node_n->prev = node_m->prev;
    // node_m->prev = tmp;

    // dummyNode->prev->next = NULL;
    // dummyNode->prev = NULL;
    // dummyNode = NULL;
}

/*
* Reverse linked list.
* head - pointer to the head of linked list
*/
void reverse(struct Node* head) {
    struct Node *current = head->next;
    
    int len = 0;
    while (current != NULL){
        current = current->next;
        len++;
    }

    for (int i = 0; i < len/2; ++i) {
        struct Node *a = find(head, i);
        struct Node *b = find(head, len - i - 1);
        swap(head, i, len - i - 1);
    }
}


/*
* Sort the keys in linked list in ascending order.
* head - pointer to the head of linked list
*/
void sort(struct Node* head){

    struct Node *current = head->next;
    
    int i = 0;
    while (current != NULL){
        current = current->next;
        i++;
    }

    int l = i;

    for (int i = 0; i < l; ++i){
        for (int j = 0; j < l - i - 1; ++j){
            struct Node *a = find(head, j); 
            struct Node *b = find(head, j + 1);
            if (a->key > b->key){
                swap(head, j, j+1);
            }
        }
    }
}


/*
* Joins two linked lists.
* Ex: 
*   linked list 1: 1 -> 3 -> 5 -> 13, head1.key = 1;
*   linked list 2: 4 -> 1 -> 612 -> 69, head2.key = 4;
* join(head1, head2) => 1 -> 3 -> 5 -> 13 -> 4 -> 1 -> 612 -> 69
* head1 - pointer to the head of the first linked list
* head2 - pointer to the head of the first linked list
*/
void join(struct Node* head1, struct Node* head2) {
    struct Node* tail = head1;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head2->next;
    head2->next->prev = tail;
    head2->next = NULL;
}

/*
* Output the keys from the linked list.
* head - pointer to the head of linked list
*/
void traverse(struct Node* head) {
    struct Node *current = head->next;
    while(current->next != NULL){
        printf("%d -- ", current->key);
        current = current->next;
    }
    printf("%d\n", current->key);
}

/*
* Makes a backward traversal of a double linked list.
* head - pointer to the head of linked list
*/
void backwardTraversal(struct Node* head) {
    struct Node *current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    while(current->prev->prev != NULL){
        printf("%d -- ", current->key);
        current = current->prev;
    }

    printf("%d\n", current->key);
}

void writeInFile(FILE* file, struct Node* head) {
    struct Node *current = head->next;
    while(current->next != NULL){
        fprintf(file, "%d -- ", current->key);
        current = current->next;
    }
    fprintf(file, "%d ", current->key);
    fclose(file);
}

int main(){
    int x, y;
    int k;
    int i;
    char c;
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *new_head = (struct Node*)malloc(sizeof(struct Node));

    head->key = 0;
    head->next = NULL;
    new_head->key = 0;
    new_head->next = NULL;
    
    char input[] = "input.txt";
    char output[] = "output.txt";
    
    FILE* ifile;
    FILE* ofile;
    ifile = fopen(input, "r");
    ofile = fopen(output, "w");
    if (ifile == NULL || ofile == NULL) {
        fprintf(stderr, "Couldn't Open File'\n");
        exit(1);
    }

    while(!feof(ifile)) {
        fscanf(ifile, "%d -- ", &x);
        append(head, x);
    }
    fclose(ifile);

    while(1) {
        printf("Select an option:\n");
        printf("\t1. Display linekd list\n");
        printf("\t2. Append element\n");
        printf("\t3. Prepend element\n");
        printf("\t4. Reverse linked list\n");
        printf("\t5. Add a value to the specific index\n");
        printf("\t6. Remove by index\n");
        printf("\t7. Remove by value\n");
        printf("\t8. Sort linked list\n");
        printf("\t9. Search a value\n");
        printf("\t10. Join two linked lists\n");
        printf("\t11. Backwards traversal\n");
        printf("\t12. Save and exit\n");
        printf("Your choice: ");
        scanf("%d", &k);

        switch(k) {
            case 1: {
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 2: {
                printf("Input value to append: ");
                scanf("%d", &x);
                append(head, x);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 3: {
                printf("Input value to prepend: ");
                scanf("%d", &x);
                prepend(head, x);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 4: {
                reverse(head);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 5: {
                printf("Input index: ");
                scanf("%d", &i);
                printf("Input value: ");
                scanf("%d", &k);
                insert(head, i, k);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 6: {
                printf("Input index: ");
                scanf("%d", &i);
                delete(head, i);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 7: {
                printf("Input value: ");
                scanf("%d", &k);
                i = findValue(head, k);
                if (i == -1) {
                    printf("The value %d doesn't exist in linked list!\n", k); 
                    printf("Output:\n");
                    traverse(head);
                    break;
                }
                while (i != -1) {
                    delete(head, i);
                    i = findValue(head, k);
                }
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 8: {
                sort(head);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 9: {
                printf("Input value: ");
                scanf("%d", &k);
                i = findValue(head, k);
                if (i == -1) printf("The value %d doesn't exist in linked list!\n", k);
                else printf("The value %d was found successfully!\nIt has position %d.\n", k, i);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 10: {
                printf("Enter new linked list in input.txt\n");
                printf("Continue? (y/n) ");
                scanf(" %c", &c);
                FILE* ifile;
                ifile = fopen(input, "r");
                if (ifile == NULL || ofile == NULL) {
                    fprintf(stderr, "Couldn't Open File'\n");
                    exit(1);
                }
                while(!feof(ifile)) {
                    fscanf(ifile, "%d -- ", &x);
                    append(new_head, x);
                }
                fclose(ifile);
                join(head, new_head);
                printf("Output:\n");
                traverse(head);
                break;
            }
            case 11: {
                backwardTraversal(head);
                break;
            }
            case 12: {
                writeInFile(ofile, head);
                return 0;
            }
        }
        
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &c);
        if (c == 'y') continue;
        else if (c == 'n') {
            printf("Do you want to save changes? (y/n) ");
            scanf(" %c", &c);
            if (c == 'y'){writeInFile(ofile, head);}
            printf("Exit? (y/n) ");
            scanf(" %c", &c);
            if (c == 'y') return 0;
            else continue;
        }
    }

    fclose(ofile);
    return 0;
}