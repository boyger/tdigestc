#include <stdio.h>
#include "tdigest.h"

int main(void)
{
    td_histogram_t *t = td_new(500);
    for(int i = 1; i <= 10000000; i++) {
        td_add(t, i, 1);
    }
    printf("p50: %f\n", td_value_at(t, .5));
    printf("p90: %f\n", td_value_at(t, .9));
    td_free(t);
    //
    unsigned char *buffer;
    int size = td_as_bytes(t, &buffer);
    printf("size: %d\n", size);
    td_histogram_t *t_deserialize = td_from_bytes(buffer, size);
    free(buffer);
    printf("p50: %f\n", td_value_at(t_deserialize, .5));
    printf("p90: %f\n", td_value_at(t_deserialize, .9));
    free(t_deserialize);
    return 0;
}