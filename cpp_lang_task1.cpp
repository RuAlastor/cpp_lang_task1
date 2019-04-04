#include "cpp_lang_task1.h"

//
/* Default destructor */
Student::string::~string() {
    delete [] _data;
}

//
/* Default constructor */
Student::string::string() : _data(nullptr) { }
/* Constructs a string with /count/ copies of /ch/*/
Student::string::string(unsigned int count, char ch) {
    _data = new char[count + 1];
    for (int i = 0; i < count; i++) {
        _data[i] = ch;
    }
    _data[count] = '\0';
}
/* Constructs a string from a substring */
Student::string::string(const char *other, unsigned int count) {
    _data = new char[count];
    strncpy(_data, other, count);
}
/* Constructs a string from a char array
    Behaviour is undefined if strlen(other) is invalid*/
Student::string::string(const char *other) {
    _data = new char[strlen(other)];
    strcpy(_data, other);
}
/* Copy constructor */
Student::string::string(const string &other) : _data(other._data), _size(other._size) { }
/* Move constructor */
Student::string::string(string &&other) : _data(other._data), _size(other._size) {
    other._data = nullptr;
    other._size = 0;
}

//
/* Replaces contents with a copy */
Student::string& Student::string::operator=(const string& other) {
    delete [] _data;
    _data = new char[other._size];
    strcpy(_data, other._data);
    _size = other._size;
    return this;
}
/* Replaces contents using move semantics */
Student::string& Student::string::operator=(string&& other) {
    delete [] _data;
    _data = other._data;
    _size = other._size;
    other._data = nullptr;
    other._size = 0;
    return *this;
}
/* Replaces contents with those of null-terminated character string */
Student::string& Student::string::operator=(const char* other) {
    delete [] _data;
    _data = new char[strlen(other)];
    strcpy(_data, other);
    _size = strlen(other);
    return *this;
}

//
/* Returns a reference to the character at the specified /pos/ */
char& Student::string::operator[](unsigned int pos) {
    return _data[pos];
}
const char& Student::string::operator[](unsigned int pos) const {
    return _data[pos];
}
/* Returns a reference to the first symbol */
const char* Student::string::data() {
    return _data;
}
/* Returns length of the string */
unsigned int Student::string::size() {
    return _size;
}
/* Clears the contents */
void Student::string::clear() {
    delete [] _data;
    _data = nullptr;
    _size = 0;
}
/* Appends a character at the end */
void Student::string::push_back(char ch) {
    strcat(_data, &ch);
}
/* Removes the last character */
void Student::string::pop_back() {
    char* buffer = new char[_size - 1];
    strncpy(buffer, _data, _size - 1);
    delete [] _data;
    _data = buffer;
    buffer = nullptr;
}

//
/* Appends characters /count/ symbols from /other/ */
Student::string& Student::string::append(const char* other, unsigned int count) {
    char* buffer = new char[_size + strlen(other)];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    buffer = nullptr;
    strncat(_data, other, count);
    return *this;
}
/* Appends a string */
Student::string& Student::string::append(const string &other) {
    char* buffer = new char[_size + other.size()];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    buffer = nullptr;
    strcat(_data, other);
}
/* Appends a symbol /count/ times */
Student::string& Student::string::append(unsigned int count, const char &ch) {
    char* buffer = new char[_size + sizeof(char) * count];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    buffer = nullptr;
    for (int i = 0; i < count; i++) {
        strcat(_data, &ch);
    }
}






