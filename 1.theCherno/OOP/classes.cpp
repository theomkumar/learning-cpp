#include<iostream>
using namespace std;
//incomplete

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }
    void Warn(const char * message)
    {
        cout << "[WARNING]: " << message <<"\n";
    }
    void Info(const char * message)
    {
        cout << "[INFO]: " << message <<"\n";
    }
    void Error(const char * message)
    {
        cout << "[Error]: " << message <<"\n";
    }
};
int main() 
{
    Log log;
    log.SetLevel(LogLevelWarning);
    log.Warn("Danger!");
    return 0;
}