#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// TO DO: BELLEK YÖNETİMİNİ VE TYPE'I İYİLEŞTİR!

typedef struct Node
{
    Type type;
    void *data;
    Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail

} LinkedList;

LinkedList *createLinkedList()
{
    LinkedList *linked_list = malloc(sizeof(linked_list));
    linked_list->head = _createNode(NULL,NULL,NULL);
    linked_list->tail = linked_list->head;
    return linked_list;
}

Node *_createNode(Type type, void *data, Node *next)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;
    new_node->type = type;
    return new_node;
}

Node *first(LinkedList *linked_list)
{
    return linked_list->head->next;
}
Node *zeroth(LinkedList *linked_list)
{
    return linked_list->head;
}
int isLinkedListEmpty(LinkedList *linked_list)
{
    if (linked_list->head->next == NULL)
    {
        return 1;
    }
    return 0;
}

int insertAfter(LinkedList *linked_list, Type type, void *data)
{
    Node *curr_node = linked_list->head;

    while (curr_node != NULL)
    {
        if (isEqual(curr_node->data, type, data))
        {

            Node *temp_next = curr_node->next;
            curr_node->next = _createNode(type, data, temp_next);
            return 1;
        }
        curr_node = curr_node->next;
    }
    return -1;
}

void *insertAtHead(LinkedList *linked_list, Type type, void *data)
{
    linked_list->head->next = _createNode(type, data, linked_list->head->next);
}

Node *find(LinkedList *linked_list, Type type, void *data)
{

    Node *curr_node = linked_list->head->next;

    while (curr_node != NULL)
    {
        if (isEqual(curr_node, type, data))
        {
            return curr_node;
        }
        curr_node = curr_node->next;
    }
    return NULL;
}

Node *findPrevious(void *data, Type type, LinkedList *linked_list)
{
    Node *prev_node = linked_list->head;

    while (prev_node->next != NULL)
    {
        if (isEqual((prev_node->next)->data, type, data))
        {
            return prev_node;
        }
        prev_node = prev_node->next;
    }
    return NULL;
}
int removeNode(LinkedList *linked_list, Type type, void *data)
{
    Node *prev_node = linked_list->head;
    while (prev_node->next != NULL)
    {

        if (isEqual((prev_node->next)->data, type, data))
        {

            Node *temp_next = (prev_node->next)->next;
            free(prev_node->next);
            prev_node->next = temp_next;
            return 0;
        }
        prev_node = prev_node->next;
    }
    return -1;
}
int removeFirstNode(LinkedList* linked_list){
    Node* node_to_remove = linked_list->head->next;
    linked_list->head->next = node_to_remove->next;

    if(node_to_remove->data != NULL){
        free(node_to_remove->data);
    }
    if(node_to_remove->type != NULL){
        free(node_to_remove->type);
    }
    free(node_to_remove);
}

char *toString(LinkedList *linked_list)
{
    if (linked_list == NULL || linked_list->head == NULL)
    {
        return strdup("NULL"); // "NULL" string'i döndür
    }
    // Determining the size of the string
    int node_count = 0;
    Node *curr_node = linked_list->head->next;
    while (curr_node != NULL)
    {
        node_count++;
        curr_node = curr_node->next;
    }

    char *str = malloc(sizeof(char) * (node_count * 7 + 11) + 1); // include '\0' too thats why +1
    char *p = str;

    p += sprintf(p, "HEAD-->");

    while (node_count > 0)
    {
        p += sprintf(p, "NODE-->");
        node_count--;
    }
    p += sprintf(p, "NULL");

    return str;
}

char *toStringWithData(LinkedList *linked_list)
{

    if (linked_list == NULL || linked_list->head == NULL)
    {
        return strdup("NULL");
    }

    int memory_size = 12; //"head-->", "NULL" and \0
    Node *current_node = linked_list->head->next;

    while (current_node != NULL)
    {
        memory_size += calculateNodeSize(current_node);
        current_node = current_node->next;
    }

    char *str = malloc(memory_size);
    char *p = str;
    p += sprintf(p, "head-->");
    current_node = linked_list->head->next;

    while (current_node != NULL)
    {
        Type type = current_node->type;
        if (current_node->data == NULL)
        {
            p += sprintf(p, "NULL-->");
            current_node = current_node->next;
            continue;
        }
        switch (type)
        {
        case TYPE_INT:
        {
            int data = *(int *)(current_node->data);
            p += sprintf(p, "%d-->", data);
            break;
        }
        }
        current_node = current_node->next;
    }
    p += sprintf(p, "NULL");

    return str;
}
int calculateNodeSize(Node *node)
{
    if (node == NULL)
    {
        return 4;
    }
    if (node->data == NULL || node->type == NULL)
    {
        return 7; //"NULL-->"
    } // NULL

    void *data = node->data;
    Type type = node->type;

    switch (type)
    {
    case TYPE_INT:
    {
        // Manual implementation of snprintf standart function.

        int int_value = *(int *)(data); // deference to int, this is copy
        int int_nums = 0;

        if (int_value == 0)
        {
            return 4;
        }
        if (int_value < 0)
        {
            int_nums++; // for '-' sign
            int_value = -int_value;
        }
        while (int_value > 0)
        {
            int_value /= 10;
            int_nums++;
        }

        return int_nums + 3;
    }
    case TYPE_CHAR:

    default:
        return 0;
    }
}

void makeLinkedListEmpty(LinkedList *linked_list)
{

    if (linked_list == NULL)
        return;

    Node *curr_node = linked_list->head->next;

    while (curr_node != NULL)
    {

        Node *next = curr_node->next;
        if (curr_node->data != NULL)
        {
            free(curr_node->data);
        }
        curr_node = next;
    }

    free(curr_node);
    free(linked_list);
}

int length(LinkedList *linked_list)
{

    if (linked_list == NULL)
    {
        return 0;
    }
    if (linked_list->head == NULL)
    {
        return 0;
    }

    int count = 0;

    Node *curr_node = linked_list->head->next;

    while (curr_node != NULL)
    {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}

int insertAtTail(LinkedList *linked_list, Type type, void *data)
{

    if (linked_list == NULL)
    {
        return 0;
    }
    if (linked_list->head == NULL)
    {
        return 0;
    }

    Node *last_node = linked_list->head;

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = _createNode(type, data, NULL);
    linked_list->tail = last_node->next;
    return 1;
}
int fastInsertAtTail(LinkedList *linked_list, Type type, void *data){
    if (linked_list == NULL)
    {
        return 0;
    }
    if (linked_list->tail == NULL)
    {
        return 0;
    }
    linked_list->tail->next = _createNode(type,data,NULL);
    linked_list->tail = linked_list->tail->next;
}
int reverse(LinkedList *linked_list)
{

    if (linked_list == NULL)
    {
        return 0;
    }
    if (linked_list->head == NULL)
    {
        return 0;
    }

    Node *prev_node = NULL;
    Node *curr_node = linked_list->head->next;

    while (curr_node != NULL)
    {
        Node *next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    linked_list->head->next = prev_node;
    return 1;
}

int isEqual(Node *node, Type comp_type, void *comp_data)
{

    if (node->type != comp_type)
    {
        return 0;
    }

    switch (comp_type)
    {
    case TYPE_INT:
        if (*(int *)(node->data) == *(int *)(comp_data))
            return 1;
        return 0;
    default:
        break;
    }
}
void *getNodeData(Node *node, Type *type)
{
    if (node == NULL)
        return NULL;
    if (type == NULL)
        *type = -1;
    *type = node->type;
    void *data = node->data;
    return data;
}
void destroyLinkedList(LinkedList *linked_list)
{
    if (linked_list == NULL)
        return;

    Node *curr_node = linked_list->head;

    while (curr_node != NULL)
    {
        Node *temp = curr_node;
        curr_node = curr_node->next;

        if (temp->data != NULL)
        {
            free(temp->data);
        }
        if (temp->type != NULL)
        {
            free(temp->type);
        }
        free(temp);
    }
    free(linked_list);
}