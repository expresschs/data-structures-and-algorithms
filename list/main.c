#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct _node {
    char *name;
} node;

typedef struct _sl_node {
    struct sl_node *next;
    node data;
} sl_node;

typedef struct _dl_node {
    struct dl_node *prev;
    struct dl_node *next;
    node data;
} dl_node;

static sl_node s_node_pool[5] = {
    {.data.name = "Alice"},
    {.data.name = "Bob"},
    {.data.name = "Celia"},
    {.data.name = "Dylan"},
    {.data.name = "Ethan"}
};
static dl_node d_node_pool[5] = {
    {.data.name = "Alice"},
    {.data.name = "Bob"},
    {.data.name = "Celia"},
    {.data.name = "Dylan"},
    {.data.name = "Ethan"}
};
static sl_list_t s_node_list;
static dl_list_t d_node_list;

static void print_slist(sl_list_t *list)
{
    sl_node *node = NULL;
    for (node = (sl_node*)sl_peek(list);
        node != NULL;
        node = (sl_node*)sl_next((sl_entry_t*)node)) {
        printf("%s ", node->data.name);
    }
    printf("\n");
}

static void print_dlist(dl_list_t* list)
{
    dl_node *node = NULL;
    for (node = (dl_node*)dl_peek(list);
        node != NULL;
        node = (dl_node*)dl_next((dl_entry_t*)node)) {
        printf("%s ", node->data.name);
    }
    printf("\n");
}


int main(void)
{
    printf("...single linked list test... \n\r");
    sl_init((sl_list_t*)&s_node_list);
    sl_addlast((sl_entry_t*)&s_node_pool[0], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_addlast((sl_entry_t*)&s_node_pool[1], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_addlast((sl_entry_t*)&s_node_pool[2], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_addfirst((sl_entry_t*)&s_node_pool[3], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_addfirst((sl_entry_t*)&s_node_pool[4], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_rem((sl_entry_t*)&s_node_pool[3], (sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_remlast((sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_remlast((sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_remfirst((sl_list_t*)&s_node_list); print_slist(&s_node_list);
    sl_remfirst((sl_list_t*)&s_node_list); print_slist(&s_node_list);

    printf("...double linked list test... \n\r");
    dl_init((dl_list_t*)&d_node_list);
    dl_addlast((dl_entry_t*)&d_node_pool[0], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_addlast((dl_entry_t*)&d_node_pool[1], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_addlast((dl_entry_t*)&d_node_pool[2], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_rem((dl_entry_t*)&d_node_pool[1], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_addfirst((dl_entry_t*)&d_node_pool[3], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_addfirst((dl_entry_t*)&d_node_pool[4], (dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_remlast((dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_remlast((dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_remfirst((dl_list_t*)&d_node_list); print_dlist(&d_node_list);
    dl_remfirst((dl_list_t*)&d_node_list); print_dlist(&d_node_list);

    return 0;
}

