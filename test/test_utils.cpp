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

TEST (TextManipulation, AddMarkToText) {
    EXPECT_STREQ ("KĐẹo", __(addMarkToText ("KDẹo", BAR)));
    EXPECT_STREQ ("đEO", __(addMarkToText ("dEO", BAR)));
    EXPECT_STREQ ("mưA", __(addMarkToText ("muA", HORN)));
    EXPECT_STREQ ("rƯơi", __(addMarkToText ("rUoi", HORN)));
    EXPECT_STREQ ("rUỏi", __(addMarkToText ("rUỏi", BAR)));
    EXPECT_STREQ ("mỮT", __(addMarkToText ("mỮT", BREVE)));
    EXPECT_STREQ ("trgiận", __(addMarkToText ("trgiạn", HAT)));
    EXPECT_STREQ ("trquẮn", __(addMarkToText ("trquÁn", BREVE)));
    EXPECT_STREQ ("măn", __(addMarkToText ("man", BREVE)));
    EXPECT_STREQ ("làmanz", __(addMarkToText ("làmanz", BREVE)));
    EXPECT_STREQ ("chuyek", __(addMarkToText ("chuyek", HAT)));
    EXPECT_STREQ ("gộu", __(addMarkToText ("gọu", HAT)));
}

TEST (TextManipulation, AddAccentToText) {
    EXPECT_STREQ ("lntmèo", __(addAccentToText ("lntmeo", GRAVE)));
    EXPECT_STREQ ("TmèO", __(addAccentToText ("TmeO", GRAVE)));
    EXPECT_STREQ ("KĐẹo", __(addAccentToText ("KĐeo", DOT)));
    EXPECT_STREQ ("rUỏi", __(addAccentToText ("rUoi", HOOK)));
    EXPECT_STREQ ("mỮT", __(addAccentToText ("mƯT", TILDE)));
    EXPECT_STREQ ("muw", __(addAccentToText ("muw", DOT)));
    EXPECT_STREQ ("trgiận", __(addAccentToText ("trgiân", DOT)));
    EXPECT_STREQ ("trquán", __(addAccentToText ("trquan", ACUTE)));
    EXPECT_STREQ ("chuyêk", __(addAccentToText ("chuyêk", ACUTE)));
    EXPECT_STREQ ("chuyêk", __(addAccentToText ("chuyêk", DOT)));
    EXPECT_STREQ ("nokckf", __(addAccentToText ("nokckf", TILDE)));
    EXPECT_STREQ ("gôu", __(addAccentToText ("gốu", NO_ACCENT)));
}

TEST (TextManipulation, ValidEndingConsonants) {
    EXPECT_TRUE (hasValidEndingConsonantsP("lntmèo"));
    EXPECT_TRUE (hasValidEndingConsonantsP("TmèO"));
    EXPECT_TRUE (hasValidEndingConsonantsP("KĐẹo"));
    EXPECT_TRUE (hasValidEndingConsonantsP("rUỏi"));
    EXPECT_TRUE (hasValidEndingConsonantsP("mỮT"));
    EXPECT_FALSE (hasValidEndingConsonantsP("mụw"));
    EXPECT_TRUE (hasValidEndingConsonantsP("trgiận"));
    EXPECT_TRUE (hasValidEndingConsonantsP("trquán"));
    EXPECT_FALSE (hasValidEndingConsonantsP("làmănz"));
    EXPECT_FALSE (hasValidEndingConsonantsP("chuyêk"));
    EXPECT_FALSE (hasValidEndingConsonantsP("chuyêk"));
    EXPECT_FALSE (hasValidEndingConsonantsP("nokckf"));
    EXPECT_TRUE (hasValidEndingConsonantsP("gôu"));
}

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
    EXPECT_STREQ ("èo", __(addAccentToWord ("eo", GRAVE)));
    EXPECT_STREQ ("iều", __(addAccentToWord ("iêu", GRAVE)));
    EXPECT_STREQ ("uối", __(addAccentToWord ("uôi", ACUTE)));
    EXPECT_STREQ ("Ẹ", __(addAccentToWord ("E", DOT)));
    EXPECT_STREQ ("huYền", __(addAccentToWord ("huYên", GRAVE)));
    EXPECT_STREQ ("uYê", __(addAccentToWord ("uYế", NO_ACCENT)));
    EXPECT_STREQ ("xóa", __(addAccentToWord ("xoa", ACUTE)));
    EXPECT_STREQ ("xoÁn", __(addAccentToWord ("xoAn", ACUTE)));
    EXPECT_STREQ ("xoẮn", __(addAccentToWord ("xoĂn", ACUTE)));
    EXPECT_STREQ ("xoaÁN", __(addAccentToWord ("xoaAN", ACUTE)));
    EXPECT_STREQ ("giịa", __(addAccentToWord ("giia", DOT)));
    EXPECT_STREQ ("Đoòng", __(addAccentToWord ("Đoong", GRAVE)));
}

TEST (WordHelpers, AddMarkToWord) {
    EXPECT_STREQ ("ê", __(addMarkToWord ("e", HAT)));
    EXPECT_STREQ ("đ", __(addMarkToWord ("d", BAR)));
    EXPECT_STREQ ("uối", __(addMarkToWord ("uói", HAT)));
    EXPECT_STREQ ("uói", __(addMarkToWord ("uói", HAT, 'a')));
    EXPECT_STREQ ("mưa", __(addMarkToWord ("mua", HORN)));
    EXPECT_STREQ ("muâ", __(addMarkToWord ("mua", HAT, 'a')));
    EXPECT_STREQ ("đeo", __(addMarkToWord ("deo", BAR)));
    EXPECT_STREQ ("ươi", __(addMarkToWord ("uoi", HORN)));
    EXPECT_STREQ ("nẰm", __(addMarkToWord ("nÀm", BREVE)));
    EXPECT_STREQ ("ĐẰm", __(addMarkToWord ("DẰm", BAR)));
    EXPECT_STREQ ("rƯơi", __(addMarkToWord ("rUoi", HORN)));
    EXPECT_STREQ ("TrƯơng", __(addMarkToWord ("TrUong", HORN)));
    EXPECT_STREQ ("TrƯơng", __(addMarkToWord ("TrUong", HORN, 'u')));
    EXPECT_STREQ ("ưu", __(addMarkToWord ("uu", HORN)));
}

TEST (ProcessKey, ProcessKey) {
    EXPECT_STREQ(__("mèo"), __(processKey ("mèov", BACKSPACE_CODE)));
    EXPECT_STREQ(__("mèo"), __(processKey ("meo", 'f')));
    EXPECT_STREQ(__("Đèo"), __(processKey ("Dèo", 'd')));
    EXPECT_STREQ(__("đèo"), __(processKey ("dèo", 'D')));
    EXPECT_STREQ(__("đEO"), __(processKey ("đÈO", 'z')));
    EXPECT_STREQ(__("mưA"), __(processKey ("muA", 'w')));
    EXPECT_STREQ(__("rƯơi"), __(processKey ("rUoi", 'w')));
    EXPECT_STREQ(__("rUòi"), __(processKey ("rUoi", 'f')));
    EXPECT_STREQ(__("ruoiw"), __(processKey ("rươi", 'w')));
    EXPECT_STREQ(__("mỬ"), __(processKey ("mỦ", 'w')));
    EXPECT_STREQ(__("mỦw"), __(processKey ("mỬ", 'w')));
    EXPECT_STREQ(__("măn"), __(processKey ("man", 'w')));
    EXPECT_STREQ(__("mũmmĩm"), __(processKey ("mũmmim", 'X')));
    EXPECT_STREQ(__("làmănz"), __(processKey ("làmăn", 'z')));
    EXPECT_STREQ(__("chuyệk"), __(processKey ("chuyêk", 'j')));
    EXPECT_STREQ(__("quảđur"), __(processKey ("quảđủ", 'r')));
    EXPECT_STREQ(__("mèokckf"), __(processKey ("mèokck", 'f')));
    EXPECT_STREQ(__("meO"), __(processKey ("me", 'O')));
    EXPECT_STREQ (__("làmănz"), __(processKey ("làmăn", 'z')));
    EXPECT_STREQ (__("chuyệk"), __(processKey ("chuyêk", 'j'))); // FIXME: Need to discuss
    EXPECT_STREQ (__("đèO"), __(processKey ("dèO", 'D')));
    EXPECT_STREQ (__("geO"), __(processKey ("ge", 'O')));
    EXPECT_STREQ (__("goa"), __(processKey ("go", 'a')));
    EXPECT_STREQ (__("gô"), __(processKey ("go", 'o')));
    EXPECT_STREQ(__("họa"), __(processKey ("hoạt", BACKSPACE_CODE)));
}

TEST (MarkAndWord, RemoveAllMarks) {
    EXPECT_STREQ ("thuỏ", __(removeAllMarksFromWord ("thuở")));
    EXPECT_STREQ ("gIỵA", __(removeAllMarksFromWord ("gIỵA")));
    EXPECT_STREQ ("uýNh", __(removeAllMarksFromWord ("uýNh")));
    EXPECT_STREQ ("LỌn", __(removeAllMarksFromWord ("LỘn")));
    EXPECT_STREQ ("xOoNg", __(removeAllMarksFromWord ("xOoNg")));
    EXPECT_STREQ ("xOÒng", __(removeAllMarksFromWord ("xOÒng")));
    EXPECT_STREQ ("khúC", __(removeAllMarksFromWord ("khứC")));
    EXPECT_STREQ ("HuO", __(removeAllMarksFromWord ("HuƠ")));
    EXPECT_STREQ ("HuOu", __(removeAllMarksFromWord ("HưƠu")));
    EXPECT_STREQ ("HuONg", __(removeAllMarksFromWord ("HưƠNg")));
}

TEST (MarkAndWord, RemoveMark) {
    EXPECT_STREQ ("thuỏ", __(removeMarkFromWord ("thuở", 3)));
    EXPECT_STREQ ("gIỵA", __(removeMarkFromWord ("gIỵA", 2)));
    EXPECT_STREQ ("uýNh", __(removeMarkFromWord ("uýNh", 1)));
    EXPECT_STREQ ("LỌn", __(removeMarkFromWord ("LỘn", 1)));
    EXPECT_STREQ ("xOoNg", __(removeMarkFromWord ("xOoNg", 3)));
    EXPECT_STREQ ("xOÒng", __(removeMarkFromWord ("xOÒng", 2)));
    EXPECT_STREQ ("khúC", __(removeMarkFromWord ("khứC", 2)));
    EXPECT_STREQ ("HuO", __(removeMarkFromWord ("HuƠ", 2)));
}

TEST (AccentAndWord, RemoveAccent) {
    EXPECT_STREQ ("thuơ", __(removeAccentFromWord ("thuở")));
    EXPECT_STREQ ("gIyA", __(removeAccentFromWord ("gIỵA")));
    EXPECT_STREQ ("uyNh", __(removeAccentFromWord ("uýNh")));
    EXPECT_STREQ ("LÔn", __(removeAccentFromWord ("LỘn")));
    EXPECT_STREQ ("xOoNg", __(removeAccentFromWord ("xOoNg")));
    EXPECT_STREQ ("xOOng", __(removeAccentFromWord ("xOÒng")));
    EXPECT_STREQ ("khuC", __(removeAccentFromWord ("khúC")));
    EXPECT_STREQ ("kHuYU", __(removeAccentFromWord ("kHuỶU")));
    EXPECT_STREQ ("HuƠ", __(removeAccentFromWord ("HuƠ")));
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
    EXPECT_STREQ (__("ô"), __(removeAccentFromChar ("ố")));
    EXPECT_STREQ (__("ô"), __(removeAccentFromChar ("ổ")));
    EXPECT_STREQ (__("Ô"), __(removeAccentFromChar ("Ỗ")));
    EXPECT_STREQ (__("ô"), __(removeAccentFromChar ("ộ")));
    EXPECT_STREQ (__("â"), __(removeAccentFromChar ("ầ")));
    EXPECT_STREQ (__("Â"), __(removeAccentFromChar ("Ấ")));
    EXPECT_STREQ (__("â"), __(removeAccentFromChar ("ẩ")));
    EXPECT_STREQ (__("Â"), __(removeAccentFromChar ("Ẫ")));
    EXPECT_STREQ (__("â"), __(removeAccentFromChar ("ậ")));

    EXPECT_STREQ (__("ó"), __(removeMarkFromChar ("ố")));
    EXPECT_STREQ (__("ỏ"), __(removeMarkFromChar ("ổ")));
    EXPECT_STREQ (__("Õ"), __(removeMarkFromChar ("Ỗ")));
    EXPECT_STREQ (__("ọ"), __(removeMarkFromChar ("ộ")));
    EXPECT_STREQ (__("à"), __(removeMarkFromChar ("ầ")));
    EXPECT_STREQ (__("Á"), __(removeMarkFromChar ("Ấ")));
    EXPECT_STREQ (__("ả"), __(removeMarkFromChar ("ẩ")));
    EXPECT_STREQ (__("Ã"), __(removeMarkFromChar ("Ẫ")));
    EXPECT_STREQ (__("ạ"), __(removeMarkFromChar ("ậ")));

    EXPECT_STREQ (__("a"), __(toPlainLetter ("â")));
    EXPECT_STREQ (__("a"), __(toPlainLetter ("ắ")));
    EXPECT_STREQ (__("N"), __(toPlainLetter ("N")));
    EXPECT_STREQ (__("O"), __(toPlainLetter ("Ộ")));
    EXPECT_STREQ (__("E"), __(toPlainLetter ("Ễ")));

    EXPECT_EQ (0, getAccentFromChar ("ồ"));
    EXPECT_EQ (1, getAccentFromChar ("Ứ"));
    EXPECT_EQ (2, getAccentFromChar ("Ể"));
    EXPECT_EQ (2, getAccentFromChar ("Ả"));
    EXPECT_EQ (3, getAccentFromChar ("ẵ"));
    EXPECT_EQ (4, getAccentFromChar ("ị"));
    EXPECT_EQ (5, getAccentFromChar ("n"));

    EXPECT_STREQ (__("á"), __(addAccentToChar ("a", ACUTE)));
    EXPECT_STREQ (__("ặ"), __(addAccentToChar ("ă", DOT)));
    EXPECT_STREQ (__("Ổ"), __(addAccentToChar ("Ô", HOOK)));
    EXPECT_STREQ (__("n"), __(addAccentToChar ("n", DOT)));
    EXPECT_STREQ (__("Ễ"), __(addAccentToChar ("Ê", TILDE)));

    EXPECT_STREQ (__("â"), __(addMarkToChar ("ă", HAT)));
    EXPECT_STREQ (__("Ự"), __(addMarkToChar ("Ự", HAT)));
    EXPECT_STREQ (__("N"), __(addMarkToChar ("N", HAT)));
    EXPECT_STREQ (__("ổ"), __(addMarkToChar ("ỏ", HAT)));
    EXPECT_STREQ (__(" "), __(addMarkToChar (" ", HAT)));
    EXPECT_STREQ (__("Ẳ"), __(addMarkToChar ("Ả", BREVE)));
    EXPECT_STREQ (__("ử"), __(addMarkToChar ("ủ", HORN)));
    EXPECT_STREQ (__("Đ"), __(addMarkToChar ("D", BAR)));
    EXPECT_STREQ (__("Đ"), __(addMarkToChar ("Đ", BAR)));
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
