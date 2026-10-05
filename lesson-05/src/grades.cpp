#include <cstdio>
#include <cstdint>

// На языке C: прочитать grades.txt, посчитать средний балл и вывести результат;

const char* const FILE_NAME = "grades.txt";

double mean()
{
    FILE *f = fopen(FILE_NAME, "r");
    
    if (!f){
        perror("Не удалось открыть файл");
    }
    
    uint32_t grade = 0;
    uint32_t summ = 0;
    uint32_t cnt = 0;
    
    
    while(!feof(f)){
        fscanf(f, "%d", &grade);
        
        summ += grade;
        cnt++;
    }

    fclose(f);
    return summ / static_cast<double>(cnt);
}

int main()
{
    printf("mean grade is %f\n", mean());
}
