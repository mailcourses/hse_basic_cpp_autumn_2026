#include <iostream>

enum class VK_TYPE
{
    ORIGINAL = 1,
    REPOST,
    UNDEFINED,
    SIZE
};

enum GROUP_TYPE
{
    PERSON = 200,
    GY_GROUP = 404,
    UNDEFINED = 500,
    SIZE = 'd'
};

union Header
{
    int flag;      // 4 байта
    char linkage;  // 1 байт
    double offset; // 8 байт
};

union Color
{
    uint32_t code; // 0xRRGGBBAA
    struct {
        uint8_t r, g, b, a;
    } rgba;
};

class mystring 
{
union string_data
{
    char data_[16];
    struct {
        size_t size_;
        char* data_;
    } head_;
};

};

int main()
{
    VK_TYPE type = VK_TYPE::REPOST;
    std::cout << static_cast<char>(SIZE) << std::endl;

    Header head;
    head.flag = 10;
    std::cout << sizeof(Header) << std::endl;      
    std::cout << head.offset << std::endl;

    Color russina_blue;
    russina_blue.code = 0x0036A7FF;
    std::cout << (int)russina_blue.rgba.r << " : " << (int)russina_blue.rgba.g << " : " << (int)russina_blue.rgba.b << " : " << (int)russina_blue.rgba.a << std::endl; // TODO: почему rgba.a == 0?
    return 0;
}
