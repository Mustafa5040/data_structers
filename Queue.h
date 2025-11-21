
struct Queue;
typedef struct Queue Queue;

typedef enum Type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_LINKEDLIST,

} Type;

Queue *createQueue(int initial_capacity);
void *dequeue(Queue *queue, Type *type);
int enqueue(Queue *queue, void* data, Type type);
void *frontQueue(Queue *queue, Type *type);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
int sizeQueue(Queue *queue);