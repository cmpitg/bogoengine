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

#include "engine.hpp"

namespace BoGo {

    using namespace Glib;
    using namespace std;

#ifdef _
#undef _
#endif
#define _(x) (ustring ("") + x)

#ifdef __
#undef __
#endif
#define __(x) (ustring ("") + x).c_str ()

    ustring replace (ustring str, ustring oldPortion,
                     ustring newPortion, _size_t startFrom = 0) {
        _size_t pos = str.find (oldPortion, startFrom);
        if (pos != ustring::npos)
            str.replace (pos, oldPortion.length (), newPortion);
        return str;
    }

#undef _
#undef __
}
