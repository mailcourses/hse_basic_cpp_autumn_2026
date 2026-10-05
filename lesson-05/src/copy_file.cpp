#include <fstream>
#include <iostream>
#include <filesystem>

// Написать copy_file: прочитать один файл и записать его содержимое в другой.
// dst не должен существовать изначально.
void copy_file(const std::string& src, const std::string& dst)
{
    std::ifstream input(src);
    
    if(!input) {
        std::cout << "Не удалось открыть файл" << std::endl;
        return;
    }
    
    if(std::filesystem::exists(dst)){
        std::cout << "Выходной файл уже существует" << std::endl;
        return;
    }
    
    std::ofstream output(dst);
    if(!output){
        std::cout << "Выходной файл не удалось создать" << std::endl;
        return;
    }
    
    char buffer[1024];
    
    while(input.read(buffer, sizeof(buffer)) || input.gcount() > 0){
        output.write(buffer, input.gcount());
        //todo: обработка ошибок
    }

    
}

int main(int argc, char** argv)
{
    copy_file(argv[1], argv[2]);
}
