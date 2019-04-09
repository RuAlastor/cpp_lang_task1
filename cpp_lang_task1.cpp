#include "cpp_lang_task1.h"

using namespace Student;

/* STRING */

//
/* Default destructor */
string::~string() {
    delete [] _data;
}

//
/* Default constructor */
string::string() : _data(nullptr), _size(0) { }
/* Constructs a string with /count/ copies of /ch/*/
string::string(unsigned int count, char ch) {
    _data = new char[count + 1];
    for (unsigned int i = 0; i < count; i++) {
        _data[i] = ch;
    }
    _data[count] = '\0';
}
/* Constructs a string from a substring */
string::string(const char *other, unsigned int count) {
    _data = new char[count];
    strncpy(_data, other, count);
}
/* Constructs a string from a char array
    Behaviour is undefined if strlen(other) is invalid*/
string::string(const char *other) {
    _data = new char[strlen(other)];
    strcpy(_data, other);
}
/* Copy constructor */
string::string(const string &other) : _data(other._data), _size(other._size) { }
/* Move constructor */
string::string(string &&other) : _data(other._data), _size(other._size) {
    other._data = nullptr;
    other._size = 0;
}

//
/* Replaces contents with a copy */
string& string::operator=(const string& other) {
    delete [] _data;
    _data = new char[other._size];
    strcpy(_data, other._data);
    _size = other._size;
    return *this;
}
/* Replaces contents using move semantics */
string& string::operator=(string&& other) {
    delete [] _data;
    _data = other._data;
    _size = other._size;
    other._data = nullptr;
    other._size = 0;
    return *this;
}
/* Replaces contents with those of null-terminated character string */
string& string::operator=(const char* other) {
    delete [] _data;
    _data = new char[strlen(other)];
    strcpy(_data, other);
    _size = strlen(other);
    return *this;
}

//
/* Returns a reference to the character at the specified /pos/ */
char& string::operator[](unsigned int pos) {
    return _data[pos];
}
const char& string::operator[](unsigned int pos) const {
    return _data[pos];
}
/* Returns a reference to the first symbol */
const char* string::data() const {
    return this->_data;
}
/* Returns true if string is empty */
bool string::empty() {
    return _size == 0;
}

/* Returns length of the string */
unsigned int string::size() const {
    return this->_size;
}
/* Clears the contents */
void string::clear() {
    delete [] _data;
    _data = nullptr;
    _size = 0;
}
/* Appends a character at the end */
void string::push_back(char ch) {
    strcat(_data, &ch);
}
/* Removes the last character */
void string::pop_back() {
    char* buffer = new char[_size - 1];
    strncpy(buffer, _data, _size - 1);
    delete [] _data;
    _data = buffer;
}

//
/* Appends characters /count/ symbols from /other/ */
string& string::append(const char* other, unsigned int count) {
    char* buffer = new char[_size + strlen(other)];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    strncat(_data, other, count);
    return *this;
}
/* Appends a string */
string& string::append(const string &other) {
    char* buffer = new char[_size + other.size()];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    strcat(_data, other._data);
    return *this;
}
/* Appends a symbol /count/ times */
string& string::append(unsigned int count, const char &ch) {
    char* buffer = new char[_size + sizeof(char) * count];
    strcpy(buffer, _data);
    delete [] _data;
    _data = buffer;
    for (unsigned int i = 0; i < count; i++) {
        strcat(_data, &ch);
    }
    return *this;
}


/* VECTOR */

//
/* Default destructor */
template <typename T>
vector<T>::~vector() {
    delete [] _data;
}

//
/* Default constructor */
template <typename T>
vector<T>::vector() : _data(nullptr), _size(0) { }
/* Copy constructor */
template <typename T>
vector<T>::vector(const vector &other) : _data(other._data), _size(other._size) { }
/* Move constructor */
template <typename T>
vector<T>::vector(vector &&other) : _data(other._data), _size(other._size) {
    other._data = nullptr;
    other._size = 0;
}
/* Constructs a container with /count/ copies of /val/ */
template <typename T>
vector<T>::vector(unsigned int count, const T& val) : _size(count) {
    _data = new T[_size];
    for (unsigned int i = 0; i < count; i++) {
        _data[i] = val;
    }
}
/* Constructs a container with /count/ empty elements */
template <typename T>
vector<T>::vector(unsigned int count) : _size(count) {
    _data = new T[_size];
}

//
/* Returns a reference to the character at the speciified /pos/ */
template <typename T>
T& vector<T>::operator [](unsigned int pos) {
    return _data[pos];
}
template <typename T>
const T& vector<T>::operator [](unsigned int pos) const {
    return _data[pos];
}
/* Returns pointer to the underlying array serving as elements storage */
template <typename T>
T* vector<T>::data() {
    return _data;
}
template <typename T>
const T* vector<T>::data() const {
    return _data;
}


//
/* Returns true if vector is empty */
template <typename T>
bool vector<T>::empty() const {
    return _size == 0;
}

//
/* Clears the contents */
template <typename T>
void vector<T>::clear() {
    delete [] _data;
    _data = nullptr;
    _size = 0;
}
/* Appends an object to the end */
template <typename T>
void vector<T>::push_back(const T &value) {
    T* buffer = new T[_size + 1];
    memmove(buffer, _data, sizeof(T) * _size);
    delete [] _data;
    _data = buffer;
    _data[_size++] = value;
}
/* Appends an object to the end using move semantic */
template <typename T>
void vector<T>::push_back(T&& value) {
    T* buffer = new T[_size + 1];
    memmove(buffer, _data, sizeof(T) * _size);
    delete [] _data;
    _data = buffer;
    _data[_size++] = std::move(value);
}
/* Removes last element of the container */
template <typename T>
void vector<T>::pop_back() {
    _size--;
}
/* Inserts /count/ copies of /val/ before /pos/ */
template <typename T>
void vector<T>::insert(unsigned int pos, unsigned int count, const T &value) {
    T* buffer = new T[_size + count];
    memmove(buffer, _data, sizeof(T) * pos);
    memmove(buffer + pos + count, _data + pos, sizeof(T) * (_size - pos));
    for (unsigned int i = pos; i < count; i++ ) {
        buffer[i] = value;
    }
    _data = buffer;
}

void print_number_table(short col, short row) {
    int** main_table = new int*[row];
    for (short i = 0; i < row; i++) {
        main_table[i] = new int[col];
    }
    srand(1000);
    print_stars(col);
    for (int i = 0; i < col; i++) {
        short mt_digits = 0;
        std::cout << '|';
        for (int j = 0; j < row; j++) {
            main_table[i][j] = rand() % 200;
            mt_digits = (main_table[i][j] / 100 != 0 ? 3 : (main_table[i][j] / 10 != 0 ? 2 : 1));
            print_element(main_table[i][j], mt_digits);
        }
        std::cout << "\n";
        if (i != col - 1) {
            print_div(row);
        }
    }
    print_stars(col);

    for (short i = 0; i < row; i++) {
        delete [] main_table[i];
    }
    delete [] main_table;
}
void print_element(const int &val, short amount_of_digits) {
    switch (amount_of_digits) {
    case 1:
        std::cout << std::setw(3) << val << std::setw(3) << '|';
        break;
    case 2:
        std::cout << std::setw(4) << val << std::setw(2) << '|';
        break;
    case 3:
        std::cout << std::setw(4) << val << std::setw(2) << '|';
        break;
    default:

        break;
    }
}
void print_div(short row) {
    std::cout << '|';
    for (int i = 0; i < row; i++) {
        std::cout << std::setw(3) << '+' << std::setw(3) << '|';
    }
    std::cout << '\n';
}

void print_stars(short col) {
    std::cout << std::setw(4) << '*';
    for (int i = 1; i < col; i++) {
        std::cout << std::setw(3) << '*' << std::setw(3) << '*';
    }
    std::cout << '\n';
}

/* magic */
template class vector<int>;
template class vector<char>;
/* template class vector<double>;
 * template class vector<float>;
 * template class vector<std::string>;
 * template class vector<Student::vector>;
 *
 * so on...
*/







