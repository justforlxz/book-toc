#include <stdio.h>

int main() {
    void* arr[3] = {0};
    int invalid= *(int*)(arr[0]);
    printf("invalid is: %d", invalid);
    return -1;
}
