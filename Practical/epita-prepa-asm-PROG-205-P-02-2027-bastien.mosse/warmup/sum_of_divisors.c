# include <stdio.h>

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    *count = 0;
    unsigned long sum = 0;
    for(unsigned long i = 1; i*i <= n; i++){
        if (n % i == 0 && n/i != i && i != 1) {
            sum += i + n/i;
            *count += 2;
        }
        else if (n % i == 0)
        {
            sum += i;
            (*count)++;
        }
    }
    return sum;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n", count);
}