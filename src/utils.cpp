/*

  This file is a part of BoGoEngine project.

  Copyright (C) 2012 Dương "Yang" ヤン Nguyễn <cmpitg@gmail.com>

  BoGoEngine is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  BoGoEngine is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with BoGoEngine.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "utils.hpp"
#include <iostream>

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

    ustringArrayT analyseWord (ustring str) {
        typedef bool (*_TrivialPointerToFunctions_) (ustring);

        ustringArrayT res(3);
        _TrivialPointerToFunctions_ testFuncs[3] =
            { isConsonant, isVowel, isConsonant };

        // First part: Consonant 1
        // Second part: Vowel
        // Third part: Consonant 2

        for (int part = 0; part < 3; part++) {
            res[part] = "";
            // This is safe due to short-circuit logic
            while (str != _("") && testFuncs[part] (_(str[0]))) {
                res[part] += _(str[0]);
                str.replace (0, 1, "");
            }
        }

        return res;
    }

    ustringArrayT analyseWord (string str) {
        return analyseWord (_(str));
    }

    ustringArrayT analyseWord (const gchar *str) {
        return analyseWord (_(str));
    }

    bool isVowel (ustring ch) {
        return PlainVowels.find (toPlainLetter (ch.lowercase ()))
            != ustring::npos;
    }

    bool isVowel (const gchar *ch) {
        return isVowel (_(ch));
    }

    bool isVowel (string ch) {
        return isVowel (_(ch));
    }

    bool isVowel (guint ch) {
        return isVowel (_(ch));
    }

    bool isConsonant (ustring ch) {
        // Only vowel is special, so non-alphabet characters are
        // counted as consonants
        return !isVowel (ch);
    }

    bool isConsonant (const gchar *ch) {
        return isConsonant (_(ch));
    }

    bool isConsonant (string ch) {
        return isConsonant (_(ch));
    }

    bool isConsonant (guint ch) {
        return isConsonant (_(ch));
    }

    ustring removeMarksFromChar (ustring ch) {
        bool isUp = isUpperCase (ch);
        ch = ch.lowercase ();

        _size_t_ posVowel = getVowelPos (ch);
        _size_t_ accent = getAccentFromChar (ch);

        if (posVowel != ustring::npos)
            ch = addAccentToChar (_(PlainVowels[posVowel]), accent);

        if (isUp)
            ch = ch.uppercase ();
        return ch;
    }

    ustring removeMarksFromChar (string ch) {
        return removeMarksFromChar (_(ch));
    }

    ustring removeMarksFromChar (const gchar *ch) {
        return removeMarksFromChar (_(ch));
    }

    ustring removeMarksFromChar (guint ch) {
        return removeMarksFromChar (_(ch));
    }

    Accents getAccentFromChar (ustring ch) {
        _size_t_ accent = VowelsWithAccents.find (ch.lowercase ());

        if (accent != ustring::npos)
            accent %= NUMBER_OF_ACCENTS;
        else
            accent = NO_ACCENT;
        return accent;
    }

    Accents getAccentFromChar (string ch) {
        return getAccentFromChar (_(ch));
    }

    Accents getAccentFromChar (const gchar *ch) {
        return getAccentFromChar (_(ch));
    }

    Accents getAccentFromChar (guint ch) {
        return getAccentFromChar (_(ch));
    }

    ustring toPlainLetter (ustring ch) {
        ch = removeAccentFromChar (removeMarksFromChar (ch));
        return ch;
    }

    ustring toPlainLetter (const gchar *ch) {
        return toPlainLetter (_(ch));
    }

    ustring toPlainLetter (string ch) {
        return toPlainLetter (_(ch));
    }

    ustring toPlainLetter (guint ch) {
        return toPlainLetter (_(ch));
    }

    ustring addAccentToChar (ustring ch, Accents accent) {
        bool isUp = isUpperCase (ch);
        ch = ch.lowercase ();

        _size_t_ pos = Vowels.find (ch);
        if (pos != ustring::npos)
            ch = _(VowelsWithAccents[pos * NUMBER_OF_ACCENTS + accent]);

        if (isUp)
            ch = ch.uppercase ();
        return ch;
    }

    ustring addAccentToChar (const gchar *ch, Accents accent) {
        return addAccentToChar (_(ch), accent);
    }

    ustring addAccentToChar (guint ch, Accents accent) {
        return addAccentToChar (_(ch), accent);
    }

    ustring addAccentToChar (string ch, Accents accent) {
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

    _size_t_ getVowelPos (string ch) {
        return getVowelPos (_(ch));
    }

    _size_t_ getVowelPos (guint ch) {
        return getVowelPos (_(ch));
    }

    ustring removeAccentFromChar (ustring ch) {
        bool isUp = isUpperCase (ch);
        ch = ch.lowercase ();

        _size_t_ posVowel = getVowelPos (ch);
        if (posVowel != ustring::npos)
            ch = _(Vowels[posVowel]);

        if (isUp)
            ch = ch.uppercase ();
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

    bool isWordBreak (ustring ch) {
        // A char is a word-break if and only if tt's a non-letter
        // character and not a Backspace.
        return !isLetter (ch.lowercase ()) && ch != _(BACKSPACE_CODE);
    }

    bool isWordBreak (const gchar *ch) {
        return isWordBreak (_(ch));
    }

    bool isWordBreak (string ch) {
        return isWordBreak (_(ch));
    }

    bool isWordBreak (guint ch) {
        return isWordBreak (_(ch));
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
