#include <iostream>
#include <streambuf>
#include <string>
#include <functional>

// Custom stream buffer that intercepts output
class InterceptBuf : public std::streambuf {
public:
    InterceptBuf(std::ostream& stream) : original(stream), old_buf(stream.rdbuf()) {
        stream.rdbuf(this);
    }

    ~InterceptBuf() {
        original.rdbuf(old_buf);
    }

protected:
    virtual int overflow(int c) override {
        if (c != EOF) {
            buffer += static_cast<char>(c);
        }
        return c;
    }

    virtual int sync() override {
        original << "[Intercepted Output]: " << buffer << std::endl;
        buffer.clear();
        return 0;
    }

private:
    std::ostream& original;
    std::streambuf* old_buf;
    std::string buffer;
};

// Template metaprogramming to build a string at compile time
template<char... chars>
struct CompileTimeString {
    static void print(std::ostream& os) {
        const char str[] = {chars..., '\0'};
        os << str;
    }
};

using HelloWorld = CompileTimeString<'H','e','l','l','o',',',' ','W','o','r','l','d','!'>;

// Function pointer trickery
void execute(std::function<void()> func) {
    func();
}

// Main wrapper class
class HelloWorldProgram {
public:
    void run() {
        InterceptBuf buf(std::cout);

        auto lambda =  {
            HelloWorld::print(std::cout);
            std::cout << std::endl;
        };

        std::function<void()> func = lambda;
        execute(func);
    }
};

int main() {
    HelloWorldProgram program;
    program.run();
    return 0;
}

