/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez
#include <cctype>

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char c) {
  this->pData = new char[2];
  this->pData[0] = c;
  this->pData[1] = '\0';
  this->len = 1;

}

String::String(const char* chars) {
  const char* src = chars ? chars : "";
  this->len = strlen(src);
  this->pData = new char[this->len + 1];
  strcpy(this->pData, src);
}

/// Másoló konstruktor: String-ből készít (createString)
String::String(const String& string) {
  this->len = string.len;
  this->pData = new char[this->len + 1];
  strcpy(this->pData, string.c_str());
}

/// Destruktor (disposeString)
String::~String() {
  delete[] this->pData;
}

/// operator=
String& String::operator=(const String& rhs) {
  if (this == &rhs) {
    return *this;
  }

  char* uj = new char[rhs.len + 1];
  strcpy(uj, rhs.c_str());
  delete[] this->pData;
  this->pData = uj;
  this->len = rhs.len;
  return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!
char& String::operator[](const size_t idx) const {
  if(idx > this->len-1 || idx < 0) throw "Rossz indexelés!";
  return this->pData[idx];    
}


/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)
String String::operator+(const String& rhs) const {
  String result;
  result.len = this->len + rhs.len;
  result.pData = new char[result.len + 1];
  strcpy(result.pData, this->c_str());
  strcat(result.pData, rhs.c_str());
  return result;
}

String String::operator+(char rhs) const {
  String result;
  result.len = this->len + 1;
  result.pData = new char[result.len + 1];
  strcpy(result.pData, this->c_str());
  result.pData[this->len] = rhs;
  result.pData[this->len + 1] = '\0';
  return result;
}

String operator+(char lhs, const String& rhs) {
  String left(lhs);
  return left + rhs;
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s) {
  os << s.c_str();
  return os;
}

/// >> operátor, ami beolvas az istream-ről egy szót
std::istream& operator>>(std::istream& is, String& s) {
  std::istream::sentry sentry(is);
  if (!sentry) {
    return is;
  }

  String tmp;
  int ch;
  while (is && (ch = is.peek()) != EOF && !std::isspace(static_cast<unsigned char>(ch))) {
    tmp = tmp + static_cast<char>(is.get());
  }

  if (tmp.size() == 0) {
    is.setstate(std::ios::failbit);
    return is;
  }

  s = tmp;
  return is;
}
