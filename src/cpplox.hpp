#include <string>

class CppLox {
public:
    CppLox() {}
    void runPrompt();
    void runFile(const std::string& fileName);
    static void error(int line, std::string message);
    static void report(int line, std::string where, std::string message);
    static bool s_hasError;

private:
    std::string m_source = "";

    void run(const std::string& source);
};