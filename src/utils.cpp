/*

  This file is a part of BoGoEngine project.

  Copyright (C) 2012 Dương H. Nguyễn <cmpitg@gmail.com>

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
// FIXME Polish and clean up code

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

    long find (ustring s, ustringArrayT a) {
        for (long i = 0; i < a.size (); i++)
            if (a[i] == s)
                return i;
        return -1;
    }

    bool containsP (ustring parent, ustring child) {
        return parent.find (child) != ustring::npos;
    }

    bool containsP (ustring parent, const gchar *child) {
        return containsP (parent, _(child));
    }

    bool containsP (const gchar *parent, const gchar *child) {
        return containsP (_(parent), _(child));
    }

    bool containsP (const gchar *parent, ustring child) {
        return containsP (_(parent), child);
    }

    bool containsP (ustringArrayT a, ustring s) {
        return find (s, a) != -1;
    }

    ustring removeAllMarksFromWord (ustring word) {
        ustring res = "";
        for (_size_t_ i = 0; i < word.length (); i++)
            res += removeMarkFromChar (word[i]);
        return res;
    }

    ustring removeAllMarksFromWord (string word) {
        return removeAllMarksFromWord (_(word));
    }

    ustring removeAllMarksFromWord (const gchar *word) {
        return removeAllMarksFromWord (_(word));
    }

    ustring removeMarkFromWord (ustring word, _size_t_ pos) {
        ustring ch = _(word[pos]);
        return word.replace (pos, 1, removeMarkFromChar (ch));
    }

    ustring removeMarkFromWord (string word, _size_t_ pos) {
        return removeMarkFromWord (_(word), pos);
    }

    ustring removeMarkFromWord (const gchar *word, _size_t_ pos) {
        return removeMarkFromWord (_(word), pos);
    }

    ustring removeAccentFromWord (ustring word) {
        ustring res;
        for (_size_t_ i = 0; i < word.length (); i++)
            res += removeAccentFromChar (word[i]);
        return res;
    }

    ustring removeAccentFromWord (string word) {
        return removeAccentFromWord (_(word));
    }

    ustring removeAccentFromWord (const gchar *word) {
        return removeAccentFromWord (_(word));
    }

    InputMethodT makeStandardIM (guint imID) {
        if (imID < NUMBER_OF_IMS)
            return makeIMFromString (IMs[imID]);
        return InputMethodT();
    }

    InputMethodT standardizeIM (InputMethodT im) {
        // Add * when necessary
        for (guint i = 0; i < im.size (); i++)
            if (im[i].length () < 3)
                im[i] = _(im[i][0]) + _("*") + _(im[i][1]);
        return im;
    }

    InputMethodT makeIMFromString (ustring imStr) {
        InputMethodT im;
        _size_t_ eolPos;
        ustring transPortion;
        ustring specialToken = (imStr.find (" -> ") != ustring::npos) ?
            _(" -> ") : _(" ");

        while (imStr.length () > 1) {
            eolPos = imStr.find ("\n");
            transPortion = imStr.substr (0, eolPos);
            imStr = imStr.replace (0, eolPos + 1, "");
            im = addTransformation
                (im, transPortion.replace (1, specialToken.length (), ""));
        }
        return standardizeIM (im);
    }

    InputMethodT makeIMFromString (const gchar * imStr) {
        return makeIMFromString (_(imStr));
    }

    InputMethodT makeIMFromString (string imStr) {
        return makeIMFromString (_(imStr));
    }

    InputMethodT makeIM (guint count, ...) {
        const gchar *trans;
        InputMethodT im;
        va_list transList;
        va_start (transList, count);

        for (guint i = 0; i < count; i++) {
            trans = va_arg (transList, const gchar *);
            im = addTransformation (im, _(trans));
        }

        va_end (transList);
        return im;
    }

    InputMethodT addTransformation (InputMethodT im, ustring trans) {
        im.push_back (trans);
        return im;
    }

    InputMethodT addTransformation (InputMethodT im, const gchar *trans) {
        return addTransformation (im, _(trans));
    }

    ustring toString (InputMethodT im) {
        ustring res;
        for (guint i = 0; i < im.size (); i++)
            res += _(im[i][0]) + " -> " + _(im[i][1]) + _(im[i][2]) + "\n";
        return res;
    }

    ustring addMarkToChar (ustring ch, Marks mark) {
        bool isUp = isUpperCase (ch);
        _size_t_ accent = getAccentFromChar (ch);

        _size_t_ pos = LettersMayChangeMarks.find
            (removeAccentFromChar (ch).lowercase ());
        if (pos != ustring::npos) {
            ch = addAccentToChar
                (_(LettersWithMarks
                   [mark * LettersWithoutMarks.length () + pos]),
                 accent);
            if (isUp)
                ch = ch.uppercase ();
        }
        return ch;
    }

    ustring addMarkToChar (string ch, Marks mark) {
        return addMarkToChar (_(ch), mark);
    }

    ustring addMarkToChar (const gchar *ch, Marks mark) {
        return addMarkToChar (_(ch), mark);
    }

    ustring addMarkToChar (guint ch, Marks mark) {
        return addMarkToChar (_(ch), mark);
    }

    ustring lastChar (ustring s) {
        return (s.length () > 0) ? _(s[s.length () - 1]) : _("");
    }

    ustring lastChar (string s) {
        return lastChar (_(s));
    }

    ustring lastChar (const gchar *s) {
        return lastChar (_(s));
    }

    ustring firstChar (ustring s) {
        return (s.length () > 0) ? _(s[0]) : _("");
    }

    ustring firstChar (string s) {
        return firstChar (_(s));
    }

    ustring firstChar (const gchar *s) {
        return firstChar (_(s));
    }

    bool analyseWordCheckSpecialConsonants (ustringArrayT word,
                                            ustring consonant) {
        return lastChar (word[0]).lowercase () == _(consonant[0]) &&
            firstChar (word[1]).lowercase () == _(consonant[1]);
    }

    bool analyseWordCheckSpecialConsonants (ustringArrayT word,
                                            const gchar *consonant) {
        return analyseWordCheckSpecialConsonants (word, _(consonant));
    }

    ustringArrayT analyseWord (ustring str) {
        typedef bool (*_TrivialPointerToFunctions_) (ustring);

        ustringArrayT res(3);
        _TrivialPointerToFunctions_ testFuncs[3] =
            { isConsonant, isVowel, isConsonant };

        // First part: Consonant 1
        // Second part: Vowel
        // Third part: Consonant 2

        for (int part = 2; part >= 0; part --) {
            res[part] = "";
            while (str.length () > 0 &&
                   testFuncs[part] (_(str[str.length () - 1]))){
                res[part] = _(str[str.length () -1]) + res[part];
                str.replace (str.length () -1, 1, "");
            }
        }

        // push the remaining part into res[0]
        res[0] = str + res[0];

        // Special case: "qu" and "gi" are considered consonants
        if (analyseWordCheckSpecialConsonants (res, "qu") ||
            analyseWordCheckSpecialConsonants (res, "gi")) {
            res[0] += _(res[1][0]);
            res[1] = res[1].replace (0, 1, "");
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

    _size_t_ getMarkedCharPos (ustring ch) {
        _size_t_ mark =
            LettersWithMarks.find (removeAccentFromChar (ch.lowercase ()));

        if (mark != ustring::npos)
            mark %= LettersWithoutMarks.length ();

        return mark;
    }

    _size_t_ getMarkedCharPos (string ch) {
        return getMarkedCharPos (_(ch));
    }

    _size_t_ getMarkedCharPos (const gchar *ch) {
        return getMarkedCharPos (_(ch));
    }

    _size_t_ getMarkedCharPos (guint ch) {
        return getMarkedCharPos (_(ch));
    }

    ustring removeMarkFromChar (ustring ch) {
        bool isUp = isUpperCase (ch);

        _size_t_ pos = getMarkedCharPos (ch);
        _size_t_ accent = getAccentFromChar (ch);

        if (pos != ustring::npos)
            ch = addAccentToChar (_(LettersWithoutMarks[pos]), accent);

        if (isUp)
            ch = ch.uppercase ();
        return ch;
    }

    ustring removeMarkFromChar (string ch) {
        return removeMarkFromChar (_(ch));
    }

    ustring removeMarkFromChar (const gchar *ch) {
        return removeMarkFromChar (_(ch));
    }

    ustring removeMarkFromChar (guint ch) {
        return removeMarkFromChar (_(ch));
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
        ch = removeAccentFromChar (removeMarkFromChar (ch));
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

    bool isWordBreak (ustring ch, guint BackspaceChar) {
        // A char is a word-break if and only if tt's a non-letter
        // character and not a Backspace.
        return !isLetter (ch.lowercase ()) && ch != _(BackspaceChar);
    }

    bool isWordBreak (const gchar *ch, guint BackspaceChar) {
        return isWordBreak (_(ch), BackspaceChar);
    }

    bool isWordBreak (string ch, guint BackspaceChar) {
        return isWordBreak (_(ch), BackspaceChar);
    }

    bool isWordBreak (guint ch, guint BackspaceChar) {
        return isWordBreak (_(ch), BackspaceChar);
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

    ustring toRawText (ustring str) {
        return removeAllMarksFromWord (removeAccentFromWord (str)).lowercase();
    }

    ustring toEnglishText (ustring str) {
        return removeAllMarksFromWord (removeAccentFromWord (str));
    }

    ustring removeAccentFromLastWord (ustring str) {
        ustringArrayT comp = analyseWord (str);
        if (comp[2].size () > 2)
            return str;
        comp[1] = removeAccentFromWord (comp[1]);
        return comp[0] + comp[1] + comp[2];
    }

    ustring addAccentToWord (ustring str, Accents accent) {
        //  ustring rawStr = removeAccentFromWord (str);
        //  if (accent == NO_ACCENT) return str;

        ustringArrayT comp = analyseWord (str);
        comp[1] = removeAccentFromWord (comp[1]);
        if (accent == NO_ACCENT)
            return comp[0] + comp[1] + comp[2];
        if (comp[2].size () > 2) {
            return str;
        }

        ustring vowel = comp[1];
        if (vowel == "") return str;


        ustring ch;
        ustring rawVowel = toRawText (vowel);
        _size_t_ vowelSize = vowel.size ();
        _size_t_ pos;

        for ( _size_t_ i = 0; i < 4; i++) {
            pos = rawVowel.find (SpecialSingleVowel[i]);
            if (pos != ustring::npos) break;
        }

        if (pos == ustring::npos) {
            if (comp[2] == "")
                pos = ( vowelSize <= 2) ? 0 : vowelSize - 2;
            else pos = vowel.size () -1;
        }

        vowel = vowel.replace (pos, 1, addAccentToChar (vowel[pos], accent));
        return comp[0] + vowel + comp[2];
    }


    ustring addAccentToText (ustring str, Accents accent) {
        return addAccentToWord (str, accent);
    }

    ustring addAccentToText (ustring str, ustring transf) {
        _size_t_ pos = AccentTransformations.find (transf);
        if (pos != ustring::npos)
            return addAccentToText (str, ACCENTS[pos/2]);
        return str;
    }

    ustring addMarkToWord (ustring str, Marks mark) {
        if (mark == NO_MARK)
            return removeAllMarksFromWord (str);
        guint lpos = str.size () -1;
        ustring lastChar = _(str[lpos]);
        ustring firstPart = ustring (str, 0, lpos);

        if (lpos == 0) {
            if (canAddMarkToLetter (lastChar, mark)) {
                return addMarkToChar (lastChar, mark);
            }
            return lastChar;
        }
        // Special case : uo ươ
        if ((lpos > 0) && (mark == HORN) &&
            (toRawText(lastChar) == "o" ) &&
            (toRawText (_(str[lpos -1])) == "u")) {
            return
                ((lpos >= 2) ? ustring (str, 0, lpos - 1) : "")
                + addMarkToChar (str[lpos-1], HORN)
                + addMarkToChar (str[lpos], HORN);
        }

        // Special case: ua + w -> ưa not uă
        if ((lpos > 0) && (mark == BREVE) &&
            (toRawText(lastChar) == "a" ) &&
            (toRawText (_(str[lpos -1])) == "u")) {
            return
                ((lpos >= 2) ? ustring (str, 0, lpos - 1) : "")
                + addMarkToChar (str[lpos-1], HORN)
                + str[lpos];
        }

        if (canAddMarkToLetter (lastChar, mark))
            return firstPart + addMarkToChar (lastChar, mark);
        else
            return addMarkToWord (firstPart, mark) + lastChar;

        return str;
    }

    ustring addMarkToText (ustring str, ustring transf) {
        _size_t_ pos = MarkTransformations.find (transf);
        gchar affectedChar = transf[0];
        if ((affectedChar != '*') &&
            (!containsP (toRawText (str), _(affectedChar))))
            return str;
        return addMarkToWord (str, MARKS[pos/2]);
    }

    bool canAddMarkToLetter (ustring ch, Marks mark) {
        ustring _ch = toRawText (ch);
        switch (mark) {
        case HAT:
            if (containsP("aeo", _ch))
                return true;
            break;
        case HORN:
            if (containsP("ou", _ch))
                return true;
            break;
        case BREVE:
            if (_ch == "a")
                return true;
            break;
        case BAR:
            if (_ch == "d")
                return true;
            break;
        case NO_MARK:
            return true;
            break;
        }
        return false;
    }

    bool canAddMarkToLetter (gchar ch, Marks mark) {
        return canAddMarkToLetter (_(ch), mark);
    }

    ustring getTransformation (ustring key_transf) {
        /* get the transformation part from the string describing the
           transformation
           ex: "a a+" -> "a+" */
        ustring transf = key_transf.erase (0,1);
        while (transf[0] == ' ' ) {
            transf.erase(0,1);
        }
        return transf;
    }

    ustringArrayT findTransformation (ustring ch, InputMethodT im) {
        ustringArrayT trans;
        for (guint i = 0; i < im.size(); i++) {
            ustring tr = im[i];
            if (ch == _(tr[0])) {
                trans.push_back (tr);
            }
        }
        return trans;
    }

    ustring addCharToWord (ustring str, ustring ch) {
        return str + ch;
    }

    ustring (*filterTransformation (ustring key_transf )) (ustring, ustring) {
        ustring transf = getTransformation (key_transf);
        if (containsP (MarkTransformations, transf))
            return &addMarkToText;

        if (containsP (AccentTransformations, transf))
            return &addAccentToText;
        return &addCharToWord;
    }

    Transform getTypeTranformation (ustring key_transf) {
        //Determine the type of transformation: add mark or add accent
        ustring transf = getTransformation (key_transf);
        if (containsP (MarkTransformations, transf))
            return ADD_MARK;

        if (containsP (AccentTransformations, transf))
            return ADD_ACCENT;

        return ADD_CHAR;
    }

    ustring processKey (gchar key, ustring str, InputMethodT im) {
        // Default input method is telex and default charset is UTF8
        ustring ch = _(key);

        // Process Backspace
        if (ch == _(BACKSPACE_CODE)) {
            str.erase (str.size() - 1, 1);
            return str;
        }

        ustring (*doTransform) (ustring, ustring);
        ustring newStr = str;
        ustringArrayT transforms = findTransformation (toRawText (ch), im);
        Transform kind;
        if (transforms.size () != 0) {
            for (_size_t_ i = 0; i < transforms.size (); i++) {
                doTransform = filterTransformation (transforms[i]);
                kind = getTypeTranformation (transforms[i]);
                newStr = doTransform (newStr,
                                      getTransformation (transforms[i]));
            }
        } else
            newStr = addCharToWord (str, ch);
        if (newStr == str) {
            if (kind == ADD_MARK)
                newStr = addCharToWord (removeAllMarksFromWord (str), ch);
            if (kind == ADD_ACCENT)
                newStr = addCharToWord (removeAccentFromLastWord (str), ch);
        }

        return newStr;
    }

#undef _
#undef __
}
