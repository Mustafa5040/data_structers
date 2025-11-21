typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,

} Type;

struct Node;

struct LinkedList;

typedef struct Node Node;

typedef struct LinkedList LinkedList;

LinkedList *createLinkedList();

Node *_createNode(Type type, void *data, Node *next);

Node *first(LinkedList *linked_list);

Node *zeroth(LinkedList *linked_list);

int isLinkedListEmpty(LinkedList *linked_list);

int insertAfter(LinkedList *linked_list, Type type, void *data);

void *insertAtHead(LinkedList *linked_list, Type type, void *data);

Node *find(LinkedList *linked_list, Type type, void *data);

Node *findPrevious(void *data, Type type, LinkedList *linked_list);

int removeNode(LinkedList *linked_list, Type type, void *data);

char *toString(LinkedList *linked_list);

char *toStringWithData(LinkedList *linked_list);

int calculateNodeSize(Node *node);

void makeLinkedListEmpty(LinkedList *linked_list);

int length(LinkedList *linked_list);

int insertAtTail(LinkedList *linked_list, Type type, void *data);

int fastInsertAtTail(LinkedList *linked_list, Type type, void *data);

int reverse(LinkedList *linked_list);

int isEqual(Node *node, Type comp_type, void *comp_data);

void *getNodeData(Node *node, Type *type);

void destroyLinkedList(LinkedList *linked_list);

int removeFirstNode(LinkedList *linked_list);