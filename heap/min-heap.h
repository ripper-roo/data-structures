#ifndef MIN_HEAP
#define MIN_HEAP

struct Element
{
    char value[50];     
    int priority;   
};

typedef struct minHeap* p_minHeap;

struct minHeap
{
    struct Element *elements;
    int numberOfElements;
    int size;
};

p_minHeap createHeap(int size);

void freeHeap(p_minHeap heap);

int isHeapEmpty(p_minHeap heap);

int isHeapFull(p_minHeap heap);

void swap(struct Element *a, struct Element *b);

void upHeap(p_minHeap heap, int index);

void push(p_minHeap heap, char *value, int priority);

int findSmallestChild(p_minHeap heap, int index);

void downHeap(p_minHeap heap, int index);

void removeTopElement(p_minHeap heap);

struct Element pop(p_minHeap heap);

#endif