#include <pa1.h>
#include <stdio.h>
#include "seatest.h"
#include "seatest.c"

void test_print_one()
{
        int a = PrintOne();
        assert_int_equal(1, a);
}

void test_fixture_one( void )
{
        test_fixture_start();
        run_test(test_print_one);
        test_fixture_end();
}

void all_tests( void )
{
        test_fixture_one();
}
