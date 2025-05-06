#ifndef __LIST_H_
#define __LIST_H_

#define sl_init(l) \
    do { \
        (l)->head = NULL; \
        (l)->tail = NULL; \
    } while (0)

#define dl_init(l) \
    do { \
        (l)->head = NULL; \
        (l)->tail = NULL; \
    } while (0)

#define sl_move(l1, l2) \
    do { \
        (l2)->head = (l1)->head; \
        (l2)->tail = (l1)->tail; \
        (l1)->head = NULL; \
        (l1)->tail = NULL; \
    } while (0)

#define dl_move(l1, l2) \
    do { \
        (l2)->head = (l1)->head; \
        (l2)->tail = (l1)->tail; \
        (l1)->head = NULL; \
        (l1)->tail = NULL; \
    } while (0)

#define sl_next(l)  ((l)->flink)
#define dl_next(l)  ((l)->flink)
#define dl_prev(l)  ((l)->blink)

#define sl_empty(l) ((l)->head == NULL)
#define dl_empty(l) ((l)->head == NULL)

#define sl_peek(l)  ((l)->head)
#define dl_peek(l)  ((l)->head)


struct sl_entry_s {
    struct sl_entry_s *flink;
};
typedef struct sl_entry_s sl_entry_t;

struct dl_entry_s {
    struct dl_entry_s *flink;
    struct dl_entry_s *blink;
};
typedef struct dl_entry_s dl_entry_t;

struct sl_list_s {
  sl_entry_t *head;
  sl_entry_t *tail;
};
typedef struct sl_list_s  sl_list_t;

struct dl_list_s {
    dl_entry_t *head;
    dl_entry_t *tail;
};
typedef struct dl_list_s dl_list_t;


#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

void sl_addfirst(sl_entry_t *node, sl_list_t *list);
void dl_addfirst(dl_entry_t *node, dl_list_t *list);
void sl_addlast(sl_entry_t *node, sl_list_t *list);
void dl_addlast(dl_entry_t *node, dl_list_t *list);
void sl_addafter(sl_entry_t *prev, sl_entry_t *node, sl_list_t *list);
void dl_addafter(dl_entry_t *prev, dl_entry_t *node, dl_list_t *list);
void dl_addbefore(dl_entry_t *next, dl_entry_t *node, dl_list_t *list);

void sl_cat(sl_list_t *list1, sl_list_t *list2);
void dl_cat(dl_list_t *list1, dl_list_t *list2);

 sl_entry_t *sl_remafter(sl_entry_t *node, sl_list_t *list);
void sl_rem(sl_entry_t *node, sl_list_t *list);
void dl_rem(dl_entry_t *node, dl_list_t *list);
sl_entry_t *sl_remlast(sl_list_t *list);
dl_entry_t *dl_remlast(dl_list_t *list);
sl_entry_t *sl_remfirst(sl_list_t *list);
dl_entry_t *dl_remfirst(dl_list_t *list);

size_t sl_count(sl_list_t *list);
size_t dl_count(dl_list_t *list);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /** __LIST_H_ */

