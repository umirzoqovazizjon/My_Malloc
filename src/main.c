#include "../include/my_malloc.h"

int main()
{
    // Test my_malloc
    printf("\tTest my_malloc\n");
    printf("\np1 -> ");
    int* p1 = (int*)my_malloc(10 * sizeof(int));
    assert(p1 != NULL);
    printf("%p [malloc 10 int]\n", p1);
    for (int i = 0; i < 10; i++) p1[i] = i * 10;
    for (int i = 0; i < 10; i++) printf("p1[%d] = %d\n", i, p1[i]);

    printf("\np2 -> ");
    float* p2 = (float*)my_malloc(10 * sizeof(float));
    assert(p2 != NULL);
    printf("%p [malloc 10 float]\n", p2);
    for (int i = 0; i < 10; i++) p2[i] = i * 1. / 10;
    for (int i = 0; i < 10; i++) printf("p2[%d] = %.1f\n", i, p2[i]);

    printf("\np3 -> ");
    float* p3 = (float*)my_malloc(10 * sizeof(double));
    assert(p3 != NULL);
    printf("%p [malloc 10 double]\n", p3);
    for (int i = 0; i < 10; i++) p3[i] = i * 10000000000.;
    for (int i = 0; i < 10; i++) printf("p3[%d] = %g\n", i, p3[i]);

    // Test my_calloc
    printf("\n\tTest my_calloc\n");
    printf("\np4 -> ");
    int* p4 = (int*)my_calloc(10, sizeof(int));
    assert(p4 != NULL);
    printf("%p [calloc 10 int]\n", p4);
    for (int i = 0; i < 10; i++) printf("p4[%d] = %d\n", i, p4[i]);

    printf("\np5 -> ");
    float* p5 = (float*)my_calloc(10, sizeof(float));
    assert(p5 != NULL);
    printf("%p [calloc 10 float]\n", p5);
    for (int i = 0; i < 10; i++) printf("p5[%d] = %.1f\n", i, p5[i]);

    printf("\np6 -> ");
    float* p6 = (float*)my_calloc(10, sizeof(double));
    assert(p6 != NULL);
    printf("%p [calloc 10 double]\n", p6);
    for (int i = 0; i < 10; i++) printf("p6[%d] = %g\n", i, p6[i]);

    // Test my_realloc
    printf("\n\tTest my_realloc\n");
    printf("\np1 -> ");
    p1 = (int*)my_realloc(p1, 20 * sizeof(int));
    assert(p1 != NULL);
    printf("%p [realloc 20 int]\n", p1);
    for (int i = 10; i < 20; i++) p1[i] = i * 10;
    for (int i = 0; i < 20; i++) printf("p1[%d] = %d\n", i, p1[i]);

    printf("\np2 -> ");
    p2 = (float*)my_realloc(p2, 20 * sizeof(float));
    assert(p2 != NULL);
    printf("%p [realloc 20 float]\n", p2);
    for (int i = 10; i < 20; i++) p2[i] = i * 1. / 10;
    for (int i = 0; i < 20; i++) printf("p2[%d] = %.1f\n", i, p2[i]);

    printf("\np3 -> ");
    p3 = (float*)my_realloc(p3, 20 * sizeof(double));
    assert(p3 != NULL);
    printf("%p [realloc 20 double]\n", p3);
    for (int i = 10; i < 20; i++) p3[i] = i * 10000000000.;
    for (int i = 0; i < 20; i++) printf("p3[%d] = %g\n", i, p3[i]);

    // Test re-malloc after reallocation.
    // it must allocate space from the top of the heap
    printf("\n\tTest re-malloc after reallocation\n");
    printf("\np7 -> ");
    int* p7 = (int*)my_malloc(10 * sizeof(int));
    assert(p7 != NULL);
    printf("%p [malloc 10 int]\n", p7);
    for (int i = 0; i < 10; i++) p7[i] = i * 10;
    for (int i = 0; i < 10; i++) printf("p7[%d] = %d\n", i, p7[i]);

    printf("\np8 -> ");
    float* p8 = (float*)my_malloc(10 * sizeof(float));
    assert(p8 != NULL);
    printf("%p [malloc 10 float]\n", p8);
    for (int i = 0; i < 10; i++) p8[i] = i * 1. / 10;
    for (int i = 0; i < 10; i++) printf("p8[%d] = %.1f\n", i, p8[i]);

    printf("\np9 -> ");
    float* p9 = (float*)my_malloc(10 * sizeof(double));
    assert(p9 != NULL);
    printf("%p [malloc 10 double]\n", p9);
    for (int i = 0; i < 10; i++) p9[i] = i * 10000000000.;
    for (int i = 0; i < 10; i++) printf("p9[%d] = %g\n", i, p9[i]);

    print_nodes();

    // Test my_free
    printf("\n\tTest my_free\n\n");
    my_free(p1);
    printf("%p\n", p1);
    my_free(p3);
    printf("%p\n", p3);

    print_nodes();

    // Test my_free for checking merge_consecutive_nodes
    printf("\n\tTest my_free for checking consecutive merging\n\n");
    my_free(p2);

    print_nodes();

    // Freeing All Memory blocks
    my_free(p4);
    my_free(p5);
    my_free(p6);
    my_free(p7);
    my_free(p8);
    my_free(p9);

    printf("\n\tAll tests passed!\n\n");

    print_nodes();

    return 0;
}