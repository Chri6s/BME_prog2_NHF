#ifndef STRING_H
#define STRING_H
/**
 * \file string5.h
 *
 *
 */

#include <iostream>

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 *
 * Korábban a len adattag unsigned int típusú volt. Most helyette a size_t típust használjuk.
 * Ezzel a típussal tér vissza a sizeof operator is, később több helyen ezt használjuk
 * mérettípusként.

 */
class String {
    char *pData;
    size_t len;
public:

    String() :pData(0), len(0) {}
    String(char c);
    String(const char* chars);
    String(const String& other);
    ~String();
    
    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }
    
    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { 
        return pData ? pData : "";
    }
    
    String& operator=(const String& rhs);
    String operator+(const String& rhs) const;
    String operator+(char rhs) const;
    char& operator[](const size_t idx) const;
};

String operator+(char lhs, const String& rhs);
std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);





#endif
