#include <glibmm/ustring.h>
#include <string>

namespace BoGo {

    using namespace Glib;
    using namespace std;

    typedef ustring::size_type _size_t_;
    typedef guint Accents;

    const gchar BACKSPACE_CODE = 8;

    const guint NUMBER_OF_ACCENTS = 6;
    const guint GRAVE  = 0,
        ACUTE          = 1,
        HOOK           = 2,
        TILDE          = 3,
        DOT            = 4,
        NO_ACCENT      = 5;

    const ustring LowerCaseLetters =
        ustring ("aăâbcdđeêfghijklmnoôơpqrstuưvwxy");
    // const ustring LowerCaseAlphabet = ustring ("aăâbcdđeêfghijklmnoôơpqrstuưvwxy");
    // const ustring UpperCaseAlphabet = ustring ("AĂÂBCDĐEÊFGHIJKLMNOÔƠPQRSTUƯVWXY");
    const ustring Numbers = ustring ("0123456789");

    const ustring PlainVowels  = ustring ("aaaeeiooouuy");
    const ustring Vowels       = ustring ("aăâeêioôơuưy");
    const ustring VowelsWithAccents =
        "àáảãạa" "ằắẳẵặă" "ầấẩẫậâ" "èéẻẽẹe" "ềếểễệê" "ìíỉĩịi"
        "òóỏõọo" "ồốổỗộô" "ờớởỡợơ" "ùúủũụu" "ừứửữựư" "ỳýỷỹỵy";

    // const ustring VowelsWithAccents[] = {
    //     ustring ("àáảãạ"), ustring ("ằắẳẵặ"), ustring ("ầấẩẫậ"),
    //     ustring ("èéẻẽẹ"), ustring ("ềếểễệ"), ustring ("ìíỉĩị"),
    //     ustring ("òóỏõọ"), ustring ("ồốổỗộ"), ustring ("ờớởỡợ"),
    //     ustring ("ùúủũụ"), ustring ("ừứửữự"), ustring ("ỳýỷỹỵ")
    // };

    ustring addAccentToChar (ustring ch, Accents accent);
    ustring addAccentToChar (string ch, Accents accent);
    ustring addAccentToChar (const char *ch, Accents accent);
    ustring addAccentToChar (guint ch, Accents accent);

    _size_t_ getVowelPos (ustring ch);
    _size_t_ getVowelPos (string ch);
    _size_t_ getVowelPos (const gchar *ch);
    _size_t_ getVowelPos (guint ch);

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

    bool isWordBreak (ustring ch, ustring currentWord = "");
    bool isWordBreak (string ch, string currentWord = "");
    bool isWordBreak (const gchar *ch, const gchar *currentWord = "");
    bool isWordBreak (guint ch, const gchar *currentWord = "");

    ustring removeAccentFromChar (ustring ch);
    ustring removeAccentFromChar (string ch);
    ustring removeAccentFromChar (const gchar *ch);
    ustring removeAccentFromChar (guint ch);
}
