#include <cstdio>
#include <cstdint>
/*
 * ● Открыть file.txt, вывести первые две строки и корректно закрыть файл.
 * ● Добавить понятное сообщение, если файл не открылся.
 * ● Изменить режим так, чтобы программа не стирала старый лог при дозаписи.
 * */

const char* const FILE_NAME = "/home/poisk/hse_basic_cpp_autumn_2026/lesson-05/src/tmp/file.txt";
const uint32_t MAX_LINES = 2;

void excercise()
{
    FILE* file = fopen(FILE_NAME, "r");
    
    if (file == nullptr)
    {
        printf("Не удалось открыть файл\n");
        return;
    }
    
    char line[256];
    
    for (int i = 0; i < MAX_LINES; ++i)
    {
        if (fgets(line, sizeof(line), file) != nullptr)
            printf("%s", line);
    }
    
    fclose(file);
}

int main()
{
    excercise();
}
