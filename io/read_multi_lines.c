/**
 * @file read_multi_lines.c
 * @author imxtx
 * @brief Read numbers from file line by line
 * @version 0.1
 * @date 2021-11-15
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // store numbers from lines
    int nums[100] = {0};

    // open file
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL)
    {
        printf("fail to load file\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;  // store a line
    ssize_t nread;      // number of characters read
    size_t len;         // the length of the line
    while ((nread = getline(&line, &len, fp)) != -1)
    {
        int i = 0;
        char *pos = NULL;
        // read a line of numbers
        while (1)
        {
            // convert a string to a number
            nums[i++] = strtol(line, &pos, 10);
            if (*pos == '\n')  // meet line break
                break;
            // update the start position of the string to be converted
            line = pos;
        }

        // Do something with the data
    }

    fclose(fp);
    return 0;
}
