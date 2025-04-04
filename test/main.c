#include <check.h>
#include "../src/circularqueue.h"

START_TEST(test_cqueue_create_destroy) {
    CQueue *q = cqueue_create () ;
    ck_assert(cqueue_is_empty(q));
    cqueue_destroy(q);
    q= NULL;
    ck_assert_ptr_eq(q, NULL);
}
END_TEST

/*START_TEST(test_queue_enqueue_dequeue) {
    
    Queue *queue;
    queue = queue_create();

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 30);
    queue_enqueue(queue, 40);
    queue_enqueue(queue, 50);

    
    ck_assert_int_eq(queue_dequeue(queue), 10);
    ck_assert_int_eq(queue_dequeue(queue), 30);
    ck_assert_int_eq(queue_dequeue(queue), 40);
    ck_assert_int_eq(queue_dequeue(queue), 50);
    ck_assert(queue_is_empty(queue));
    queue_delete(queue);
}
END_TEST*/

Suite* queue_suite(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("Queue");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_cqueue_create_destroy);
    //tcase_add_test(tc_core, test_queue_enqueue_dequeue);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = queue_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}