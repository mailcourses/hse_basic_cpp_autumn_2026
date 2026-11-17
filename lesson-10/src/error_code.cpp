#include <iostream>
#include <system_error>

enum class Error
{
    Success,
    Failure
};

[[nodiscard]]
Error doSomething()
{
    return Error::Success;
}

enum class HttpCode
{
    Ok = 200,
    NotFound = 404,
    InternalServerError = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const override
    {
        switch(code)
        {
            case 200:
                return "ok";
            case 404:
                return "not found";
            case 500:
                return "internal server error";
            default:
                return "unknown";
        }
    }
};

std::error_code make_error_code(HttpCode code)
{
    static const HttpCategory instance;
    return std::error_code(static_cast<int>(code), instance);
}

std::error_code download(const std::string& url)
{
    if (url == "https://vk.com")
        return make_error_code(HttpCode::Ok);
    if (url == "https://bbc.uk")
        return make_error_code(HttpCode::InternalServerError);
    if (url == "https://google.com")
        return make_error_code(HttpCode::NotFound);
    return make_error_code(HttpCode::NotFound);
}

int main()
{
    {
        [[maybe_unused]]auto error = doSomething();
    }

    {
        std::vector<std::string> urls = {"https://vk.com", "https://google.com", "https://bbc.uk"};
        for (auto url : urls)
        {
            auto error = download(url);
            if (error)
            {
                std::cout << error << std::endl;
                std::cout << error.message() << std::endl;
            }
        }
    }
    return 0;
}
