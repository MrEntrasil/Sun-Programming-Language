#include <string>

enum TokenType
{
    // * Single-character tokens
    Sun_OpenParen, Sun_CloseParen,
    Sun_MathOperator,
    // * Literals
    Sun_String,
    Sun_Number,
    Sun_Boolean,
    Sun_Nill,
    Sun_Equal
};

typedef struct {
    public:
    enum TokenType type;
    std::string value;
} Token;

Token createToken(std::string value, enum TokenType type){
    Token tk;
    tk.type = type;
    tk.value = value;

    return tk;
}