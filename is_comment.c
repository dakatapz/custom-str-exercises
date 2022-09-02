#include <stdio.h>

int is_comment (FILE *fp)
{
	int count = 0;
	char c;

	while ((c = fgetc(fp)) != EOF){
		if (c == '/') {
			c = fgetc(fp);
			if (c == '/' && c != EOF) {
				printf("inside comment\n");
				do {
					c = fgetc(fp);
				}while(c == '\n');
				count++;
			} else if (c == '*' && c != EOF) {
				printf("inside comment\n");
				do {
					c = fgetc(fp);
				}while(c == '*' && (c = fgetc(fp)) == '/' && c != EOF);
				count++;
			}
		}
	}

	return count;

}

void main(int argc, char *argv[])
{
	//variable to store number of comments
	int comments;
	FILE *f;
	f = fopen (argv[1], "r");
	/*test comment*/
	comments = is_comment(f);
	printf("file has %d comment(s)\n", comments);
}
