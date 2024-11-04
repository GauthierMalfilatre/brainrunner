/*
** EPITECH PROJECT, 2024
** BRAINRUNNER
** File description:
** Brainfuck compiler
*/
#include <sys/types.h>
#include "include/my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <stdio.h>

#define BUFFER_SIZE 50000

static int print_bf_in_file(int wfd, char *kronk_buffer)
{
    for (int i = 0; i < my_strlen(kronk_buffer); i++) {
        switch (kronk_buffer[i]) {
        case '>':
            write(wfd, "index++;\n", 9);
            break;
        case '<':
            write(wfd, "index--;\n", 9);
            break;
        case '+':
            write(wfd, "ptr[index]++;\n", 14);
            break;
        case '-':
            write(wfd, "ptr[index]--;\n", 14);
            break;
        case '.':
            write(wfd, "putchar(ptr[index]);\n", 21);
            break;
        case ',':
            write(wfd, "read(0, &ptr[index], 1);\n", 25);
            break;
        case '[':
            write(wfd, "while (ptr[index]) {\n", 21);
            break;
        case ']':
            write(wfd, "}\n", 2);
            break;
        default:
            break;
        }
    }
}

static int brainfuck_to_cfile(int fd, int wfd)
{
    char kronk_buffer[BUFFER_SIZE];
    int size = read(fd, kronk_buffer, BUFFER_SIZE - 1);

    write(wfd, "#include <unistd.h>\n#include <stdio.h>\nint main(void) {\nchar ptr[30000] = {};\nint index = 0;\n", 93);
    while (size > 0) {
        print_bf_in_file(wfd, kronk_buffer);
        size = read(wfd, kronk_buffer, BUFFER_SIZE - 1);
    }
    close(fd);
    write(wfd, "return 0;\n}\n", 12);
    close(wfd);
    return 0;
}

int main(int argc, char *const *argv)
{
    int fd;
    int wfd;

    if (argc != 2) {
        my_errstr("brainrunner: You must give one file.\n");
        return 84;
    }
    fd = open(argv[1], O_RDONLY);
    wfd = open("temp.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1 || wfd == -1) {
        my_errstr("brainrunner: error while loading file.\n");
        return 84;
    }
    return brainfuck_to_cfile(fd, wfd);
}
