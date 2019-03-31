#include <stdio.h>

typedef struct item_
{
    int key;
    int value;
} item;

int sort(item *data, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - i - 1; ++j)
        {
            if (data[j].key >= data[j + 1].key)
            {
                // swap data[i] and data[j];
                item tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

void dump(item *data, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("data[%d] is key=%d, value=%d\n", i, data[i].key, data[i].value);
    }
}

int main()
{
    item data[3];
    int size = sizeof(data) / sizeof(data[0]);

    data[0].key = 10;
    data[0].value = 1;
    data[1].key = 10;
    data[1].value = 2;
    data[2].key = 2;
    data[2].value = 3;

    printf("before sort:\n");
    dump(data, size);

    sort(data, size);

    printf("\nafter sort:\n");
    dump(data, size);
}
