#pragma once
#include <string>
#include <optional>
#include <vector>

enum class TokenType{
    _exit,
    _int_lit,
    _semi
};

struct Token{
    TokenType type;
    std::optional<std::string> value{};
};

class Tokenizer{
    public:
        inline Tokenizer(std::string source)
            :m_source(std::move(source))
        {

        }

        std::vector<Token> tokenize(){
    std::vector<Token> tokens;
        std::string buffer;
        for(int i = 0; i < str.length(); i++){
            char c = str.at(i);
            if(std::isalpha(c)){
              buffer.push_back(c);
                i++;
            while(std::isalnum(str.at(i))){
                buffer.push_back(str.at(i));
                i++;
            }
            i--;
            if(buffer == "exit"){
                tokens.push_back({.type = TokenType::_exit});
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
                while (std::isdigit(str.at(i)))
                {
                    buffer.push_back(str.at(i));
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
            else{
                std::cerr << "FOUT" << std::endl;
                exit(EXIT_FAILURE);
            }
    }
    return tokens;
        }



    private:

    std::optional<char> peak() const {
        if(m_index + 1 >= m_source.length()){
            return{};
        }else{
            return m_source.at(m_index);
        }
        
    }

    const std::string m_source;
    int m_index;



};