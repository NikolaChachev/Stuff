#include "MyString.h"
void String::copy(const String& other)
{
    delete[] this->data;
    this->SIZE = other.GetSize();
    this->data = new char[SIZE];
    mystrcpy(this->data,other.GetData());
}
void String::destroy()
{
    delete[] this->data;
    this->SIZE = 0;
}
String::String()
{
    data = nullptr;
    SIZE = 0;
}
String::String(char* data)
{
    this->SIZE = mystrlen(data);
    this->data = new char[SIZE];
    mystrcpy(this->data,data);
}
String::String(const String& other)
{
    copy(other);
}
String& String::operator=(const String& other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}
String::~String()
{
    destroy();
}
void String::newsize(int newsize)
{
    if(this->SIZE > 0)
    {
    char* temp;
    temp = new char[this->SIZE];
    temp = this->data;
    delete[] data;
    this->SIZE = newsize;
    this->data = new char[SIZE];
    mystrcpy(this->data,temp);
    delete[] temp;
    }
    else
    {
        delete[] data;
        this->SIZE = newsize;
        data = new char[SIZE];
    }
}
void String::SetSize(int newSize)
{
    newsize(newSize);
}
int String::GetSize() const
{
    return this->SIZE;
}
char* String::GetData() const
{
    return this->data;
}

void String::SetAt(int index, char symbol)
{
    this->data[index] = symbol;
}
char* String::operator+(const String& two)
{
   int size1 = mystrlen(this->data);
   int size2 = mystrlen(two.GetData());
   char* temp = new char[size1 + size2];

    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }

    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1] = two[i];
    }

    temp[size1+size2] = '\0';
    return temp;
}
void String::AddChar(char ch)
{
    if(this->SIZE == 0)
    {
        this->SIZE += 1;
        this->data = new char[SIZE];
        data[SIZE - 1] = ch;
    }
    else{
     this->SIZE += 1;
     data[SIZE - 1] = ch;
    }

}
void String::concat(char* other)
{
    int size1 = mystrlen(this->data);
    int size2 = mystrlen(other);
    char * temp = new char[size1 + size2 + 1];

    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }

    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1] = other[i];
    }

    temp[size1+size2 + 1] = '\0';
    delete[] this->data;
    this-> data = temp;
}
istream& operator>>(istream& is, String& src)
{
    src.~String();
    String temp;
    char ch = NULL;
    while(is.get(ch) && ch != '\n')
        temp.AddChar(ch);
    src.SetSize(temp.GetSize());
    for(unsigned int c = 0; c < temp.GetSize(); c++)
        src.SetAt(c,temp[c]);
    return is;
}
char& String::operator[](int index)
{
       return data[index];
}
char& String::operator[](int index) const
{
    if(index < 0 || index > SIZE)
        cout << "wrong input" << endl;
    return data[index];
}
ostream& operator<<(ostream& os, String& src)
{
    for(int c = 0; c < src.GetSize(); c++)
        os << src[c];


    return os;
}
