#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	printf("1 -> +\n");
	printf("2 -> -\n");

    int pipeToChild[2];
	pipe(pipeToChild);

	int result;
	int first = 0, second = 0, plusmis = 0;
	scanf("%d", &plusmis);
	
	printf("Enter two numbers\n");
	scanf("%d%d", &first, &second);
	pid_t child;
	child = fork();
	if(child < 0) {
	    fprintf(stderr, "Fork failure");
  	    exit(1);	
	} else if (child  == 0) {
		if (plusmis == 1) {
			result = first+second;
        	close(pipeToChild[0]);
        	write(pipeToChild[1], &result, sizeof(int));
        	close(pipeToChild[1]);
        } else if (plusmis == 2) {
        	result = first-second;
        	close(pipeToChild[0]);
        	write(pipeToChild[1], &result, sizeof(int));
        	close(pipeToChild[1]);
        } else {
        	printf("wrong number\n");
        	exit(2);
        }
        exit(0);
    } else {
        close(pipeToChild[1]);
        read(pipeToChild[0], &result, sizeof(int));
        printf("Answer: ");
        printf("%d\n", result);
        close(pipeToChild[0]);
	}
	return 0;
}