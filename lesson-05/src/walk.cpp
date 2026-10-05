// C++: пройти по папке data/ и вывести имена всех .txt-файлов;
#include <filesystem>
#include <iostream>

using namespace std;
void walk_and_print(const std::string& directory)
{
    for (const auto& file: filesystem::directory_iterator(directory)){
        if (file.is_regular_file() and file.path().extension() == ".txt"){
            cout << file.path().filename() << endl;
        }
    }
    
}

int main()
{
    walk_and_print("./");
    return 0;
}
