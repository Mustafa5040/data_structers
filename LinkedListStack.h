struct LinkedListStack ;

typedef struct  LinkedListStack;

typedef enum Type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_LINKEDLIST,

} Type;

LinkedListStack *createLinkedListStack();

int isLinkedListStackEmpty( LinkedListStack *linked_list_stack);

void *popLinkedListStack( LinkedListStack*linked_list_stack, Type *type);

int pushLinkedListStack( LinkedListStack*linked_list_stack, Type type, void *data);

void *peekLinkedListStack(LinkedListStack *linked_list_stack, Type *type);

void destroyLinkedListStack(LinkedListStack *linked_list_stack);

void makeLinkedListStackEmpty(LinkedListStack *linked_list_stack);