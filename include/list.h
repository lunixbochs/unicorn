#ifndef UC_LLIST_H
#define UC_LLIST_H

struct list_item {
    struct list_item *prev, *next;
    void *data;
};

struct list {
    struct list_item *head, *tail;
};

struct list *list_new(void);
void list_clear(struct list *list);
void *list_append(struct list *list, void *data);
int list_remove(struct list *list, void *data);

#endif
