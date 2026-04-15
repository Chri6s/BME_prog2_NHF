#ifndef STRING_H
#define STRING_H
/**
 * \file string5.h
 *
 * Ez a fájl tartalmazza a
 *   - String osztály deklarációját
 *   - az inline függvényeket. Ha valamit inline-ként akar megvalósítani,
 *     akkor azt ebbe a fájlba írja! Tipikusan a rövid kódokat szokás
 *     inline-két megvalósítani (pl: c_str).
 *     Más függvényeket ill. definíciókat ne írjon a .h fájlba!
 *
 * A C nyelven megvalósított String adatszerkezetet (string1) a 2. laboron a
 * C++ nyelv nem OO eszközeivel átalakítottuk (string2_cpp).
 *
 * Most továbblépünk és a String adatszerkezetet igazi osztállyá alakítjuk:
 * Az adatokon műveletet végző függvényeket összezárjuk az adatokkal,
 * így ezek a függvények tagfüggvényekké válnak és
 *   formálisan eltűnik az első paraméterük (s0) (ezt this-ként azért megkapják).
 * A nevük is megváltozik, mert most már az összetartozást, és a
 *   paraméterek típusára való utalást már nem a név hordozza, hanem az osztály.
 * A createString... alakú függvényekből konstruktorok keletkeznek.
 * A disposeString destruktorrá alakul át.
 * Egyes műveletvégző függvényekből pedig operátor függvény lesz.
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
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

    String() :pData(0), len(0) {}
    String(char c);
    String(const char* chars);
    String(const String& other);
    ~String();
    String& operator=(const String& rhs);

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { 
        return pData ? pData : "";
    }

    String operator+(const String& rhs) const;
    String operator+(char rhs) const;
    char& operator[](const size_t idx) const;
};

String operator+(char lhs, const String& rhs);
std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);





#endif
