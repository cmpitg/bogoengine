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

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <glibmm/ustring.h>
#include "utils.hpp"

namespace BoGo {

    using namespace Glib;
    
    ustring processKeyUTF8 (ustring text,
                            gchar key,
                            InputMethodT im = makeStandardIM (IM_SIMPLETELEX),
                            guint BackspaceChar = BACKSPACE_CODE);

    ustring processKey (ustring text,
                        gchar key,
                        InputMethodT im = makeStandardIM (IM_SIMPLETELEX),
                        guint BackspaceChar = BACKSPACE_CODE);

    void processKey (const gchar *text,
                     gchar key,
                     const gchar *result,
                     InputMethodT im = makeStandardIM (IM_SIMPLETELEX),
                     CharSetT charset = CHARSET_UTF8);
}

#endif
