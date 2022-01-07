#include <stdio.h>
#include <string.h>
#define MAX 15

int arr_item_num_char(char* arr);
int arr_item_num_arr(int arr[]);

main()
{
	char input;
	char input2[MAX];
	int length;
	printf("What do you have string or else?(type s or e))\n");
	scanf("%c ",&input);
	if (input == 's')
	{
		printf("Enter your string\n");
		fgets(input2, sizeof(input2), stdin);
		length = arr_item_num_char(input2);
		printf("Number of items in the array: %d\n",length);
	}
	else
	{
		printf("Enter the array's components one by one\n");
		
	}
}

int arr_item_num_char(char* arr)
{
	int ans;
	ans = strlen(arr);
	return ans; 
}

int arr_item_num_arr(int arr[])
{
	return sizeof(arr)/sizeof(arr[0]);
}
