
struct CircularQueue;
typedef struct CircularQueue CircularQueue;

typedef enum Type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_LINKEDLIST,

} Type;

CircularQueue *createCircularQueue(int capacity);
void *dequeueCircularQueue(CircularQueue *queue, Type *type);
void enqueueCircularQueue(CircularQueue *queue, void* data, Type type);
void *frontCircularQueue(CircularQueue *queue, Type *type);
int isCircularQueueEmpty(CircularQueue *queue);
int isCircularQueueFull(CircularQueue *queue);