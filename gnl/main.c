#include "get_next_line.h"
#include <fcntl.h>

void leaks() {
	system("leaks a.out");
}

int main() {
	//atexit(leaks);
	int fd;
    char *line;

    fd = open("empty.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    line = get_next_line(fd);
    // while (line)
    // {
    //     printf("%s\n", line);
    //     free(line);
    //     line = get_next_line(fd);
    // }
	if(!line)
		printf("nULL");
	else
		printf("%s", line);
	free(line);
    close(fd);
    return 0;
}



