
struct LinkedListQueue;
typedef struct LinkedListQueue LinkedListQueue;

typedef enum Type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_LINKEDLIST,

} Type;

LinkedListQueue *createLinkedListQueue();
void *dequeueLinkedListQueue(LinkedListQueue *queue, Type *type);
int enqueueLinkedListQueue(LinkedListQueue *queue, void* data, Type type);
void *frontLinkedListQueue(LinkedListQueue *queue, Type *type);
int isLinkedListQueueEmpty(LinkedListQueue *queue);
int isLinkedListQueueFull(LinkedListQueue *queue);