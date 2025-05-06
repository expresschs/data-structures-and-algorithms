#include <string.h>
#include <stdint.h>
#include "stack.h"

void stack_init(stack_type *s, uint8_t *buf, uint16_t itemsize, uint16_t itemcount)
{
    s->itemsize = itemsize;
    s->itemcount = itemcount;
    s->buf = (void*)buf;
    s->head = 0;

    return;
}

int stack_put(stack_type *s, void *data)
{
    int ret = 1;

    if (0 == stack_is_full(s)) {
        memcpy(s->buf + s->itemsize * s->head, data, s->itemsize);
        s->head++;
        ret = 0;
    }

    return ret;
}

int stack_get(stack_type *s, void *data)
{
    int ret = 1;

    if (0 == stack_is_empty(s)) {
        s->head--;
        memcpy(data, s->buf + s->itemsize * s->head, s->itemsize);
        ret = 0;
    }

    return ret;
}

int stack_get_size(stack_type *s)
{
    return s->head;
}

int stack_get_empty(stack_type *s)
{
    return s->itemcount - s->head;
}

int stack_peek(stack_type *s, void *data)
{
    int ret = 1;

    if (0 == stack_is_empty(s)) {
        memcpy(data, s->buf + s->itemsize * s->head, s->itemsize);
        ret = 0;
    }

    return ret;
}

