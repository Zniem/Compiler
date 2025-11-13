#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

enum class TokenType{
    _return,
    _int_lit,
    _semi
};

struct Token{
    TokenType type;
    std::optional<std::string> value;
};

std::vector<Token> tokenize(const std::string& str){
    for(int c = 0; c < str.length(); c++){


    }
};

int main(int argc, char const *argv[])
{
    if(argc != 2){
        std::cerr << "Incorrect usage. Correct usage is: " << std::endl;
        std::cerr << "sm <File.sm>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }
    tokenize(contents);
   
    

    return EXIT_SUCCESS;
}
