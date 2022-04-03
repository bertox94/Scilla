#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define CAPACITY 100000

void reverse(int array[]);
void arrcat_undo(int collection[], int i);
int properly_insert_undo(int collection[], int i);
int pick_garbage(int k);
void finalize_undo(int arr[],int lenght);
void finalize2_undo(int arr[],int lenght);
void opening_in_congruence(int arr[], int lenght);
void print(int encoded[], int lenght);




void main()
{

	printf("Welcome to Scilla's decrypter!\nv0.2 \n\n");


	//int speech[CAPACITY];
	char temp;
	int three_items[2];
	int collection[CAPACITY];
	int encoded[CAPACITY];
	int decoded[CAPACITY];
	int lenght;
	int i = 0;
	int j = 0;
	int k = 0;


	//char encoded_ch[CAPACITY];

	
	/*while(temp != 10){
		temp = getchar();	
		if(temp != 10){							
		get_three((int)temp, three_items);
		arrcat(collection, i, three_items);
						//printf_array(collection, 3*i +3);
		i++;
		}
	}

											
	lenght = properly_insert(collection, 3*(i), encoded);
	finalize(encoded, lenght);
	print(encoded, lenght);
*/

	while(temp != 10){
		temp = getchar();	
		if(temp != 10){							
			encoded[i] = (int)temp-48;
		i++;
		}
	}
	lenght = i;
	finalize_undo(encoded, lenght);

	lenght = properly_insert_undo(encoded, lenght);
															//printf(" lenght is%d", lenght );
	arrcat_undo(encoded, lenght/3);

	print(encoded, lenght/3);




	sleep(8);
	return ;
}

void get_three_undo(int num, int three_items[]){
	int i = 0;
	while(i<3){
		three_items[i] = num%10;
		num = num/10;
		i++;
	}		
}

void reverse(int array[]){
	int temp;
	temp = array[0];
	array[0] = array[2];
	array[2] = temp;
}

void arrcat_undo(int collection[], int i){
	int j = 0;

	while(j<i){
																								//	printf("yyyyyyyyyy\n");
		collection[j] = collection[3*j]+collection[3*j+1]*10+collection[3*j+2]*100;
		j++;
	}
}

int properly_insert_undo(int collection[], int i){
	int j = 0;
	int k = 0;

	while(k<i){
		if(collection[k]%2==0 && k%2==0){
			collection[j] = collection[k];
			j++;
		}
		else if(collection[k]%2 ==1 && k%2==1){
			collection[j] = collection[k];	
			j++;	
		}

		k++;
	}
	return j;
}


void finalize_undo(int arr[],int lenght){
	int encoded[CAPACITY];
	int key = 0;
	int i = 0;
opening_in_congruence(arr, lenght);
finalize2_undo(arr, lenght);

	while(i<lenght){
		key = key+ arr[i];
		i++;
	}

	i = 0;

	key = key%lenght;
	key = lenght -key;

	while(i<lenght){
		if (key == lenght)
			key = 0;
		encoded[i] = arr[key];
		i++; key++;
	}

	i = 0;
	
	while(i<lenght){
		arr[i] = encoded[i];
						//printf("%d\n", arr[i]);
		i++;
	}
}

void print(int encoded[], int lenght){
	int i = 0;
	printf("\n\n");
	while(i<lenght){
		printf("%c",encoded[i]);
		i++;
	}
}


void finalize2_undo(int arr[],int lenght){
int encoded[CAPACITY];
int i = 0;
int sign = -1;
int incr = 0;
int key;

	key = (lenght/2)*2-1;
	while(i<lenght){
		encoded[i] = arr[key];
		if(key%2 == 1 && key != 1)
		{
			key= key-2;
		}
		else if(key == 1)
			key = 0;
		else
			key = key+2;
	i++;

	}

	i = 0;

	while(i<lenght){
		arr[i] = encoded[i];
						//printf("%d\n", arr[i]);
		i++;
	}
}


void opening_in_congruence(int arr[], int lenght){
	int i = lenght-1;

	while(i>0){
		arr[i] = arr[i]-arr[i-1];
		if(arr[i]<0)
			arr[i]+=10;
		i--;
	}
}

