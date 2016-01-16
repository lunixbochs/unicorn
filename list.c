#include <stdlib.h>
#include <stdint.h>
#include "list.h"

// simple linked list implementation

struct list *list_new(void)
{
    return calloc(1, sizeof(struct list));
}

// removed linked list nodes but does not free their content
void list_clear(struct list *list)
{
    struct list_item *next, *cur = list->head;
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

// returns generated linked list node, or NULL on failure
void *list_append(struct list *list, void *data)
{
    struct list_item *item = malloc(sizeof(struct list_item));
    if (item == NULL) {
        return NULL;
    }
    item->prev = list->tail;
    item->next = NULL;
    item->data = data;
    if (list->head == NULL) {
        list->head = item;
    } else {
        list->tail->next = item;
    }
    list->tail = item;
    return item;
}

// returns 1 if entry was removed, 0 otherwise
int list_remove(struct list *list, void *data)
{
    struct list_item *next, *cur;
    // is list empty?
    if (list->head == NULL) {
        return 0;
    }
    cur = list->head;
    while (cur != NULL) {
        next = cur->next;
        if (cur->data == data) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            if (cur == list->head) {
                list->head = cur->next;
            }
            if (cur == list->tail) {
                list->tail = cur->prev;
            }
            free(cur);
            return 1;
        }
        cur = next;
    }
    return 0;
}
