#include <pa1.h>
#include <stdio.h>
#include "seatest.h"
#include "seatest.c"

void test_print_one()
{
        int a = PrintOne();
        assert_int_equal(1, a);
}

void test_calculate_weight4()
{
        double w1 = 0.2;
        double x1 = 0.34;
        double y1 = 0.54;
        double z1 = 0.26;
        double w2 = 0.39;
        double x2 = 0.53;
        double y2 = 0.24;
        double z2 = 0.1;
        double a = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 4);
        assert_double_equal(0.433359, a, 0.0001);
}
void test_calculate_weight3()
{
        double w1 = 0.5;
        double x1 = 0.3;
        double y1 = 0.4;
        double z1 = 0.2;
        double w2 = 0.5;
        double x2 = 0.3;
        double y2 = 0.4;
        double z2 = 0.2;
        double b = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 3);
        assert_double_equal(0, b, 0.0);
}
void test_calculate_weight2()
{
        double w1 = 0.5;
        double x1 = 0.3;
        double y1 = 0.4;
        double z1 = 0.2;
        double w2 = 0.5;
        double x2 = 0.3;
        double y2 = 0.4;
        double z2 = 0.2;
        double c = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 2);
        assert_double_equal(0, c, 0.0);
}
void test_calculate_weight0()
{
        double w1 = 0.5;
        double x1 = 0.3;
        double y1 = 0.4;
        double z1 = 0.2;
        double w2 = 0.5;
        double x2 = 0.3;
        double y2 = 0.4;
        double z2 = 0.2;
        double d = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 0);
        double e = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 0);
        double f = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 0);
        double g = CalculateWeight(w1, x1, y1, z1, w2, x2, y2, z2, 0);
        assert_false(d == e);
        assert_false(d == e);
        assert_false(d == f);
        assert_false(f == g);
        assert_false(e == g);
        assert_false(d == 0);
        assert_false(e == 0);
        assert_false(f == 0);
}

void test_fixture_one( void )
{
        test_fixture_start();
        run_test(test_print_one);
        run_test(test_calculate_weight4);
        run_test(test_calculate_weight3);
        run_test(test_calculate_weight2);
        run_test(test_calculate_weight0);
        test_fixture_end();
}

void all_tests( void )
{
        test_fixture_one();
}
