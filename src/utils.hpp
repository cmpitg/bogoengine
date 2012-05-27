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

#include <glibmm/ustring.h>
#include <string>
#include <vector>
#include <map>
#include <cstdarg>

namespace BoGo {

    using namespace Glib;
    using namespace std;

    typedef ustring::size_type _size_t_;
    typedef vector<ustring> ustringArrayT;
    typedef guint Accents;
    typedef guint Marks;
    typedef guint Transform;
    typedef ustringArrayT InputMethodT;

    const guint NUMBER_OF_IMS = 4;
    const guint IM_SIMPLETELEX = 0,
        IM_TELEX = 1,
        IM_VNI = 2,
        IM_VIQR = 3;
    const ustring IMs[] = {
        "a a^\n"
        "o o^\n"
        "e e^\n"
        "w o+\n"
        "w u+\n"
        "w v\n"
        "d -\n"
        "s /\n"
        "r ?\n"
        "x ~\n"
        "j .\n"
        "z _\n"
        "f \\\n"
    };

    const guint ADD_ACCENT = 0,
        ADD_MARK = 1,
        ADD_CHAR = 2;

    const guint NUMBER_OF_ACCENTS = 6;
    const guint GRAVE  = 0,
        ACUTE          = 1,
        HOOK           = 2,
        TILDE          = 3,
        DOT            = 4,
        NO_ACCENT      = 5;
    const Accents ACCENTS[] = {GRAVE, ACUTE, HOOK, TILDE, DOT, NO_ACCENT};
    const ustring AccentTransforms = "*\\" "*/" "*?" "*~" "*." "*_";

    const guint NUMBER_OF_MARKS = 5;
    const guint NO_MARK  = 0,
        HAT              = 1,
        HORN             = 2,
        BREVE            = 3,
        BAR              = 4;

    const Marks MARKS[] = {HAT, HAT, HAT, HORN, HORN, BREVE, BAR};
    const ustring MarkTransforms = "a^" "o^" "e^" "o+" "u+" "*v" "*-";

    const gchar BACKSPACE_CODE = 8;

    const ustring LowerCaseLetters = "aăâbcdđeêfghijklmnoôơpqrstuưvwxy";
    const ustring Numbers = "0123456789";

    const ustring PlainVowels     = "aaaeeiooouuy";
    const ustring Vowels          = "aăâeêioôơuưy";
    const ustring VowelsWithAccents =
        "àáảãạa" "ằắẳẵặă" "ầấẩẫậâ" "èéẻẽẹe" "ềếểễệê" "ìíỉĩịi"
        "òóỏõọo" "ồốổỗộô" "ờớởỡợơ" "ùúủũụu" "ừứửữựư" "ỳýỷỹỵy";

    const ustring ValidFinalConsonants = "ghctmnp";
    const ustring ValidFinalMulticonsonants = "ng ch nh";
    const ustring InvalidFinalConsonants = "bdđfklqrsvx";

    const ustring SpecialSingleVowel = "ăâơê";
    const ustring AllVowels = "a e e i o u y ao oa eo oe ie eu"
        " oo uo ua ye uye ieu yeu";
    // const ustring ValidFinalConsonants2 = "c t n ch nh";

    const ustring LettersWithoutMarks    = "aaaddeeooouu";
    const ustring LettersMayChangeMarks  = "aăâdđeêoôơuư";
    const ustring LettersWithMarks =
        "aaaddeeooouu" "âââdđêêôôôuư" "aăâdđeêơơơưư"
        "ăăădđeêoôơuư" "aăâđđeêoôơuư";

    bool containsP (ustring str, ustring needle, bool ignoreCase = true);
    bool containsP (string str, ustring needle, bool ignoreCase = true);
    bool containsP (const gchar *str, ustring needle, bool ignoreCase = true);
    bool containsP (ustring str, string needle, bool ignoreCase = true);
    bool containsP (string str, string needle, bool ignoreCase = true);
    bool containsP (const gchar *str, string needle, bool ignoreCase = true);
    bool containsP (ustring str, guint needle, bool ignoreCase = true);
    bool containsP (string str, guint needle, bool ignoreCase = true);
    bool containsP (const gchar *str, guint needle, bool ignoreCase = true);
    bool containsP (ustring str, const gchar *needle, bool ignoreCase = true);
    bool containsP (string str, const gchar *needle, bool ignoreCase = true);
    bool containsP (const gchar *str, const gchar *needle,
                    bool ignoreCase = true);
    bool containsP (ustringArrayT a, ustring s);

    int getLastWord (ustring text);

    long find (ustring s, ustringArrayT a);

    ustring removeAllMarksFromWord (ustring word);
    ustring removeAllMarksFromWord (string word);
    ustring removeAllMarksFromWord (const gchar *word);

    ustring removeMarkFromWord (ustring word, _size_t_ pos);
    ustring removeMarkFromWord (string word, _size_t_ pos);
    ustring removeMarkFromWord (const gchar *word, _size_t_ pos);

    ustring removeAccentFromWord (ustring word);
    ustring removeAccentFromWord (string word);
    ustring removeAccentFromWord (const gchar *word);

    InputMethodT makeStandardIM (guint imID);

    InputMethodT makeIM (guint count, ...);

    InputMethodT makeIMFromString (ustring imStr);
    InputMethodT makeIMFromString (const gchar * imStr);
    InputMethodT makeIMFromString (string imStr);

    ustring toString (InputMethodT im);

    InputMethodT addTransform (InputMethodT im, ustring trans);
    InputMethodT addTransform (InputMethodT im, const gchar *trans);
    ustring getTransform (ustring trans);

    ustring addMarkToChar (ustring ch, Marks mark);
    ustring addMarkToChar (string ch, Marks mark);
    ustring addMarkToChar (const gchar *ch, Marks mark);
    ustring addMarkToChar (guint ch, Marks mark);

    ustringArrayT analyseWord (ustring str);
    ustringArrayT analyseWord (string str);
    ustringArrayT analyseWord (const gchar *str);

    bool analyseWordCheckSpecialConsonants (ustringArrayT word,
                                            ustring consonant);
    bool analyseWordCheckSpecialConsonants (ustringArrayT word,
                                            const gchar *consonant);

    ustring lastChar (ustring s);
    ustring lastChar (string s);
    ustring lastChar (const gchar *s);

    ustring firstChar (ustring s);
    ustring firstChar (string s);
    ustring firstChar (const gchar *s);

    bool isVowel (ustring ch);
    bool isVowel (string ch);
    bool isVowel (const gchar *ch);
    bool isVowel (guint ch);

    bool isConsonant (ustring ch);
    bool isConsonant (string ch);
    bool isConsonant (const gchar *ch);
    bool isConsonant (guint ch);

    ustring removeMarkFromChar (ustring ch);
    ustring removeMarkFromChar (const gchar *ch);
    ustring removeMarkFromChar (string ch);
    ustring removeMarkFromChar (guint ch);

    ustring addAccentToChar (ustring ch, Accents accent);
    ustring addAccentToChar (string ch, Accents accent);
    ustring addAccentToChar (const char *ch, Accents accent);
    ustring addAccentToChar (guint ch, Accents accent);

    _size_t_ getVowelPos (ustring ch);
    _size_t_ getVowelPos (string ch);
    _size_t_ getVowelPos (const gchar *ch);
    _size_t_ getVowelPos (guint ch);

    _size_t_ getMarkedCharPos (ustring ch);
    _size_t_ getMarkedCharPos (string ch);
    _size_t_ getMarkedCharPos (const gchar *ch);
    _size_t_ getMarkedCharPos (guint ch);

    Accents getAccentFromChar (ustring ch);
    Accents getAccentFromChar (string ch);
    Accents getAccentFromChar (const gchar *ch);
    Accents getAccentFromChar (guint ch);

    ustring toPlainLetter (ustring ch);
    ustring toPlainLetter (string ch);
    ustring toPlainLetter (const gchar *ch);
    ustring toPlainLetter (guint ch);

    bool isLetter (ustring ch);
    bool isLetter (string ch);
    bool isLetter (const gchar *ch);
    bool isLetter (guint ch);

    bool isUpperCase (ustring ch);
    bool isUpperCase (string ch);
    bool isUpperCase (const gchar *ch);
    bool isUpperCase (guint ch);

    bool isLowerCase (ustring ch);
    bool isLowerCase (string ch);
    bool isLowerCase (const gchar *ch);
    bool isLowerCase (guint ch);

    bool isWordBreak (ustring ch, guint BackspaceChar = BACKSPACE_CODE);
    bool isWordBreak (string ch, guint BackspaceChar = BACKSPACE_CODE);
    bool isWordBreak (const gchar *ch, guint BackspaceChar = BACKSPACE_CODE);
    bool isWordBreak (guint ch, guint BackspaceChar = BACKSPACE_CODE);

    ustring removeAccentFromChar (ustring ch);
    ustring removeAccentFromChar (string ch);
    ustring removeAccentFromChar (const gchar *ch);
    ustring removeAccentFromChar (guint ch);

    ustring removeAccentFromLastWord (ustring str);

    ustring getTransform (ustring trans);
    ustringArrayT findTransform (ustring ch, InputMethodT im);
    ustring (*filterTransform (ustring key_transf)) (ustring str, ustring transf);
    ustring processKey (gchar key, ustring str, InputMethodT im);
    Transform getTypeTranformation (ustring key_transf);

    ustring toRawText (ustring str);
    ustring toEnglishText (ustring str);

    ustring addAccentToWord (ustring str, Accents accent);
    ustring addAccentToText (ustring str, Accents accent);
    ustring addAccentToText (ustring str, ustring key_transf);

    bool canAddMarkToLetterP (ustring ch, Marks mark);
    bool canAddMarkToLetterP (gchar ch, Marks mark);

    ustring addMarkToWord (ustring str, Marks mark);
    ustring addMarkToText (ustring str, ustring key_transf);

    ustring addChar (ustring str, ustring ch);
}
