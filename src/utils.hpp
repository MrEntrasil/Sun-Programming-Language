#include <list>
#include <sstream>

typedef std::list<std::string> StrList;

class Utils
{
    public:
    StrList* split(const char* str, const char* delimiter, int limit = -1){
        StrList result;
        std::istringstream iss(str);
        std::string token;
        int counter = 0;

        while (std::getline(iss, token, *delimiter)){
            if (limit != -1 && counter >= limit){
                break;
            }
            counter++;
            result.push_back(token);
        }

        return new StrList(result);
    };
    std::string shift(StrList* list){
        std::string result = list->front();
        list->pop_front();
        return result;
    };
};