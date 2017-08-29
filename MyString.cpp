#include "String.h"
void String::copy(const String& other)
{
    this->SIZE = other.SIZE ;
    this->data = new char[SIZE];
    mystrcpy(this->data,other.data);
}
void String::destroy()
{
    delete[] this->data;
}
String::String()
{
    data = nullptr;
    SIZE = 0;
}
String::String(char* data)
{
    this->SIZE = mystrlen(data) + 1;
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
String& String::operator=(char* obj)
{
    destroy();
    this->SIZE = mystrlen(obj);
    this->data = new char[SIZE];
    mystrcpy(data,obj);
    return *this;
}
String::~String()
{
    destroy();
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
   if(index >= 0 && index <= this->SIZE)
        this->data[index] = symbol;
   else
    cout << "error index out of bounds" << endl;
}
char* String::operator+(const String& two)
{
    int size1 = mystrlen(this->data);
    int size2 = mystrlen(two.GetData());
    char* temp = new char[size1 + size2 + 1];
    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }
    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1 + 1] = two[i];
    }
    cout << mystrlen(temp) << endl;
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
    else
    {
        this->SIZE += 1;
        char* temp = new char[this->SIZE];
        mystrcpy(temp,this->data);
        this->data = new char[this->SIZE];
        mystrcpy(this->data,temp);
        this->data[this->SIZE - 1] = ch;
    }
}
char& String::operator[](int index)
{
    return data[index];
}
char String::operator[](int index) const
{
    if(index < 0 || index > SIZE)
        cout << "wrong input" << endl;
    return data[index];
}
bool String::operator<(const String& other)
{
    return (this->SIZE< other.SIZE);
}
bool String::operator>(const String& other)
{
    return(this->SIZE > other.SIZE);
}
bool String::operator<=(const String& other)
{
    return !operator>(other);
}
bool String::operator>=(const String& other)
{
    return !operator<(other);
}
bool String::operator==(const String& other)
{
    bool flag;
    if(this->SIZE !=other.SIZE)
        return flag = false;
    else
    {
        for(int c = 0;c <this->SIZE;c++)
        {
            if(this->data[c] != other[c])
                return flag = false;
        }
    }
    return flag = true;
}
bool String::operator!=(const String& other)
{
    bool flag;
    if(this->SIZE != other.SIZE)
        return flag = true;
    else
    {
        for(int c =0;c<this->SIZE;c++)
        {
            if(this->data[c] != other[c])
                return flag = true;
        }
    }
    return flag = false;
}
String& String::operator+=(const String& other)
{
    int size1 = mystrlen(this->data);
    int size2 = mystrlen(other.data);
    char* temp = new char[size1 + size2 + 1];
    for(int i = 0; i< size1; ++i)
    {
        temp[i] = this->data[i];
    }
    for(int i = 0; i< size2; ++i)
    {
        temp[i + size1] = other[i];
    }
    this->SIZE = mystrlen(temp);
    this->data = new char[this->SIZE];
    mystrcpy(this->data,temp);
    delete[] temp;
    return *this;
}
istream& operator>>(istream& is, String& src)
{
    src.destroy();
    String temp;
    char ch = NULL;
    while(is.get(ch) && ch != '\n')
        temp.AddChar(ch);
    src.SIZE = temp.SIZE ;
    src.data = new char[src.SIZE + 1];
    for(unsigned int c = 0; c < temp.SIZE; c++)
        src.SetAt(c,temp[c]);
    src.data[src.SIZE] = '\0';
    return is;
}
ostream& operator<<(ostream& os, String& src)
{
    os << src.data;
    return os;
}
