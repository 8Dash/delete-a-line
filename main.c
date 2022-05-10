#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048
int main()
{
FILE *file, *file1;
char filename[FILENAME_SIZE];
char file1_filename[FILENAME_SIZE];
char buffer[MAX_LINE];
int delete_line=0;
printf("filename:");
scanf("%s",filename);
//file.txt
//file1____file.txt
strcpy(file1_filename,"file1____");
strcat(file1_filename,filename);

printf("Delete Line:");
scanf("%d", &delete_line);
file = fopen(filename,"r");
file1 = fopen(file1_filename, "w");
if (file == NULL || file1 == NULL)
if(file == NULL)
{
printf("Error opening file .\n");
return 1;
}
bool keep_reading=true;
int current_line=1;
do
{
fgets(buffer, MAX_LINE, file);
if(feof(file))keep_reading=false;
else if(current_line != delete_line)
    fputs(buffer, file1);
    current_line++;
} while(keep_reading);
fclose(file);
fclose(file1);
remove(filename);
rename(file1_filename, filename);
return 0;
}
