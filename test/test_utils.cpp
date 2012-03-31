#include <gtest/gtest.h>
#include <iostream>
#include <engine.hpp>

using namespace std;
using namespace Glib;
using namespace BoGo;

#define _(s) (ustring ("") + s)
#define __(s) (ustring ("") + s).c_str ()

TEST (CharacterHelpers, CharacterCases) {
    EXPECT_EQ (true, isUpperCase ("Â"));
    EXPECT_EQ (true, isUpperCase ("À"));
    EXPECT_EQ (true, isUpperCase ("Ă"));
    EXPECT_EQ (true, isUpperCase ("Â"));
    EXPECT_EQ (true, isUpperCase ("B"));
    EXPECT_EQ (true, isUpperCase ("C"));
    EXPECT_EQ (true, isUpperCase ("D"));
    EXPECT_EQ (true, isUpperCase ("Đ"));
    EXPECT_EQ (true, isUpperCase ("E"));
    EXPECT_EQ (true, isUpperCase ("Ế"));
    EXPECT_EQ (true, isUpperCase ("G"));
    EXPECT_EQ (true, isUpperCase ("H"));
    EXPECT_EQ (true, isUpperCase ("I"));
    EXPECT_EQ (true, isUpperCase ("K"));
    EXPECT_EQ (true, isUpperCase ("L"));
    EXPECT_EQ (true, isUpperCase ("M"));
    EXPECT_EQ (true, isUpperCase ("N"));
    EXPECT_EQ (true, isUpperCase ("O"));
    EXPECT_EQ (true, isUpperCase ("Ô"));
    EXPECT_EQ (true, isUpperCase ("Ơ"));
    EXPECT_EQ (true, isUpperCase ("P"));
    EXPECT_EQ (true, isUpperCase ("Q"));
    EXPECT_EQ (true, isUpperCase ("R"));
    EXPECT_EQ (true, isUpperCase ("S"));
    EXPECT_EQ (true, isUpperCase ("T"));
    EXPECT_EQ (true, isUpperCase ("U"));
    EXPECT_EQ (true, isUpperCase ("Ư"));
    EXPECT_EQ (true, isUpperCase ("V"));
    EXPECT_EQ (true, isUpperCase ("X"));
    EXPECT_EQ (true, isUpperCase ("Y"));

    EXPECT_EQ (false, isUpperCase ("a"));
    EXPECT_EQ (false, isUpperCase ("ă"));
    EXPECT_EQ (false, isUpperCase ("ậ"));
    EXPECT_EQ (false, isUpperCase ("b"));
    EXPECT_EQ (false, isUpperCase ("c"));
    EXPECT_EQ (false, isUpperCase ("d"));
    EXPECT_EQ (false, isUpperCase ("đ"));
    EXPECT_EQ (false, isUpperCase ("ẻ"));
    EXPECT_EQ (false, isUpperCase ("ê"));
    EXPECT_EQ (false, isUpperCase ("g"));
    EXPECT_EQ (false, isUpperCase ("h"));
    EXPECT_EQ (false, isUpperCase ("i"));
    EXPECT_EQ (false, isUpperCase ("k"));
    EXPECT_EQ (false, isUpperCase ("l"));
    EXPECT_EQ (false, isUpperCase ("m"));
    EXPECT_EQ (false, isUpperCase ("n"));
    EXPECT_EQ (false, isUpperCase ("o"));
    EXPECT_EQ (false, isUpperCase ("ỗ"));
    EXPECT_EQ (false, isUpperCase ("ơ"));
    EXPECT_EQ (false, isUpperCase ("p"));
    EXPECT_EQ (false, isUpperCase ("q"));
    EXPECT_EQ (false, isUpperCase ("r"));
    EXPECT_EQ (false, isUpperCase ("s"));
    EXPECT_EQ (false, isUpperCase ("t"));
    EXPECT_EQ (false, isUpperCase ("u"));
    EXPECT_EQ (false, isUpperCase ("ư"));
    EXPECT_EQ (false, isUpperCase ("v"));
    EXPECT_EQ (false, isUpperCase ("x"));
    EXPECT_EQ (false, isUpperCase ("y"));
}

// TEST (WordHelpers, Other) {
//     EXPECT_EQ (false, isWordBreak ((gchar) 8));
//     EXPECT_EQ (true, isWordBreak ("1"));
//     EXPECT_EQ (true, isWordBreak ((gchar) 13));
//     EXPECT_EQ (false, isWordBreak ("â"));
//     EXPECT_EQ (true, isWordBreak ("â", "ngoan"));
// }

// ờớởỡợỳýỷỹỵòóỏõọồốổỗộầấẩẫậằắẳẵặàáảãạàáảãạ

TEST (CharacterHelpers, AccentsAndTransform) {
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ố").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ổ").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ỗ").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ộ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ầ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ấ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ẩ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ẫ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ậ").c_str ());

    EXPECT_STREQ (__("a"), toPlainLetter ("â").c_str ());
    EXPECT_STREQ (__("a"), toPlainLetter ("ắ").c_str ());
    EXPECT_STREQ (__("n"), toPlainLetter ("n").c_str ());
    EXPECT_STREQ (__("o"), toPlainLetter ("ộ").c_str ());
    EXPECT_STREQ (__("e"), toPlainLetter ("ễ").c_str ());

    EXPECT_EQ (0, getAccentFromChar ("ồ"));
    EXPECT_EQ (1, getAccentFromChar ("Ứ"));
    EXPECT_EQ (2, getAccentFromChar ("Ể"));
    EXPECT_EQ (3, getAccentFromChar ("ẵ"));
    EXPECT_EQ (4, getAccentFromChar ("ị"));
    EXPECT_EQ (4294967295, getAccentFromChar ("n"));
}

TEST (CharacterHelpers, PlainCharacters) {
    EXPECT_EQ (true, isLetter ("n"));
    EXPECT_EQ (true, isLetter ("ọ"));
    EXPECT_EQ (true, isLetter ("ổ"));
    EXPECT_EQ (true, isLetter ("ầ"));
    EXPECT_EQ (true, isLetter ("ẩ"));
    EXPECT_EQ (true, isLetter ("á"));
    EXPECT_EQ (true, isLetter ("ả"));
    EXPECT_EQ (true, isLetter ("t"));
    EXPECT_EQ (true, isLetter ("b"));
    EXPECT_EQ (true, isLetter ("a"));
    EXPECT_EQ (true, isLetter ("g"));
    EXPECT_EQ (true, isLetter ("o"));
    EXPECT_EQ (true, isLetter ("t"));
    EXPECT_EQ (true, isLetter ("s"));
    EXPECT_EQ (true, isLetter ("e"));
    EXPECT_EQ (false, isLetter ("7"));
    EXPECT_EQ (false, isLetter ("5"));
    EXPECT_EQ (false, isLetter ("2"));
    EXPECT_EQ (false, isLetter ("1"));
    EXPECT_EQ (false, isLetter ("6"));
    EXPECT_EQ (true, isLetter ("S"));
    EXPECT_EQ (true, isLetter ("A"));
    EXPECT_EQ (true, isLetter ("T"));
    EXPECT_EQ (true, isLetter ("O"));
    EXPECT_EQ (false, isLetter ("\\"));
    EXPECT_EQ (false, isLetter ((gchar) 13)); // Return
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest (&argc, argv);
    int dummyVal = RUN_ALL_TESTS ();

    return 0;
}
