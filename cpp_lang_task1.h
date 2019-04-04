#ifndef CPP_LANG_TASK1_H
#define CPP_LANG_TASK1_H

#include <iostream>

namespace Student {

class string {
private:
    char* _data;
    unsigned int _size;
    static const unsigned int npos = -1;
public:
    ~string();

    string();
    string(unsigned int count, char ch);
    string(const char* other, unsigned int count);
    string(const char* other);
    string(const string& other);
    string(string&& other);

    string& operator= (const string& other);
    string& operator= (string&& other);
    string& operator= (const char* other);

    char& operator[](unsigned int pos);
    const char& operator[](unsigned int pos) const;
    const char* data() const;
    bool empty();
    unsigned int size() const;
    void clear();
    void push_back(char ch);
    void pop_back();

    string& append(const char* other, unsigned int count);
    string& append(const string& other);
    string& append(unsigned int count, const char& ch);

    string substr(unsigned int pos = 0, unsigned int count = npos);

};

}

#endif // CPP_LANG_TASK1_H
