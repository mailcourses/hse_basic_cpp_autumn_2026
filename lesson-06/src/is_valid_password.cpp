/*
 * Пароль валиден, если
 * - состоять из символов таблицы ASCII с кодами от 33 до 126;
 *   - быть не короче 8 символов и не длиннее 14;
 *   - из 4 классов символов — большие буквы, маленькие буквы, цифры, 
 *     прочие символы — в пароле должны присутствовать не менее трёх любых.
 *     */

#include <cassert>
#include <string>
#include <vector>
#include <bitset>

namespace CHARS
{
enum CHARS
{
    upper = 0,
    lower,
    digit,
    symbol,
    size
};
}

const uint8_t MIN_CLASS_COUNT = 3;
const uint8_t MIN_PASSWORD_LEN = 8;
const uint8_t MAX_PASSWORD_LEN = 14;

int issymbol(int ch)
{
    return !std::islower(ch) && !std::isupper(ch) && !std::isdigit(ch);
}

bool isValidPassword(const std::string& password)
{
    if (password.size() < MIN_PASSWORD_LEN || password.size() > MAX_PASSWORD_LEN)
        return false;
    
    std::bitset<CHARS::size> flags;
    
    const std::vector<std::pair<int (*)(int), CHARS::CHARS>> rules = {
        {std::islower, CHARS::lower},
        {std::isupper, CHARS::upper},
        {std::isdigit, CHARS::digit},
        {issymbol, CHARS::symbol}
    };
    
    for (char ch: password)
    {
        if (ch < 33 || ch > 126)
            return false;
        
        auto set_flags_lambda = [ch, &flags](int (*predicator)(int), CHARS::CHARS flag) {
            if (predicator(ch))
                flags.set(flag, true);
        };
        
        for (auto [pred, symbol] : rules) {
            set_flags_lambda(pred, symbol);
        }
        
    }
    
    return flags.count() >= MIN_CLASS_COUNT;
}

int main()
{
    assert(!isValidPassword("a1F_"));
    assert(!isValidPassword("aaaaaaaa"));
    assert(!isValidPassword("aaaa1234"));
    assert(!isValidPassword("a1F_a1F_a1F_a1F_"));

    assert(isValidPassword("a1F_a1F_"));
    assert(isValidPassword("aaaBBB1234"));
    assert(isValidPassword("_()@BBB1234"));
    assert(isValidPassword("_()@aaa1234"));
    assert(isValidPassword("_()@aaaBBBB"));
}
