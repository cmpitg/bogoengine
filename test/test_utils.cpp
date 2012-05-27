/*

 This file is a part of BoGoEngine project.

 Copyright (C) 2012 Dương H. Nguyễn <cmpitg@gmail.com>

 BoGoEngine is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 BoGoEngine is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with BoGoEngine. If not, see <http://www.gnu.org/licenses/>.

*/

#include <gtest/gtest.h>
#include <iostream>
#include <engine.hpp>

using namespace std;
using namespace Glib;
using namespace BoGo;

#define _(s) (ustring ("") + s)
#define __(s) (ustring ("") + s).c_str ()

vector<ustring> makeustringVec3 (const gchar *e0,
                                 const gchar *e1,
                                 const gchar *e2) {
    vector<ustring> v(3);
    v[0] = _(e0);
    v[1] = _(e1);
    v[2] = _(e2);
    return v;
}

TEST (MarkAndWord, CanAddMarkToLetterP) {
    EXPECT_TRUE (canAddMarkToLetterP ("a", HAT));
    EXPECT_TRUE (canAddMarkToLetterP ("o", HAT));
    EXPECT_TRUE (canAddMarkToLetterP ("A", HAT));
    EXPECT_FALSE (canAddMarkToLetterP ("V", HAT));
    EXPECT_TRUE (canAddMarkToLetterP ("O", HORN));
    EXPECT_TRUE (canAddMarkToLetterP ("u", HORN));
    EXPECT_FALSE (canAddMarkToLetterP ("e", HORN));
}

// TEST (WholeWordManipulation, GetLastWord) {
//     EXPECT_EQ (0, getLastWord("giang")); //-> "giang"
//     EXPECT_EQ (3, getLastWord("conđường")); //-> "đường"
//     EXPECT_EQ (5, getLastWord("thằnghề")); //-> "hề"
//     EXPECT_EQ (4, getLastWord("nhànhạ")); //-> "hạ"
//     EXPECT_EQ (4, getLastWord("cáinhà")); //-> "hà"
//     //the "hà" result above isn't really correct in theory, but it's totally acceptable
//     EXPECT_EQ (0, getLastWord("nàNG")); //-> "nàNG"
//     EXPECT_EQ (4, getLastWord("liêux")); //-> "x"
//     EXPECT_EQ (3, getLastWord("caon")); //-> "n"
// }

TEST (FindTransform, SimpleTelex) {
    InputMethodT im = makeStandardIM (IM_SIMPLETELEX);
    ustringArrayT availTrans = findTransform ("w", im);

    EXPECT_EQ (3, availTrans.size ());
    EXPECT_TRUE (containsP (availTrans, _("wo+")));
    EXPECT_TRUE (containsP (availTrans, _("wu+")));
    EXPECT_TRUE (containsP (availTrans, _("w*v")));
    EXPECT_EQ (0, findTransform ("t", im).size ());
}

TEST (WordHelpers, AddAccentToWord) {
    EXPECT_STREQ ("èo", addAccentToWord ("eo", GRAVE).c_str ());
    EXPECT_STREQ ("iều", addAccentToWord ("iêu", GRAVE).c_str ());
    EXPECT_STREQ ("uối", addAccentToWord ("uôi", ACUTE).c_str ());
    EXPECT_STREQ ("Ẹ", addAccentToWord ("E", DOT).c_str ());
    EXPECT_STREQ ("huYền", addAccentToWord ("huYên", GRAVE).c_str ());
    EXPECT_STREQ ("uYê", addAccentToWord ("uYế", NO_ACCENT).c_str ());
    EXPECT_STREQ ("xóa", addAccentToWord ("xoa", ACUTE).c_str ());
    EXPECT_STREQ ("xoÁn", addAccentToWord ("xoAn", ACUTE).c_str ());
    EXPECT_STREQ ("xoẮn", addAccentToWord ("xoĂn", ACUTE).c_str ());
    EXPECT_STREQ ("xoaÁN", addAccentToWord ("xoaAN", ACUTE).c_str ());
}

TEST (WordHelpers, AddMarkToWord) {
    EXPECT_STREQ ("ê", addMarkToWord ("e", HAT).c_str ());
    EXPECT_STREQ ("đ", addMarkToWord ("d", BAR).c_str ());
    EXPECT_STREQ ("uối", addMarkToWord ("uói", HAT).c_str ());
    EXPECT_STREQ ("mưa", addMarkToWord ("mua", HORN).c_str ());
    EXPECT_STREQ ("đeo", addMarkToWord ("deo", BAR).c_str ());
    EXPECT_STREQ ("ươi", addMarkToWord ("uoi", HORN).c_str ());
    EXPECT_STREQ ("nẰm", addMarkToWord ("nÀm", BREVE).c_str ());
    EXPECT_STREQ ("ĐẰm", addMarkToWord ("DẰm", BAR).c_str ());
    EXPECT_STREQ ("rƯơi", addMarkToWord ("rUoi", HORN).c_str ());
    EXPECT_STREQ ("TrƯơng", addMarkToWord ("TrUong", HORN).c_str ());
}

TEST (ProcessKey, ProcessKey) {
    InputMethodT im = makeStandardIM (IM_SIMPLETELEX);
    EXPECT_STREQ(__("mèo"), __(processKey (BACKSPACE_CODE, "mèov", im)));
    EXPECT_STREQ(__("mèo"), __(processKey ('f', "meo", im)));
    EXPECT_STREQ(__("Đèo"), __(processKey ('d', "Dèo", im)));
    EXPECT_STREQ(__("đèo"), __(processKey ('D', "dèo", im)));
    EXPECT_STREQ(__("đEO"), __(processKey ('z', "đÈO", im)));
    EXPECT_STREQ(__("mưA"), __(processKey ('w', "muA", im)));
    EXPECT_STREQ(__("rƯơi"), __(processKey ('w', "rUoi", im)));
    EXPECT_STREQ(__("rUòi"), __(processKey ('f', "rUoi", im)));
    EXPECT_STREQ(__("ruoiw"), __(processKey ('w', "rươi", im)));
    EXPECT_STREQ(__("mỬ"), __(processKey ('w', "mỦ", im)));
    EXPECT_STREQ(__("mỦw"), __(processKey ('w', "mỬ", im)));
    EXPECT_STREQ(__("măn"), __(processKey ('w', "man", im)));
    EXPECT_STREQ(__("mũmmĩm"), __(processKey ('X', "mũmmim", im)));
    EXPECT_STREQ(__("làmănz"), __(processKey ('z', "làmăn", im)));
    EXPECT_STREQ(__("chuyệk"), __(processKey ('j', "chuyêk", im)));
    EXPECT_STREQ(__("quảđur"), __(processKey ('r', "quảđủ", im)));
    EXPECT_STREQ(__("mèokckf"), __(processKey ('f', "mèokck", im)));
    EXPECT_STREQ(__("meO"), __(processKey ('O', "me", im)));
    EXPECT_STREQ (__("làmănz"), __(processKey ('z', "làmăn", im)));
    EXPECT_STREQ (__("chuyệk"), __(processKey ('j', "chuyêk", im))); // FIXME: Need to discuss
    EXPECT_STREQ (__("đèO"), __(processKey ('D',"dèO", im)));
    EXPECT_STREQ (__("geO"), __(processKey ('O', "ge", im)));
    EXPECT_STREQ (__("goa"), __(processKey ('a', "go", im)));
    EXPECT_STREQ (__("gô"), __(processKey ('o', "go", im)));
    // EXPECT_STREQ(__("họa"), __(processKey (BACKSPACE_CODE, "hoạt", im)));
}

TEST (MarkAndWord, RemoveAllMarks) {
    EXPECT_STREQ ("thuỏ", removeAllMarksFromWord ("thuở").c_str ());
    EXPECT_STREQ ("gIỵA", removeAllMarksFromWord ("gIỵA").c_str ());
    EXPECT_STREQ ("uýNh", removeAllMarksFromWord ("uýNh").c_str ());
    EXPECT_STREQ ("LỌn", removeAllMarksFromWord ("LỘn").c_str ());
    EXPECT_STREQ ("xOoNg", removeAllMarksFromWord ("xOoNg").c_str ());
    EXPECT_STREQ ("xOÒng", removeAllMarksFromWord ("xOÒng").c_str ());
    EXPECT_STREQ ("khúC", removeAllMarksFromWord ("khứC").c_str ());
    EXPECT_STREQ ("HuO", removeAllMarksFromWord ("HuƠ").c_str ());
    EXPECT_STREQ ("HuOu", removeAllMarksFromWord ("HưƠu").c_str ());
    EXPECT_STREQ ("HuONg", removeAllMarksFromWord ("HưƠNg").c_str ());
}

TEST (MarkAndWord, RemoveMark) {
    EXPECT_STREQ ("thuỏ", removeMarkFromWord ("thuở", 3).c_str ());
    EXPECT_STREQ ("gIỵA", removeMarkFromWord ("gIỵA", 2).c_str ());
    EXPECT_STREQ ("uýNh", removeMarkFromWord ("uýNh", 1).c_str ());
    EXPECT_STREQ ("LỌn", removeMarkFromWord ("LỘn", 1).c_str ());
    EXPECT_STREQ ("xOoNg", removeMarkFromWord ("xOoNg", 3).c_str ());
    EXPECT_STREQ ("xOÒng", removeMarkFromWord ("xOÒng", 2).c_str ());
    EXPECT_STREQ ("khúC", removeMarkFromWord ("khứC", 2).c_str ());
    EXPECT_STREQ ("HuO", removeMarkFromWord ("HuƠ", 2).c_str ());
}

TEST (AccentAndWord, RemoveAccent) {
    EXPECT_STREQ ("thuơ", removeAccentFromWord ("thuở").c_str ());
    EXPECT_STREQ ("gIyA", removeAccentFromWord ("gIỵA").c_str ());
    EXPECT_STREQ ("uyNh", removeAccentFromWord ("uýNh").c_str ());
    EXPECT_STREQ ("LÔn", removeAccentFromWord ("LỘn").c_str ());
    EXPECT_STREQ ("xOoNg", removeAccentFromWord ("xOoNg").c_str ());
    EXPECT_STREQ ("xOOng", removeAccentFromWord ("xOÒng").c_str ());
    EXPECT_STREQ ("khuC", removeAccentFromWord ("khúC").c_str ());
    EXPECT_STREQ ("kHuYU", removeAccentFromWord ("kHuỶU").c_str ());
    EXPECT_STREQ ("HuƠ", removeAccentFromWord ("HuƠ").c_str ());
}

TEST (InputMethod, MakeIM) {
    InputMethodT im;
    im = addTransform (im, "aa^");
    im = addTransform (im, "f*\\");
    im = addTransform (im, "w*\\");
    im = addTransform (im, "oo+");
    EXPECT_STREQ ("a -> a^\nf -> *\\\nw -> *\\\no -> o+\n", __(toString (im)));

    im = makeIM (5, "aa^", "f*\\", "w*\\", "oo+", "j*.");
    EXPECT_STREQ ("a -> a^\nf -> *\\\nw -> *\\\no -> o+\nj -> *.\n",
                 __(toString (im)));

    im = makeIMFromString ("a -> a^\nf -> *\\\no -> o+\nj -> *.\n");
    EXPECT_STREQ ("a -> a^\nf -> *\\\no -> o+\nj -> *.\n",
                 __(toString (im)));

    im = makeStandardIM (IM_SIMPLETELEX);
    EXPECT_STREQ ("a -> a^\n"
                 "o -> o^\n"
                 "e -> e^\n"
                 "w -> o+\n"
                 "w -> u+\n"
                 "w -> *v\n"
                 "d -> *-\n"
                 "s -> */\n"
                 "r -> *?\n"
                 "x -> *~\n"
                 "j -> *.\n"
                 "z -> *_\n"
                 "f -> *\\"
                 "\n", __(toString (im)));
}

TEST (TestItself, TestHelpers) {
    vector<ustring> s1 = makeustringVec3("aoeu", "xin chào", "Thế Giới!");
    EXPECT_TRUE (s1 == s1);
}

TEST (WordHelpers, WordSeparator) {
    EXPECT_TRUE (makeustringVec3 ("ng", "oa", "n") ==
                 analyseWord ("ngoan"));
    EXPECT_TRUE (makeustringVec3 ("tr", "ườ", "ng") ==
                 analyseWord ("trường"));
    EXPECT_TRUE (makeustringVec3 ("", "Oạ", "cH") ==
                 analyseWord ("OạcH"));
    EXPECT_TRUE (makeustringVec3 ("Th", "ề", "") ==
                 analyseWord ("Thề"));
    EXPECT_TRUE (makeustringVec3 ("", "uI", "") ==
                 analyseWord ("uI"));
    EXPECT_TRUE (makeustringVec3 ("", "oa", "") ==
                 analyseWord ("oa"));
    EXPECT_TRUE (makeustringVec3 ("qU", "a", "N") ==
                 analyseWord ("qUaN"));
    EXPECT_TRUE (makeustringVec3 ("Gi", "Áo", "") ==
                 analyseWord ("GiÁo"));
}

TEST (CharacterHelpers, ConsonantsAndVowels) {
    EXPECT_TRUE (isVowel ("Â"));
    EXPECT_FALSE (isConsonant ("à"));
    EXPECT_TRUE (isVowel ("Ă"));
    EXPECT_TRUE (isConsonant ("C"));
    EXPECT_TRUE (isConsonant (" "));
    EXPECT_FALSE (isVowel ("Đ"));
    EXPECT_TRUE (isVowel ("Ế"));
}

TEST (CharacterHelpers, CharacterCases) {
    EXPECT_TRUE (isUpperCase ("Â"));
    EXPECT_TRUE (isUpperCase ("À"));
    EXPECT_TRUE (isUpperCase ("Ă"));
    EXPECT_TRUE (isUpperCase ("Â"));
    EXPECT_TRUE (isUpperCase ("B"));
    EXPECT_TRUE (isUpperCase ("C"));
    EXPECT_TRUE (isUpperCase ("D"));
    EXPECT_TRUE (isUpperCase ("Đ"));
    EXPECT_TRUE (isUpperCase ("E"));
    EXPECT_TRUE (isUpperCase ("Ế"));
    EXPECT_TRUE (isUpperCase ("G"));
    EXPECT_TRUE (isUpperCase ("H"));
    EXPECT_TRUE (isUpperCase ("I"));
    EXPECT_TRUE (isUpperCase ("K"));
    EXPECT_TRUE (isUpperCase ("L"));
    EXPECT_TRUE (isUpperCase ("M"));
    EXPECT_TRUE (isUpperCase ("N"));
    EXPECT_TRUE (isUpperCase ("O"));
    EXPECT_TRUE (isUpperCase ("Ô"));
    EXPECT_TRUE (isUpperCase ("Ơ"));
    EXPECT_TRUE (isUpperCase ("P"));
    EXPECT_TRUE (isUpperCase ("Q"));
    EXPECT_TRUE (isUpperCase ("R"));
    EXPECT_TRUE (isUpperCase ("S"));
    EXPECT_TRUE (isUpperCase ("T"));
    EXPECT_TRUE (isUpperCase ("U"));
    EXPECT_TRUE (isUpperCase ("Ư"));
    EXPECT_TRUE (isUpperCase ("V"));
    EXPECT_TRUE (isUpperCase ("X"));
    EXPECT_TRUE (isUpperCase ("Y"));

    EXPECT_FALSE (isUpperCase ("a"));
    EXPECT_FALSE (isUpperCase ("ă"));
    EXPECT_FALSE (isUpperCase ("ậ"));
    EXPECT_FALSE (isUpperCase ("b"));
    EXPECT_FALSE (isUpperCase ("c"));
    EXPECT_FALSE (isUpperCase ("d"));
    EXPECT_FALSE (isUpperCase ("đ"));
    EXPECT_FALSE (isUpperCase ("ẻ"));
    EXPECT_FALSE (isUpperCase ("ê"));
    EXPECT_FALSE (isUpperCase ("g"));
    EXPECT_FALSE (isUpperCase ("h"));
    EXPECT_FALSE (isUpperCase ("i"));
    EXPECT_FALSE (isUpperCase ("k"));
    EXPECT_FALSE (isUpperCase ("l"));
    EXPECT_FALSE (isUpperCase ("m"));
    EXPECT_FALSE (isUpperCase ("n"));
    EXPECT_FALSE (isUpperCase ("o"));
    EXPECT_FALSE (isUpperCase ("ỗ"));
    EXPECT_FALSE (isUpperCase ("ơ"));
    EXPECT_FALSE (isUpperCase ("p"));
    EXPECT_FALSE (isUpperCase ("q"));
    EXPECT_FALSE (isUpperCase ("r"));
    EXPECT_FALSE (isUpperCase ("s"));
    EXPECT_FALSE (isUpperCase ("t"));
    EXPECT_FALSE (isUpperCase ("u"));
    EXPECT_FALSE (isUpperCase ("ư"));
    EXPECT_FALSE (isUpperCase ("v"));
    EXPECT_FALSE (isUpperCase ("x"));
    EXPECT_FALSE (isUpperCase ("y"));
}

TEST (WordHelpers, WordBreak) {
    EXPECT_FALSE (isWordBreak ((gchar) 8));
    EXPECT_TRUE (isWordBreak ("1"));
    EXPECT_TRUE (isWordBreak ((gchar) 13));
    EXPECT_FALSE (isWordBreak ("â"));
    EXPECT_FALSE (isWordBreak ("â"));
}

TEST (OtherHelpers, StringContains) {
    EXPECT_TRUE (containsP ("điên", (guint) 273));
    EXPECT_TRUE (containsP ("Xin chào!", "À"));
    EXPECT_FALSE (containsP ("Xin chào!", "À", false));
    EXPECT_TRUE (containsP ("Xin chào!", "!"));
    EXPECT_TRUE (containsP ("Xin chào!", " "));
    EXPECT_TRUE (containsP ("Xin chào!", "X"));
    EXPECT_FALSE (containsP ("Xin chào!", "x", false));
}

TEST (CharacterHelpers, AccentsAndTransform) {
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ố").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ổ").c_str ());
    EXPECT_STREQ (__("Ô"), removeAccentFromChar ("Ỗ").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ộ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ầ").c_str ());
    EXPECT_STREQ (__("Â"), removeAccentFromChar ("Ấ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ẩ").c_str ());
    EXPECT_STREQ (__("Â"), removeAccentFromChar ("Ẫ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ậ").c_str ());

    EXPECT_STREQ (__("ó"), removeMarkFromChar ("ố").c_str ());
    EXPECT_STREQ (__("ỏ"), removeMarkFromChar ("ổ").c_str ());
    EXPECT_STREQ (__("Õ"), removeMarkFromChar ("Ỗ").c_str ());
    EXPECT_STREQ (__("ọ"), removeMarkFromChar ("ộ").c_str ());
    EXPECT_STREQ (__("à"), removeMarkFromChar ("ầ").c_str ());
    EXPECT_STREQ (__("Á"), removeMarkFromChar ("Ấ").c_str ());
    EXPECT_STREQ (__("ả"), removeMarkFromChar ("ẩ").c_str ());
    EXPECT_STREQ (__("Ã"), removeMarkFromChar ("Ẫ").c_str ());
    EXPECT_STREQ (__("ạ"), removeMarkFromChar ("ậ").c_str ());

    EXPECT_STREQ (__("a"), toPlainLetter ("â").c_str ());
    EXPECT_STREQ (__("a"), toPlainLetter ("ắ").c_str ());
    EXPECT_STREQ (__("N"), toPlainLetter ("N").c_str ());
    EXPECT_STREQ (__("O"), toPlainLetter ("Ộ").c_str ());
    EXPECT_STREQ (__("E"), toPlainLetter ("Ễ").c_str ());

    EXPECT_EQ (0, getAccentFromChar ("ồ"));
    EXPECT_EQ (1, getAccentFromChar ("Ứ"));
    EXPECT_EQ (2, getAccentFromChar ("Ể"));
    EXPECT_EQ (2, getAccentFromChar ("Ả"));
    EXPECT_EQ (3, getAccentFromChar ("ẵ"));
    EXPECT_EQ (4, getAccentFromChar ("ị"));
    EXPECT_EQ (5, getAccentFromChar ("n"));

    EXPECT_STREQ (__("á"), addAccentToChar ("a", ACUTE).c_str ());
    EXPECT_STREQ (__("ặ"), addAccentToChar ("ă", DOT).c_str ());
    EXPECT_STREQ (__("Ổ"), addAccentToChar ("Ô", HOOK).c_str ());
    EXPECT_STREQ (__("n"), addAccentToChar ("n", DOT).c_str ());
    EXPECT_STREQ (__("Ễ"), addAccentToChar ("Ê", TILDE).c_str ());

    EXPECT_STREQ (__("â"), addMarkToChar ("ă", HAT).c_str ());
    EXPECT_STREQ (__("Ự"), addMarkToChar ("Ự", HAT).c_str ());
    EXPECT_STREQ (__("N"), addMarkToChar ("N", HAT).c_str ());
    EXPECT_STREQ (__("ổ"), addMarkToChar ("ỏ", HAT).c_str ());
    EXPECT_STREQ (__(" "), addMarkToChar (" ", HAT).c_str ());
    EXPECT_STREQ (__("Ẳ"), addMarkToChar ("Ả", BREVE).c_str ());
    EXPECT_STREQ (__("ử"), addMarkToChar ("ủ", HORN).c_str ());
    EXPECT_STREQ (__("Đ"), addMarkToChar ("D", BAR).c_str ());
    EXPECT_STREQ (__("Đ"), addMarkToChar ("Đ", BAR).c_str ());
}

TEST (CharacterHelpers, PlainCharacters) {
    EXPECT_TRUE (isLetter ("n"));
    EXPECT_TRUE (isLetter ("ọ"));
    EXPECT_TRUE (isLetter ("ổ"));
    EXPECT_TRUE (isLetter ("Ầ"));
    EXPECT_TRUE (isLetter ("Ẩ"));
    EXPECT_TRUE (isLetter ("á"));
    EXPECT_TRUE (isLetter ("Ả"));
    EXPECT_TRUE (isLetter ("T"));
    EXPECT_TRUE (isLetter ("b"));
    EXPECT_TRUE (isLetter ("a"));
    EXPECT_TRUE (isLetter ("g"));
    EXPECT_TRUE (isLetter ("o"));
    EXPECT_TRUE (isLetter ("t"));
    EXPECT_TRUE (isLetter ("s"));
    EXPECT_TRUE (isLetter ("e"));
    EXPECT_FALSE (isLetter ("7"));
    EXPECT_FALSE (isLetter ("5"));
    EXPECT_FALSE (isLetter ("2"));
    EXPECT_FALSE (isLetter ("1"));
    EXPECT_FALSE (isLetter ("6"));
    EXPECT_TRUE (isLetter ("S"));
    EXPECT_TRUE (isLetter ("A"));
    EXPECT_TRUE (isLetter ("T"));
    EXPECT_TRUE (isLetter ("O"));
    EXPECT_FALSE (isLetter ("\\"));
    EXPECT_FALSE (isLetter ((gchar) 13)); // Return
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest (&argc, argv);
    int dummyVal = RUN_ALL_TESTS ();

    return 0;
}
