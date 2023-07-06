#include<iostream>

using namespace std;

class FixedString
{ 
  private:
    string str_;
  public:
   FixedString(size_t fixedSize) : str_(' ', fixedSize) {}
   size_t size() const { 
      return str_.size(); 
   } 
    
    char const & operator[](size_t idx) const { 
        return str_[idx]; 
    }
    char & operator[](size_t idx) { 
        return str_[idx]; 
    }
    FixedString& operator+=(const char* s) {
      if (s == NULL) return *this;
      str_ += s;

      return *this;
      // (str_ + s);
      // size_ += strlen(s);
      // char* prevData = data_;
      // data_ = new char[size_ + 1];
      // strcpy(data_, prevData);
      // strcat(data_, s);
      // delete [] prevData;
      // return *this;
    }
};

// class FixedString : public std::string { 
//   public:
//     FixedString(size_t fixedSize) : std::string(fixedSize, ' ')
//  {} 
//  };


class FixedString2 : public std::string { 
  public:
    FixedString2(size_t fixedSize) : std::string(' ', fixedSize) {}
    size_t size() const { 
      return string::size(); 
    } 
    char const & operator[](size_t idx) const { 
      return string::operator[](idx); 
    } 
    char& operator[](size_t idx) { 
      return string::operator[](idx); 
    } 
    // FixedString2& operator+=(const char* s) {
    //   if (s == NULL) return *this;
    //   return string::operator+=(s);

    //   // return *this;
    // }

};

int main(int argc, char* argv[])
{
    FixedString s1(10);
    s1[0] = 'a';
    s1 += "abc";
    cout << s1[0] << s1.size() << endl;

    FixedString2 s2(10);
    s2[0] = 'b';
    s2 += "abc";
    cout << s2 << s2.size() << endl;

    return 0;
}