/* array_min_max.c: min and max searching */

# define _XOPEN_SOURCE 500

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

# include "tests_tools.h"

# define MAXVAL 100
# define STEP 10

/*
 * In all following functions parameters array and len are defined as:
 * array: an integer array
 * len: the length of the array, must be greater than 0
 */

/*
 * min and max value
 */

/*
 * array_min(array, len): returns min value of array
 */
int array_min(int array[], size_t len)
{
	if(len < 1){ errx(1, "Error"); }
	int min = array[0];
	for(size_t icr = 0; icr < len; icr++){
		if(array[icr] < min){
			min = array[icr];
		}
	}
	return min;
}

/*
 * array_max(array, len): returns max value of array
 */
int array_max(int array[], size_t len)
{
	if(len < 1){ errx(1, "Error"); }
	int max = array[0];
	for(size_t icr = 0; icr < len; icr++){
		if(array[icr] > max){
			max = array[icr];
		}
	}
	return max;
}

/*
 * min and max index
 */

/*
 * array_min_index(array, len): returns the index of the min value of array
 */
size_t array_min_index(int array[], size_t len)
{
	if(len < 1){ errx(1, "Error"); }
	size_t id_min = 0;
	int min = array[id_min];
	for(size_t icr = 0; icr < len; icr++){
		if(array[icr] < min){
			min = array[icr];
			id_min = icr;
		}
	}
	return id_min;
}

/*
 * array_max_index(array, len): returns the index of the max value of array
 */
size_t array_max_index(int array[], size_t len)
{
	if(len < 1){ errx(1, "Error"); }
	size_t id_max = 0;
	int max = array[id_max];
	for(size_t icr = 0; icr < len; icr++){
		if(array[icr] > max){
			max = array[icr];
			id_max = icr;
		}
	}
	return id_max;
}

/*
 * Tests
 */

/*
 * Test functions
 */

/*
 * min value tests
 */
void test_min(int array[], size_t len)
{
    int min;
    printf("*** Test min value search ***\n");

    printf("**** Sorted array ****\n");
    array_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min(array, len);
    printf("  array_min: %d\t(should be %d)\n", min, array[0]);

    printf("**** Reverse sorted array ****\n");
    array_reverse_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min(array, len);
    printf("  array_min: %d\t(should be %d)\n", min, array[len - 1]);

    printf("**** Random array ****\n");
    array_random_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min(array, len);
    printf("  array_min: %d\n", min);
}

/*
 * max value tests
 */
void test_max(int array[], size_t len)
{
    int max;
    printf("*** Test max value search ***\n");

    printf("**** Sorted array ****\n");
    array_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max(array, len);
    printf("  array_max: %d\t(should be %d)\n", max, array[len - 1]);

    printf("**** Reverse sorted array ****\n");
    array_reverse_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max(array, len);
    printf("  array_max: %d\t(should be %d)\n", max, array[0]);

    printf("**** Random array ****\n");
    array_random_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max(array, len);
    printf("  array_max: %d\n", max);
}

/*
 * min index test
 */
void test_min_index(int array[], size_t len)
{
    size_t min;
    printf("*** Test min value index search ***\n");

    printf("**** Sorted array ****\n");
    array_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min_index(array, len);
    printf("  array_min_index: array[%zu] = %d\n", min, array[min]);

    printf("**** Reverse sorted array ****\n");
    array_reverse_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min_index(array, len);
    printf("  array_min_index: array[%zu] = %d\n", min, array[min]);

    printf("**** Random array ****\n");
    array_random_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    min = array_min_index(array, len);
    printf("  array_min_index: array[%zu] = %d\n", min, array[min]);
}

/*
 * max index test
 */
void test_max_index(int array[], size_t len)
{
    size_t max;
    printf("*** Test max value index search ***\n");

    printf("**** Sorted array ****\n");
    array_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max_index(array, len);
    printf("  array_max_index: array[%zu] = %d\n", max, array[max]);

    printf("**** Reverse sorted array ****\n");
    array_reverse_sorted_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max_index(array, len);
    printf("  array_max_index: array[%zu] = %d\n", max, array[max]);

    printf("**** Random array ****\n");
    array_random_fill(array, len, MAXVAL);
    array_print(array, len, MAXVAL);
    max = array_max_index(array, len);
    printf("  array_max_index: array[%zu] = %d\n", max, array[max]);
}

/*
 * main
 */
int main(int argc, char *argv[])
{
    size_t len;
    if (argc < 2)
        errx(1, "must provide array length");
    len = strtoul(argv[1], NULL, 10);
    int *array = calloc(len, sizeof (int));

    test_min(array, len);
    printf("\n");

    test_max(array, len);
    printf("\n");

    test_min_index(array, len);
    printf("\n");

    test_max_index(array, len);
    printf("\n");

    free(array);
    return 0;
}
