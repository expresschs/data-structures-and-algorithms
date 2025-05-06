#include <stddef.h>
#include "list.h"

void dl_addafter(dl_entry_t *prev, dl_entry_t *node, dl_list_t *list)
{
    if (!list->head || prev == list->tail) {
        dl_addlast(node, list);
    } else {
        dl_entry_t *next = prev->flink;
        node->blink = prev;
        node->flink = next;
        next->blink = node;
        prev->flink = node;
    }
}

void dl_addbefore(dl_entry_t *next, dl_entry_t *node, dl_list_t *list)
{
    if (!list->head || next == list->head) {
        dl_addfirst(node, list);
    } else {
        dl_entry_t *prev = next->blink;
        node->flink = next;
        node->blink = prev;
        prev->flink = node;
        next->blink = node;
    }
}

void dl_addfirst(dl_entry_t *node, dl_list_t *list)
{
    node->blink = NULL;
    node->flink = list->head;

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->blink = node;
        list->head = node;
    }
}

void dl_addlast(dl_entry_t *node, dl_list_t *list)
{
    node->flink = NULL;
    node->blink = list->tail;

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->flink = node;
        list->tail        = node;
    }
}

void dl_cat(dl_list_t *list1, dl_list_t *list2)
{
    if (dl_empty(list2)) {
        dl_move(list1, list2);
    } else if (!dl_empty(list1)) {
        list2->tail->flink = list1->head;
        list1->head->blink = list2->tail;
        list2->tail = list1->tail;
        dl_init(list1);
    }
}

size_t dl_count(dl_list_t *list)
{
    dl_entry_t *node;
    size_t count;

    for (node = list->head, count = 0;
        node != NULL;
        node = node->flink, count++);

    return count;
}

void dl_rem(dl_entry_t *node, dl_list_t *list)
{
    dl_entry_t *prev = node->blink;
    dl_entry_t *next = node->flink;

    if (!prev) {
        list->head = next;
    } else {
        prev->flink = next;
    }

    if (!next) {
        list->tail = prev;
    } else {
        next->blink = prev;
    }

    node->flink = NULL;
    node->blink = NULL;
}

dl_entry_t *dl_remfirst(dl_list_t *list)
{
    dl_entry_t *ret = list->head;

    if (ret) {
        dl_entry_t *next = ret->flink;
        if (!next) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = next;
            next->blink = NULL;
        }

        ret->flink = NULL;
        ret->blink = NULL;
    }

    return ret;
}

dl_entry_t *dl_remlast(dl_list_t *list)
{
    dl_entry_t *ret = list->tail;

    if (ret) {
        dl_entry_t *prev = ret->blink;
        if (!prev) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->tail = prev;
            prev->flink = NULL;
        }

        ret->flink = NULL;
        ret->blink = NULL;
  }

  return ret;
}

void sl_addafter(sl_entry_t *prev, sl_entry_t *node, sl_list_t *list)
{
    if (!list->head || prev == list->tail) {
        sl_addlast(node, list);
    } else {
        node->flink = prev->flink;
        prev->flink = node;
    }
}

void sl_addfirst(sl_entry_t *node, sl_list_t *list)
{
    node->flink = list->head;
    if (!list->head) {
        list->tail = node;
    }

    list->head = node;
}

void sl_addlast(sl_entry_t *node, sl_list_t *list)
{
    node->flink = NULL;
    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->flink = node;
        list->tail        = node;
    }
}

void sl_cat(sl_list_t *list1, sl_list_t *list2)
{
    if (sl_empty(list2)) {
        sl_move(list1, list2);
    } else if (!sl_empty(list1)) {
        list2->tail->flink = list1->head;
        list2->tail = list1->tail;
        sl_init(list1);
    }
}

size_t sl_count(sl_list_t *list)
{
    sl_entry_t *node;
    size_t count;

    for (node = list->head, count = 0;
        node != NULL;
        node = node->flink, count++);

    return count;
}

void sl_rem(sl_entry_t *node, sl_list_t *list)
{
    if (list->head && node) {
        if (node == list->head) {
            list->head = node->flink;
            if (node == list->tail) {
                list->tail = NULL;
            }
        } else {
            sl_entry_t *prev;

            for (prev = (sl_entry_t *)list->head;
                prev && prev->flink != node;
                prev = prev->flink);

            if (prev) {
                sl_remafter(prev, list);
            }
        }
    }
}

sl_entry_t *sl_remafter(sl_entry_t *node, sl_list_t *list)
{
    sl_entry_t *ret = node->flink;

    if (list->head && ret) {
        if (list->tail == ret) {
            list->tail = node;
            node->flink = NULL;
        } else {
            node->flink = ret->flink;
        }

        ret->flink = NULL;
    }

    return ret;
}

sl_entry_t *sl_remfirst(sl_list_t *list)
{
    sl_entry_t *ret = list->head;

    if (ret) {
        list->head = ret->flink;
        if (!list->head) {
            list->tail = NULL;
        }

        ret->flink = NULL;
    }

    return ret;
}

sl_entry_t *sl_remlast(sl_list_t *list)
{
    sl_entry_t *ret = list->tail;

    if (ret) {
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            sl_entry_t *prev;
            for (prev = list->head;
                prev && prev->flink != ret;
                prev = prev->flink);

            if (prev) {
                prev->flink = NULL;
                list->tail = prev;
            }
        }

        ret->flink = NULL;
    }

    return ret;
}


