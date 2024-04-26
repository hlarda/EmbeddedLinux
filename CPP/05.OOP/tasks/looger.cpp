#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

enum class logLevel : char{
    debug,
    info,
    warning,
    error
};

#define LVL_TO_STR(lvl) \
    (lvl == logLevel::debug ? "DEBUG" : \
    (lvl == logLevel::info ? "INFO" : \
    (lvl == logLevel::warning ? "WARN" : \
    (lvl == logLevel::error ? "ERROR" : "UNKNOWN"\
	))))

class loger{
private:
    vector<unordered_map<string, string>> logs;
    logLevel USR_LVL;
    logLevel lvl;
public:
    loger():USR_LVL(logLevel::info){}

    loger(logLevel level):USR_LVL(level){}

    void log(logLevel level, string message){
        if( level >= USR_LVL){
            unordered_map< string, string> logEntry;
            logEntry[message] = LVL_TO_STR(level);
            logs.push_back(logEntry);
        }
    }

    void dump(){
        for(auto log : logs){
            for(auto entry : log){
                cout <<"["<< entry.second<< "] "<<entry.first<< endl;
            }
        }
    }

    void clear(){
        logs.clear();
    }

    loger operator<<(string message){
        log(lvl, message);
        return *this;
    }

    loger& log(logLevel level){
        lvl = level;
        return *this;
    }

    ~loger()=default;
};

int main(int argc, char const *argv[])
{
    loger l(logLevel::error);
    l.log(logLevel::info)<<"log";

    l.log(logLevel::debug, "debug");
    l.log(logLevel::warning, "warning");
    l.log(logLevel::info, "info");
    l.log(logLevel::error, "error");
    l.dump();
    l.log(logLevel::info, "wont be printed");
    l.clear();
    l.dump();

    return 0;
}

