#ifndef _STACK_H_
#define _STACK_H_

typedef struct {
    volatile uint16_t head;
    uint16_t itemsize;   //缓冲区中每个元素的大小
    uint16_t itemcount;  //缓冲区中能够保存元素的总个数
    uint8_t *buf;
} stack_type;

static __inline int stack_is_empty(stack_type *s)
{
    return (s->head == 0);
}

static __inline int stack_is_full(stack_type *s)
{
    return (s->head == s->itemcount);
}

void stack_init(stack_type *q, uint8_t *buf, uint16_t itemsize, uint16_t itemcount);
int stack_put(stack_type *q, void *data);
int stack_get(stack_type *q, void *data);
int stack_get_size(stack_type *q);
int stack_get_empty(stack_type *s);
int stack_put(stack_type *q, void *data);


#endif // _STACK_H_


