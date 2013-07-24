#include <stdio.h>

void print_arguments(int argc, char *argv[]);
void print_1(int ages[], char *name[]);
void print_2(int *cur_age, char **cur_name, int count);
void print_3(int *cur_age, char **cur_name, int count);
void print_4(int *cur_age, char **cur_name, int count);

void print_arguments(int argc, char *argv[])
{
	int i;
	for (i = argc; i > 0; ) {
		printf("argument %d: %s\n",
				--i, argv[i]);
	}
}

void print_1(int ages[], char *name[])
{
	int i;
	int count = sizeof(ages) / sizeof(int);

	for (i = count - 1; i >= 0; --i) {
		printf("%s has %d years alive.\n",
				name[i], ages[i]);
	}

}

void print_2(int *cur_age, char **cur_name, int count)
{
	int i;
	for (i = count - 1; i > 0; --i) {
		printf("%s is %d years old.\n",
				*(cur_name + i), *(cur_age + i));
	}
}

void print_3(int *cur_age, char **cur_name, int count)
{
	int i;
	for (i = count - 1; i > 0; --i) {
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}
}

void print_4(int *cur_age, char **cur_name, int count)
{
	int *start = cur_age;
	for (;(cur_age - start) < count; cur_age++, cur_name++) {
		printf("%s is %d years old ...\n",
				*cur_name, *cur_age);
	}
}


int main(int argc, char *argv[])
{
	int i;
	for (i = argc; i > 0;){
		printf("argument %d: %s\n",
				--i, argv[i]);
	}
	// create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);

	// first way using indexing
	for (i = count - 1; i >= 0; --i) {
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	printf("---\n");

	// setup the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for (i = count - 1; i >= 0; --i) {
		printf("%s is %d years old.\n",
				*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way, pointers are just arrays
	for (i = count - 1; i >= 0; --i) {
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for (cur_name = names + count-1, cur_age = ages + count-1;
			(cur_age - ages) >= 0;
			cur_name--, cur_age--)
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
		printf("cur_age: %p\ncur_name: %p\n", cur_age, cur_name);
	}

	printf("---1\n");

	print_1(ages, names);

	return 0;
}
