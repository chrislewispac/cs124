#include <pa1.h>
#include <stdio.h>
#include "seatest.h"
#include "seatest.c"

void test_print_one()
{
        int a = PrintOne();
        assert_int_equal(1, a);
}

void test_num_edges()
{
        int i = 4;
        assert_int_equal(CalculateNumEdges(i), MakeEdges(i));
        i = 8;
        assert_int_equal(CalculateNumEdges(i), MakeEdges(i));
        i = 26;
        assert_int_equal(CalculateNumEdges(i), MakeEdges(i));
}

void test_fixture_one( void )
{
        test_fixture_start();
        run_test(test_print_one);
        run_test(test_num_edges);
        test_fixture_end();
}

void all_tests( void )
{
        test_fixture_one();
}
