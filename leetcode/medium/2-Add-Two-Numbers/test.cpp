#include <iostream>

int main(){
    
    int* a = NULL;
    int* b = (int*) 500;
    printf("Sum: %ld, sizeof int*: %ld, sizeof int: %ld\n", (long) a + (long) b, sizeof(int*), sizeof(int));
    
    //printf("%ld %ld %ld\n", sizeof(int), sizeof(int*), sizeof(long long));
    return 0;
}