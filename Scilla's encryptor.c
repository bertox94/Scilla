#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define CAPACITY 100000

void get_three(int num, int three_items[]);

void reverse(int array[]);

void arrcat(int collection[], int i, int three_items[]);

int properly_insert(int collection[], int i, int encoded[]);

int pick_garbage(int k);

int pick_garbage_r();

void finalize(int arr[], int lenght);

void finalize2(int arr[], int lenght);

void closure_in_congruence(int arr[], int lenght);

void print(int encoded[], int lenght);


void main() {

    printf("Welcome to Scilla's encryptor!\nv0.2 \n\n");


    //int speech[CAPACITY];
    int temp;
    int three_items[2];
    int collection[CAPACITY];
    int encoded[CAPACITY];
    int lenght;
    int i = 0;
    int j = 0;
    int k = 0;


    //char encoded_ch[CAPACITY];

    while (temp != 10) {
        temp = (int) getchar();
        if (temp != 10) {
            if (temp < 0) {
                temp = temp + 256;
            }

            get_three(temp, three_items);
            //reverse(three_items);					
            arrcat(collection, i, three_items);
            //printf_array(collection, 3*i +3);
            i++;
        }
    }


    lenght = properly_insert(collection, 3 * (i), encoded);
    finalize(encoded, lenght);
    print(encoded, lenght);

    sleep(8);
    return;
}

void get_three(int num, int three_items[]) {
    int i = 0;
    while (i < 3) {
        three_items[i] = num % 10;
        num = num / 10;
        i++;
    }
}

void reverse(int array[]) {
    int temp;
    temp = array[0];
    array[0] = array[2];
    array[2] = temp;
}

void arrcat(int collection[], int i, int three_items[]) {
    int k = 0;

    i = 3 * i;

    for (k; k < 3; k++) {
        collection[i] = three_items[k];
        i++;
    }
}

int properly_insert(int collection[], int i, int encoded[]) {
    int j = 0;
    int k = 0;

    while (j < i) {
        if (collection[j] % 2 == 0 && k % 2 == 0) {
            encoded[k] = collection[j];
            j++;
        } else if (collection[j] % 2 == 1 && k % 2 == 1) {
            encoded[k] = collection[j];
            j++;
        } else
            encoded[k] = pick_garbage(k);
        k++;
    }

    int pad = pick_garbage_r();
    int h = 0;
    while (pad % 2 != k % 2 && h < 5) {
        encoded[k] = pad;
        k++;
        h++;
        pad = pick_garbage_r();
    }

    return k;
}

int pick_garbage(int k) {
    int num = (int) (int *) malloc(sizeof(int));
    num = abs(k * num + clock());

    while (k % 2 == num % 2) {
        num++;
    }
    return num % 10;
}

int pick_garbage_r() {
    int num = (int) (int *) malloc(sizeof(int));

    return abs((clock() + num)) % 10;
}

void finalize(int arr[], int lenght) {
    int encoded[CAPACITY];
    int key = 0;
    int i = 0;

    while (i < lenght) {
        key = key + arr[i];
        i++;
    }

    i = 0;

    key = key % lenght;


    while (i < lenght) {
        if (key == lenght)
            key = 0;
        encoded[i] = arr[key];
        i++;
        key++;
    }

    i = 0;

    while (i < lenght) {
        arr[i] = encoded[i];
        i++;
    }

    finalize2(arr, lenght);
    closure_in_congruence(arr, lenght);


}

void print(int encoded[], int lenght) {
    int i = 0;
    printf("\n\n");
    while (i < lenght) {
        printf("%d", encoded[i]);
        i++;
    }
}


void finalize2(int arr[], int lenght) {
    int encoded[CAPACITY];
    int incr = 0;
    int key;
    int i = 0;
    int sign = 1;
    key = lenght / 2;


    while (i < lenght) {
        encoded[i] = arr[key + sign * incr];
        key = key + sign * incr;
        incr++;
        i++;
        if (sign > 0)
            sign = -1;
        else
            sign = 1;
    }

    i = 0;


    while (i < lenght) {
        arr[i] = encoded[i];
        i++;
    }

}

void closure_in_congruence(int arr[], int lenght) {
    int i = 1;

    while (i < lenght) {
        arr[i] = (arr[i] + arr[i - 1]) % 10;
        i++;
    }
}
