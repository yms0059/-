#include <stdio.h>
#include <string.h>
#define CAPACITY 100
#define BUFFER_SIZE 20
char * names[CAPACITY]; /* names */
char * numbers[CAPACITY]; /* phone numbers */
int n = 0; /* number of people in phone directory */
void add();
void find();
void status();
void remove();

int main() {
	char buffer[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", buffer);
		if (strcmp(buffer, "read") == 0)
			load();
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "find") == 0)
			find();
		else if (strcmp(buffer, "status") == 0)
			status();
		else if (strcmp(buffer, "delete") == 0)
			remove();
		else if (strcmp(buffer, "save") == 0)
			save();
		else if (strcmp(buffer, "exit") == 0)
			break;
	}
	return 0;
}


void load() {
	char fileName[BUFFER_SIZE]; //파일 이름입력바든ㄴ곳
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	scanf("%s", fileName); //파일 이름을 입력받는다.

	FILE*fp = fopen(fileName, "r");//파일에 접근하기 위해서는 먼저 파일을 열어야 open해야한다.
	if (fp == NULL) {
		printf("파일오픈 실패");
		return;
	}

	while ((fcanf(fp, "%s", buf1) != EOF)) {
		fcanf(fp, "%s", buf2);
		names[n] = strdup(buf1);
		numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp); //일을 마무리하면 반드시 닫아주어야한다
}

void save() {
	int i;
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (i = 0; i<n; i++) {
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}



void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);
	int i = n - 1;
	while (i >= 0 && strcmp(names[i], buf1) > 0) {
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = strdup(buf1);
	numbers[i + 1] = strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);
}


/*char *strdup(char *s)
{
char *p;
p = (char *)malloc(strlen(s) + 1);
if (p != NULL)
strcpy(p, s);
return p;
}*/

void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf);
	if (index == -1)
		printf("No person named '%s' exists.\n", buf);
	else
		printf("%s\n", numbers[index]);
}

void status() {
	int i;
	for (i = 0; i<n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}

void remove() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf); /* returns -1 if not exists */
	if (index == -1) {
		printf("No person named '%s' exists.\n", buf);
		return;
	}
	int j = index;
	for (; j<n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully. \n", buf);
}

int search(char *name) {
	int i;
	for (i = 0; i<n; i++) {
		if (strcmp(name, names[i]) == 0) {
			return i;
		}
	}
	return -1;
}