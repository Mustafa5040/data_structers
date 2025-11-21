struct ArrayStack;

typedef struct ArrayStack ArrayStack;

typedef enum Type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_LINKEDLIST,

} Type;

ArrayStack *createArrayStack(int capacity);

int isArrayStackEmpty(ArrayStack *array_stack);

int isArrayStackFull(ArrayStack *array_stack);

void *popArrayStack(ArrayStack *array_stack, Type *type);

int pushArrayStack(ArrayStack *array_stack, Type type, void *data);

void *peekArrayStack(ArrayStack *array_stack, Type *type);

void destroyArrayStack(ArrayStack *array_stack);

int makeArrayStackEmpty(ArrayStack *array_stack);
