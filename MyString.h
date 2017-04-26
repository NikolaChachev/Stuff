#ifndef String_H
#define String_H
#include "MyFunc.h"
#include "vector"
class String
{
  char* data;
  int SIZE;
  void destroy();
  void copy(const String&);
  void newsize(int);
public:
    String();
    String(char*);
    String(const String&);
    String& operator=(const String&);
    ~String();
    void SetSize(int);
    int GetSize() const;
    char* GetData() const;
    char* operator+(const String&);
    char& operator[](int);
    char& operator[](int) const;
    friend ostream& operator<<(ostream&, String&);
    friend istream& operator>>(istream&, String&);
    char GetAt(int);
    void AddChar(char);
    void SetAt(int, char);
};

#endif // String_H
