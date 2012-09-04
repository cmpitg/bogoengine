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
#include "engine.hpp"

namespace BoGo {

#ifdef _
#undef _
#endif
#define _(x) (ustring ("") + x)

#ifdef __
#undef __
#endif
#define __(x) (ustring ("") + x).c_str ()

    using namespace Glib;
    using namespace std;

    ustring processKeyUTF8 (ustring text, char key, InputMethodT im,
                            guint BackspaceChar) {
        // Case: Backspace character
        if (key == BackspaceChar) {
            _size_t_ pos = getLastPseudoWordPos (text);

            // Case: no word inside text
            if (pos == ustring::npos)
                return text.substr (0, text.size () - 1);

            ustring firstPart = text.substr (0, pos);
            ustring lastWord = text.substr (pos);
            Accents accent = getAccentFromWord (lastWord);
            lastWord.replace (lastWord.size () - 1, 1, "");
            return firstPart + addAccentToWord (lastWord, accent);
        }

        gchar lowCaseKey = _(key).lowercase ()[0];
        ustringArrayT availTrans = findTransform (__(lowCaseKey), im);

        // Case: `key` is not for transforming
        if (availTrans.size () == 0)
            return addChar (text, _(key));

        TransformTypeT markOrAccent;
        // cerr << "Text >> " << __(text) << " -> " << endl;
        ustring res = "";

        for (guint i = 0; i < availTrans.size (); i++) {
            const gchar *trans = availTrans[i].c_str ();
            TransformTypeT tmpMarkOrAccent = getTransformType (trans[2]);
            TransformT tmpTrans = getTransform (trans[2]);
            ustring tmpRes;

            if (tmpMarkOrAccent == TRANSFORM_MARK)
                tmpRes = addMarkToText (text, tmpTrans, trans[1]);
            else
                tmpRes = addAccentToText (text, tmpTrans);

            // cerr << " >> " << trans << " -> "
            //      << "mark? " << (tmpMarkOrAccent == TRANSFORM_MARK) << " -> "
            //      << "trans: " << tmpTrans << " -> "
            //      << __(tmpRes) << endl;

            if (res == "" || (tmpRes != text && res != "")) {
                res = tmpRes;
                markOrAccent = tmpMarkOrAccent;
            }
        }

        // Case: fallback to English
        if (res.size () == 0 || res == text) {
            if (markOrAccent == TRANSFORM_MARK)
                res = addChar (removeMarksFromLastWord (text), _(key));
            else
                res = addChar (removeAccentFromLastWord (text), _(key));
        }

        return res;
    }

    ustring processKey (ustring text, char key, InputMethodT im,
                        guint BackspaceChar) {
        return processKeyUTF8 (text, key, im, BackspaceChar);
    }

#undef _
#undef __
}

