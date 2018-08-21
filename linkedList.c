
#include <stdio.h>
#include "linkedList.h"

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
    printf("The data is:%g\n", getData(pHead, pos));
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
