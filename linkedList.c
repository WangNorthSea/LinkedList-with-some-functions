
#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;

typedef int Status;

//define one single node
struct Node {
 
    double data;
    struct Node * ptr;
   
};

//function list
//create a linkedlist
struct Node * createLinkedList(int);
//get the length of a linkedlist which has been created
int getLen(struct Node *);
//input data to a linkedlist which has been created
Status input(struct Node *);
//show data of a linkedlist which has been created
Status showData(struct Node *);
//remove a linkedlist which has been created
Status removeLinkedList(struct Node *);
//bubble sort
Status sort(struct Node *);
//insert a node into a linkedlist which has been created
Status insert(struct Node *, int, double);
//get the data of a specific position of a linkedlist which has been created
double getData(struct Node *, int); 
//remove the node of a specific position of a linkedlist which has been created
Status removeData(struct Node *, int);

int main(void) {

    int count;
    printf("Please enter the number of nodes you want to create:");
    scanf("%d", &count);
    struct Node * pHead = NULL;
    pHead = createLinkedList(count);
    if (!(pHead -> ptr)) {printf("creation failed!\n");}
    else {printf("creation succeeded!\n");}
    int len = getLen(pHead);
    printf("The number of nodes is:%d\n", len);
    if (input(pHead)) {printf("input succeeded!\n");}
    else {printf("input failed!\n");}
    if (showData(pHead)) {printf("show data succeeded!\n");}
    else {printf("show data failed!\n");}
    double insertData;
    int pos;
    printf("Please enter the data you want to insert:");
    scanf("%lf", &insertData);
    printf("Please enter the position of the new data(start from 0):");
    scanf("%d", &pos);
    if (insert(pHead, pos, insertData)) {printf("insert succeeded!\n");}
    else {printf("insert failed!\n");}
    len = getLen(pHead);
    printf("Now the number of nodes is:%d\n", len);
    if (showData(pHead)) {printf("show data succeeded!\n");}
    else {printf("show data failed!\n");}
    if (sort(pHead)) {printf("sort succeeded!\n");}
    else {printf("sort failed!\n");}
    if (showData(pHead)) {printf("show sorted data succeeded!\n");}
    else {printf("show sorted data failed!\n");}
    printf("Please enter the position of the data you want to get(start from 0):");
    scanf("%d", &pos);
    if (getData(pHead, pos)) {printf("The data is:%g\n", getData(pHead, pos));}
    else {printf("get data failed!\n");}
    printf("Please enter the position of the node you want to remove(start from 0):");
    scanf("%d", &pos);
    if (removeData(pHead, pos)) {printf("remove data succeeded!\n");}
    else {printf("remove data failed!\n");}
    len = getLen(pHead);
    printf("Now the number of nodes is:%d\n", len);
    if (showData(pHead)) {printf("show removed data succeeded!\n");}
    else {printf("show removed data failed!\n");}
    if (removeLinkedList(pHead)) {printf("remove linkedlist succeeded!\n");}
    else {printf("remove linkedlist failed!\n");}
    return 0;
}

//functions

//create a linkedlist
struct Node * createLinkedList(int count) {

    struct Node * pHead = (struct Node *)malloc(sizeof(struct Node)); //create a head node
    pHead -> ptr = NULL;
    if (!pHead) {exit(-1);} //doesn't have enough memory
    if (count <= 0) {return pHead;}  //invalid input
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    struct Node * pTail = NULL;
    if (!node) {exit(-2);} //doesn't have enough memory
    node -> ptr = NULL;
    pHead -> ptr = node;
    pTail = node;
    if (count == 1) {      
        return pHead; 
    }
    for (int i = 1; i < count; i++) {
                
        struct Node * pNode = (struct Node *)malloc(sizeof(struct Node));
        if (!pNode) {exit(-3);} //doesn't have enough memory
        pNode -> ptr = NULL;
        pTail -> ptr = pNode;
        pTail = pNode;  
    }
    return pHead;   
}

//get the length of a linkedlist which has been created
int getLen(struct Node * pHead) {
     
    if (!(pHead -> ptr)) {return ERROR;}
    int len = 1;
    struct Node * node = pHead -> ptr;
    while (node -> ptr) {
      
        len++;
        node = node -> ptr;
    }
    return len;    
}

//input data to a linkedlist which has been created
Status input(struct Node * pHead) {
  
    if (!(pHead -> ptr)) {return ERROR;}
    struct Node * pTail = pHead -> ptr;
    double input;
    int len = getLen(pHead);
    for (int i = 1; i <= len; i++) {

        printf("Please enter the data of No.%d node:", i);
        scanf("%lf", &input);
        pTail -> data = input;
        pTail = pTail -> ptr;
    }
    return OK;  
}

//show data of a linkedlist which has been created
Status showData(struct Node * pHead) {

    if (!(pHead -> ptr)) {return ERROR;}
    struct Node * pTail = pHead -> ptr;
    int len = getLen(pHead);
    for (int i = 1; i <= len; i++) {
    
        printf("The data of No.%d node is:%g\n", i, pTail -> data);
        pTail = pTail -> ptr;
    }
    return OK; 
}

//remove a linkedlist which has been created
Status removeLinkedList(struct Node * pHead) {

    if (!(pHead -> ptr)) {return ERROR;}
    int returnValue = removeLinkedList(pHead -> ptr);
    free(pHead -> ptr);
    pHead -> ptr = NULL;
    return OK;
}

//bubble sort
Status sort(struct Node * pHead) {
 
    if (!(pHead -> ptr)) {return ERROR;}
    int len = getLen(pHead);
    double exchange;
    if (len == 1) {return OK;}
    struct Node * pTail1 = pHead -> ptr;
    struct Node * pTail2 = pTail1 -> ptr;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            
            if (pTail1 -> data > pTail2 -> data) {
                 exchange = pTail1 -> data;
                 pTail1 -> data = pTail2 -> data;
                 pTail2 -> data = exchange;   
            }
            if (pTail2 -> ptr) {
               pTail2 = pTail2 -> ptr;
            }
        }
        pTail1 = pTail1 -> ptr;
        pTail2 = pTail1 -> ptr;
    }
    return OK; 
} 

//insert a node into a linkedlist which has been created
Status insert(struct Node * pHead, int pos, double data) {

    if (pos < 0) {return ERROR;}
    if (!(pHead -> ptr)) {return ERROR;}
    int len = getLen(pHead);
    if (pos > len) {return ERROR;}
    struct Node * pTail = pHead -> ptr;
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> ptr = NULL;
    newNode -> data = data;
    if (pos == 0) {
        pHead -> ptr = newNode;  
        newNode -> ptr = pTail;
        return OK;
    }
    for (int i = 0; i < pos - 1; i++) {
        pTail = pTail -> ptr;
    }
    newNode -> ptr = pTail -> ptr;
    pTail -> ptr = newNode;
    return OK;
}

//get the data of a specific position of a linkedlish which has been created
double getData(struct Node * pHead, int pos) {
    
    if (!(pHead -> ptr)) {return 0;}
    if (pos < 0) {return 0;}
    struct Node * pTail = pHead -> ptr;
    int len = getLen(pHead);
    if (pos > (len - 1)) {return 0;}
    for (int i = 0; i < pos; i++) {
        pTail = pTail -> ptr;
    }
    return pTail -> data;
}

//remove the node of a specific position of a linkedlist which has been created
Status removeData(struct Node * pHead, int pos) {

    if (!(pHead -> ptr)) {return ERROR;}
    if (pos < 0) {return ERROR;}
    struct Node * pTail = pHead -> ptr;
    struct Node * pLast = pHead;
    int len = getLen(pHead);
    if (pos > (len - 1)) {return ERROR;}
    if (pos == 0) {
        pHead -> ptr = pTail -> ptr;
        free(pTail);
        return OK;
    }
    for (int i = 0; i < pos; i++) {
        pLast = pTail;
        pTail = pTail -> ptr;
    }
    pLast -> ptr = pTail -> ptr;
    free(pTail);
    return OK;
}
