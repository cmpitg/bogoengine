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

    const ustring VowelsWithoutHat  = _("aàáảãạeèéẻẽẹoòóỏõọ");
    const ustring VowelsWithHat     = _("âầấẩẫậêềếểễệôồốổỗộ");

    const ustring VowelsWithoutHorn  = _("aàáảãạoòóỏõọuùúủũụ");
    const ustring VowelsWithHorn     = _("ăằắẳãạơờớởỡợưừứửữự");

    // Separate
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
