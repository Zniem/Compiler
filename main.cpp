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
    std::optional<std::string> value{};
};

std::vector<Token> tokenize(const std::string& str){
    std::vector<Token> tokens;
    std::string buffer;
    for(int i = 0; i < str.length(); i++){
        char c = str.at(i);
        if(std::isalpha(c)){
            buffer.push_back(c);
            i++;
            if(std::isalnum(str.at(i))){
                buffer.push_back(str.at(i));
                i++;
            }
            i--;
            if(buffer == "return"){
                tokens.push_back({.type = TokenType::_return});
                buffer.clear();
                continue;
            }else{
                std::cerr << "FOUT" << std::endl;
                exit(EXIT_FAILURE);

            }
        }
        else if (std::isdigit(c))
            {
                buffer.push_back(c);
                i++;
                while (std::isdigit(str.at(c)))
                {
                    buffer.push_back(str.at(c));
                    i++;
                }
                i--;
                tokens.push_back({.type = TokenType::_int_lit, .value = buffer});
                buffer.clear();
            }
            else if (c == ';')
            {
                tokens.push_back({.type = TokenType::_semi});
            }
            
            
            else if(std::isspace(c)){
                continue;
            }
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
