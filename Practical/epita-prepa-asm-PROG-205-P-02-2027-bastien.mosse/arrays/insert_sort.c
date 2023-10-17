// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x){
    int* i = end;
    while (i > begin && x < *(i - 1))
    {
        *i = *(i - 1);
        i -= 1;
    }
    *i = x;
}

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end){

    int* a = begin + 1;
    while (a < end && *(a-1) <= *a)
    {
        a++;
    }
    
    if (a >= end){
        return;
    }

    for(int* i = begin; i < end; i++)
    {
        array_insert(begin, i, *i);
    }
}


// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x){
    int* i = begin;
    int* j = end;
    int* mid;
    while (i <= j)
    {
        mid = i + (j - i)/2;

        if (*mid == x){
            i = mid;
            break;
        }

        if (x < *mid) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }

    for (int* k = end-1; k > i; k--)
    {
        *(k) = *(k-1);
    }
    *i = x;
}

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end){

    int* a = begin + 1;
    while (a < end && *(a-1) <= *a)
    {
        a++;
    }
    
    if (a >= end){
        return;
    }

    for(int* i = begin; i < end; i++)
    {
        array_insert_bin(begin, i, *i);
    }
}


