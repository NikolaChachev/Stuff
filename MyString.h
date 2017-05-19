#pragma once
#include "MyFunc.h"
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
    bool operator<(const String&);
    bool operator>(const String&);
    bool operator<=(const String&);
    bool operator>=(const String&);
    bool operator==(const String&);
    bool operator!=(const String&);
    String& operator+=(const String& other);
    friend ostream& operator<<(ostream&, String&);
    friend istream& operator>>(istream&, String&);
    char GetAt(int);
    void AddChar(char);
    void SetAt(int, char);

};
