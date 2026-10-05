#include <stdio.h>

int main()
{
    {
        FILE *f = fopen("report.txt", "w");
        if (f == NULL)
        {
            perror("report.txt");
            return 1;
        }
        fprintf(f, "User: %s\n", "Alice");
        fprintf(f, "Score: %d\n", 42);
        fclose(f);
    }

    {
        int values[5] = {10, 20, 30, 40, 100500};
        FILE *out = fopen("data.bin", "w");
        fwrite(values, sizeof(int), 5, out);
        fclose(out);
        FILE *in = fopen("data.bin", "rb");
        int x[5];
        fread(x, sizeof(int), 5, in);
        printf("First element is %d\n", *x);
        fclose(in);
    }

    {
        FILE *f = fopen("data.bin", "rb");
        fseek(f, sizeof(int) * 2, SEEK_SET); // от начала
        fseek(f, sizeof(int) * 1, SEEK_CUR); // от текущей позиции (начало + 2)
        fseek(f, sizeof(int) * -5, SEEK_END); // от конца
        int value = 0;
        fread(&value, sizeof(int), 1, f);
        printf("Fifth value is %d\n", value);
        fclose(f);
    }
}
