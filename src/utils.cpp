#include "utils.hpp"
#include <iostream>

// FIXME uppercase, lowercase
// FIXME charset

namespace BoGo {

    using namespace std;
    using namespace Glib;

#ifdef _
#undef _
#endif
#define _(x) (ustring ("") + x)

#ifdef __
#undef __
#endif
#define __(x) (ustring ("") + x).c_str ()

    ustring removeMarksFromChar (ustring ch) {
        _size_t_ posVowel = getVowelPos (ch);
        _size_t_ accent = getAccentFromChar (ch);

        if (posVowel != ustring::npos) {
            ch = _(PlainVowels[posVowel]);
            if (accent != ustring::npos)
                ch = addAccentToChar (ch, accent);
        }
        return ch;
    }

    Accents getAccentFromChar (ustring ch) {
        _size_t_ accent = VowelsWithAccents.find (ch.lowercase ());

        if (accent != ustring::npos)
            accent %= NUMBER_OF_ACCENTS;        // Number of accents
        return accent;
    }

    Accents getAccentFromChar (const gchar *ch) {
        return getAccentFromChar (_(ch));
    }

    ustring toPlainLetter (ustring ch) {
        bool isUp = isUpperCase (ch);
        ch = removeAccentFromChar (removeMarksFromChar (ch));
        if (isUp)
            ch = ch.uppercase ();
        return ch;
    }

    ustring toPlainLetter (const gchar *ch) {
        return toPlainLetter (_(ch));
    }

    ustring addAccentToChar (ustring ch, Accents accent) {
        _size_t_ pos = Vowels.find (ch);
        if (pos != ustring::npos)
            ch = _(VowelsWithAccents[pos * NUMBER_OF_ACCENTS + accent]);
        return ch;
    }

    ustring addAccentToChar (const gchar *ch, Accents accent) {
        return addAccentToChar (_(ch), accent);
    }

    ustring addAccentToChar (guint ch, Accents accent) {
        return addAccentToChar (_(ch), accent);
    }

    _size_t_ getVowelPos (ustring ch) {
        _size_t_ pos = VowelsWithAccents.find (ch.lowercase ());
        if (pos != ustring::npos)
            pos /= NUMBER_OF_ACCENTS;
        else if (Vowels.find (ch.lowercase ()) != pos)
            pos = Vowels.find (ch.lowercase ());
        return pos;
    }

    _size_t_ getVowelPos (const gchar *ch) {
        return getVowelPos (_(ch));
    }

    ustring removeAccentFromChar (ustring ch) {
        _size_t_ posVowel = getVowelPos (ch);
        if (posVowel != ustring::npos)
            ch = _(Vowels[posVowel]);
        return ch;
    }

    ustring removeAccentFromChar (const gchar *ch) {
        return removeAccentFromChar (_(ch));
    }

    ustring removeAccentFromChar (string ch) {
        return removeAccentFromChar (_(ch));
    }

    ustring removeAccentFromChar (guint ch) {
        return removeAccentFromChar (_(ch));
    }

    bool isLetter (ustring ch) {
        return
            LowerCaseLetters.find (toPlainLetter (ch).lowercase ())
            != ustring::npos;
    }

    bool isLetter (string ch) {
        return isLetter (_(ch));
    }

    bool isLetter (const gchar *ch) {
        return isLetter (_(ch));
    }

    bool isLetter (guint ch) {
        return isLetter (_(ch));
    }

    bool isWordBreak (ustring ch, ustring currentWord) {
        // A char is a word-break if and only if tt's a non-letter
        // character and not a Backspace.
        return !isLetter (ch.lowercase ()) && ch != _(BACKSPACE_CODE);
    }

    bool isWordBreak (const gchar *ch, const gchar *currentWord) {
        return isWordBreak (_(ch), _(currentWord));
    }

    bool isWordBreak (string ch, string currentWord) {
        return isWordBreak (_(ch), _(currentWord));
    }

    bool isWordBreak (guint ch, const gchar *currentWord) {
        return isWordBreak (_(ch), _(currentWord));
    }

    bool isUpperCase (ustring ch) {
        return ch.uppercase () == ch;
    }

    bool isUpperCase (string ch) {
        return isUpperCase (_(ch));
    }

    bool isUpperCase (const gchar *ch) {
        return isUpperCase (_(ch));
    }

    bool isUpperCase (guint ch) {
        return isUpperCase (_(ch));
    }

    bool isLowerCase (ustring ch) {
        return !isUpperCase (ch);
    }

    bool isLowerCase (string ch) {
        return isLowerCase (_(ch));
    }

    bool isLowerCase (const gchar *ch) {
        return isLowerCase (_(ch));
    }

    bool isLowerCase (guint ch) {
        return isLowerCase (_(ch));
    }

#undef _
#undef __

}
