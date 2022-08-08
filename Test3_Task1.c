#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void print(struct Node *cll) {
    printf("Element with data: %d, current address: %p and pointing to next address: %p\n", cll->data, cll, cll->next);
}

struct Node* insertAfter(struct Node *cll, int skipCount, int newElem) {
    cll = realloc(cll, sizeof(Node) * skipCount);
    printf("Please enter the data for you new element: ");
    scanf("%d", &newElem);
    (cll + skipCount - 1)->data = newElem;
    (cll + skipCount - 2)->next = (cll + skipCount - 1);
    (cll + skipCount - 1)->next = cll + 0;
    return cll;
}
int main()
{
    static unsigned int N;
    int newElem;
    printf("Please enter how many nodes do you need in your cycle linked list: ");
    scanf("%u", &N);
    Node* nodeArr = malloc(sizeof(Node) * N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &(nodeArr + i)->data);
    }
    for(int i = 0; i < N; i++)
    {
        if(i == (N - 1))
        {
            (nodeArr + i)->next = (nodeArr + 0);
            break;
        }
        (nodeArr + i)->next = (nodeArr + i + 1);
    }
    for(int i = 0; i < N; i++)
    {
        print((nodeArr + i));
    }
    insertAfter(nodeArr, ++N, newElem);
    for(int i = 0; i < N; i++)
    {
        print((nodeArr + i));
    }
    free(nodeArr);
    return 0;
}