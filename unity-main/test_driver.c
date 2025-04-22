/*
trustinsoft/demos

Copyright (C) 2022-2024 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"
#include "unity.h"

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

/* Converts an integer array into a string */
static void array_to_string(const int array[], int length, char *outstr);
/* Checks array before/after update */
static int test_array(int *in_array, int len);

/*
TEST_0001: verify with small array
Uptrace: REQ_0123
*/
void test_small_array(void)
{
    int input_array[] = {1, 3, 5, 7, 11, 13, 17};
    int len = sizeof(input_array) / sizeof(int);
    TEST_ASSERT_TRUE(test_array(input_array, len));
}

/*
TEST_0002: verify with big array
Uptrace: REQ_0123
*/
void test_large_array(void)
{
    int input_array[1000];
    for (int i = 0; i < 1000; i++)
        input_array[i] = (rand() > RAND_MAX / 2 ? rand() : -rand());
    int len = sizeof(input_array) / sizeof(int);
    TEST_ASSERT_TRUE(test_array(input_array, len));
}

/*
TEST_0003: test of empty array (GNU extension)
Uptrace: REQ_0123
*/
void test_zero_length(void)
{
    int p[] = {};
    TEST_ASSERT_TRUE(test_array(p, 0));
}

/*
TEST_0004: test of NULL
Uptrace: REQ_0123
*/
void test_null(void)
{
    int *p = NULL;
    TEST_ASSERT_TRUE(test_array(p, 777));
}

#ifdef __TRUSTINSOFT_ANALYZER__
/* TEST_ROBUSTNESS_0005: verify all entries in a big array
Uptrace: REQ_0123
*/
void test_generalized_array(void)
{
    int input_array[1000];
    // This corresponds to 2^32^1000 combinations
    // i.e approximatively 9 x 10^9632 inputs values
    tis_make_unknown(&input_array, sizeof(input_array));

    int len = sizeof(input_array) / sizeof(int);
    increment_array(input_array, 1);
    /* Ignored: does not verify function, only runtime errors */
    TEST_IGNORE();
}
#endif

void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_small_array);
    RUN_TEST(test_large_array);
    RUN_TEST(test_zero_length);
    RUN_TEST(test_null);

#ifdef __TRUSTINSOFT_ANALYZER__
    RUN_TEST(test_generalized_array);
#endif
    return UNITY_END();
}

/* Utility functions for testing */

/* Max number of cells displayed when converting array to string */
#define MAX_STRING_CELLS 10

static void array_to_string(const int array[], int length, char *outstr)
{
    if (array == NULL) {
        strcpy(outstr, "NULL");
        return;
    }
    strcpy(outstr, "{");
    char *p = outstr + strlen(outstr);
    int dotted = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < (MAX_STRING_CELLS/2) || i > length-(MAX_STRING_CELLS/2)) {
            char str[20];
            sprintf(str, "%d%s", array[i], (i == length-1) ? "": ", ");
            strcpy(p, str);
            p += strlen(p);
        } else if (! dotted) {
            strcpy(p, "..., ");
            p += strlen(p);
            dotted = 1;
        }
    }
    strcpy(p, "}");
}

static int test_array(int *in_array, int len)
{
    int ok = 1;
    int string_size = 3;
    if (len <= MAX_STRING_CELLS)
        string_size += len * 15;
    else
        string_size += MAX_STRING_CELLS * 15 + 5;
    char input[string_size];
    char output[string_size];

    if (in_array == NULL)
    {
        array_to_string(in_array, len, input);
        increment_array(in_array, len);
        array_to_string(in_array, len, output);
        ok = (in_array == NULL);
    }
    else
    {
        int out_array[len > 0 ? len : 1];
        if (len > 0)
            memcpy(out_array, in_array, len * sizeof(int));
        array_to_string(in_array, len, input);
        increment_array(out_array, len);
        array_to_string(out_array, len, output);
        for (int i = 0; i < len && ok == 1; i++)
        {
            ok = (out_array[i] == in_array[i] + 1) && ok;
        }
    }
    return ok;
}
