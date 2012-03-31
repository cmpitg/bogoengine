#include <iostream>
#include <glibmm/ustring.h>
#include "utils.hpp"

using namespace Glib;

namespace BoGo {

    typedef ustring::size_type _size_t;

    ustring addHat (ustring str, _size_t startFrom = 0);
    ustring addHat (const char *str, _size_t startFrom = 0);
    ustring addHat (std::string str, _size_t startFrom = 0);

    ustring addHorn (ustring str, _size_t startFrom = 0);
    ustring addHorn (const char *str, _size_t startFrom = 0);
    ustring addHorn (std::string str, _size_t startFrom = 0);

    ustring addAccentToChar (ustring str, Accents accent);
    ustring addAccentToChar (const char *ch, Accents accent);
    ustring addAccentToChar (std::string str, Accents accent);

    ustring removeHorn (ustring str, int pos = 0);
    ustring removeHat (ustring str, int pos = 0);
    ustring removeAccent (ustring str, int pos = 0);
    ustring toPlainVowel (ustring str, int pos = 0);

    bool isVietnameseAlphanumeric (ustring str);
    bool isVietnameseAlphanumeric (const char *str);
    bool isVietnameseAlphanumeric (std::string str);
}
