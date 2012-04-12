# Bắt đầu với BoGoEngine

## Cấu hình kỹ thuật

**BoGoEngine** sử dụng:

* CMake 2.6+
* gcc 4.2+
* glibmm 2.4
* Google Test **1.5.0** (bản *1.6.0* có lỗi khi so sánh string, *không sử dụng
  được với BoGoEngine*)

## Lưu ý

### Lưu ý chung

* **BoGoEngine** sử dụng C++.  Lý do: tiết kiệm công sức cho việc mở rộng và
  bảo trì mã nguồn mà vẫn đạt được hiệu suất rất cao.

* **BoGoEngine** dùng thư viện **glibmm** (wrapper của Glib cho ngôn ngữ C++).
  Lý do: Glib nhẹ, nhanh, API rõ ràng, trong sáng, có convention, tương đối dễ
  sử dụng, khả năng bảo trì và mở rộng tốt; đặc biệt Glib có mặt mặc định trên
  hầu hết các bản phân phối GNU/Linux.

* **BoGoEngine** đặc biệt chú trọng vào *khả năng tái sử dụng (reusability)*,
  *khả năng bảo trì (maintenance)*, *khả năng mở rộng (extensibility)* và *mức
  độ trong sáng, "tao nhã" (clearance and elegant)* của mã nguồn.

### Quy ước về mã nguồn

* **BoGoEngine** sử dụng
  [functional programming style](https://en.wikipedia.org/wiki/Functional_programming),
  hạn chế tối đa side effect và state.

* Cách đặt tên:

  - Các hằng primitive được `VIẾT_HOA_TOÀN_BỘ_VÀ_NGĂN_CÁCH_BỞI_GẠCH_CHÂN`.

  - Các hằng non-primitive, tên *struct*, tên *enum*, tên *class* được
    `ViếtHoaCácChữCáiĐầu`.

  - Tên biến, hàm, method được đặt theo `kýPhápCamelCase`.

* Để indent, *không dùng tab* mà sử dụng *04 dấu cách*.

* Ngoại trừ việc gọi constructor, tên hàm được ngăn cách với danh cách tham số
  bởi *01 dấu cách*, khi khai báo hàm cũng như khi gọi hàm.  Ví dụ hàm `main`
  được khai báo như sau: `int main (int argc, const char *argv[])`.

* Code block được mở đóng ngoặc `{}` theo Java style: mở ngoặc cùng dòng với
  câu lệnh trước, đóng ngoặc dưới câu lệnh cuối cùng 01 dòng, ví dụ:

      ```C++
      void helloWorld (const gchar *names[], guint nNames) {
          for (guint iName = 0; iName < nNames; i++) {
              sayHelloTo (names[i]);
          }
      }
      ```

* Ngoại trừ hằng string, tất cả các dòng đều không được phép vượt quá 80 ký
  tự.

* Mọi hàm xử lý **buộc** phải có test và documentation giải thích chi tiết,
  đầy đủ chức năng của hàm cũng như input/output của hàm, trừ khi ngữ nghĩa
  của hàm được phản ánh quá rõ ràng thông qua cách đặt tên.  **BoGoEngine** sử
  dụng **GoogleTest** nên quá trình viết test rất đơn giản và hiệu quả.

* Hạn chế tuyệt đối việc thêm cấu trúc dữ liệu mới.

* Hạn chế tuyệt đối các thao tác cấp phát/thu hồi bộ nhớ bằng tay như: `new`,
  `delete`, `delete[]`, `malloc`, ...

* **Hạn chế tuyệt đối việc mở rộng method cho class/struct**.  **BoGoEngine**
  viết theo functional programming style.  Hãy sử dụng hàm và tính năng
  function overloading thay vì dùng method.

* Các hàm làm việc trên `Glib::ustring`, sử dụng `toStdString` để chuyển đổi
  sang STL String của C++ chuẩn, hoặc `toCString` để chuyển đổi sang C String.

* **Không thao tác trên char**, tất cả các thao tác đều thực hiện trên
  `Glib::ustring`.

## Cách thức xử lý tiếng Việt

**Lưu ý**: khái niệm "*từ*" trong **BoGoEngine** được dùng tương đương với
khái niệm *âm tiết* hoặc *từ đơn* trong ngôn ngữ học.  Chẳng hạn trong ngôn
ngữ học thì "hợp tác xã" là *một từ có 03 âm tiết*, còn **BoGoEngine** coi cụm
từ ấy là *03 từ đơn*.

Nhìn chung, việc xử lý tiếng Việt bao gồm có:

* Biến đổi một chữ cái thành chữ cái biến thể của nó, chẳng hạn *a* thành
  *ă* hoặc *â*:

  - Ký tự **ˆ** gọi là *circumflex*, *hat*, hoặc *roof*.  **BoGoEngine** sử
    dụng từ *hat*.

  - Ký tự **̛** gọi là *horn*.

  - Ký tự **˘** gọi là *breve*.

  - Ký hiệu gạch ngang của chữ cái **đ** (**Đ**) gọi là *bar* hoặc *stroke*.
  **BoGoEngine** sử dụng *bar*.

* Thêm/bỏ dấu cho một chữ cái.  Tên các dấu theo quy ước quốc tế:

  - Không dấu (no accent/plain).
  - Dấu huyền: grave.
  - Dấu sắc: acute.
  - Dấu hỏi: hook.
  - Dấu ngã: tilde.
  - Dấu nặng: dot.

* 4 ký tự biến đổi chữ cái cộng thêm 5 ký tự mô tả dấu trong tiếng Việt đều
  được gọi là *diacritical mark*.  Tuy nhiên chỉ có *5 ký tự dấu* mới làm
  *thay đổi trọng âm* của một âm xác định, vì vậy **BoGoEngine** quy ước:

  - Gọi 5 ký tự dấu là *accent*.
  - Gọi 4 ký tự *hat*, *horn*, *breve*, và *bar* là *mark*.

* Quy tắc thêm dấu cho một từ:

  Một từ được phân tích thành 3 thành phần: _[phụ âm 1]_ + _[nguyên âm]_ +
  _[phụ âm 2]_, trong đó có 2 trường hợp đặc biệt: với các từ bắt đầu bằng
  _"gi..."_ hoặc _"qu..."_ thì _"gi"_ và _"qu"_ thuộc về _[phụ âm 1]_ chứ
  không phải _[nguyên âm]_.  Một trong 3 thành phần có thể rỗng.

  Ví dụ:
  - Với từ _"người"_ thì _[phụ âm 1]_ là "ng", _[nguyên âm]_ là "ười",
    _[phụ âm 2]_ là "".
  - Với từ _"trường"_ thì _[phụ âm 1]_ là "tr", _[nguyên âm]_ là "ườ",
    _[phụ âm 2]_ là "ng".
  - Với từ _"oạch"_ thì _[phụ âm 1]_ là "", _[nguyên âm]_ là "oạ",
    _[phụ âm 2]_ là "ch".

  **BoGoEngine** sử dụng quy tắc thêm dấu
    [kiểu cũ](http://vi.wikipedia.org/wiki/Quy_tắc_đặt_dấu_thanh_trong_tiếng_Việt#Ki.E1.BB.83u_c.C5.A9)
    cho một từ được phát biểu giản lược như sau:
  - Nếu _[nguyên âm]_ có chữ cái "ê" hoặc "ơ" thì thêm dấu ở các chữ cái này;
    ngược lại,
  - nếu _[phụ âm 2]_ tồn tại => thêm dấu vào nguyên âm cuối cùng; ngược lại,
  - nếu _[nguyên âm]_ gồm 3 chữ cái => thêm dấu vào chữ cái ở giữa; ngược lại,
  - thêm dấu vào nguyên âm đầu tiên

Ngoài công việc xử lý tiếng Việt, **BoGoEngine** còn làm công việc của một bộ
gõ:

* Xử lý một ký tự khi ký tự đó được đưa vào một string, thay đổi string theo
  cách gõ: `processKey`.

* Cho phép người dùng tự định nghĩa cách gõ của riêng mình.

* **BoGoEngine** sử dụng bảng mã *UTF-8*, tất cả các thao tác trên các bảng mã
  khác được thực hiện qua các hàm chuyển đổi (conversion).

* FIXME: Các kiểu gõ và cách định nghĩa kiểu gõ.

* FIXME: Khôi phục tiếng Anh.

### Các quy ước khác

* Một ký tự được gọi là ký tự kết thúc từ nếu như ký tự đó không thuộc bảng
  chữ cái và không phải là ký tự xóa lùi (Backspace).

* Vì tất cả các ký tự sử dụng để biến đổi chữ cái hoặc thêm dấu đều là ký tự
  ASCII, một bộ gõ có thể được định nghĩa như sau:

      ```c++
      typedef vector<ustring> InputMethodT;
      ```

  Trong đó:

  - Mỗi một phần tử của `InputMethodT` là một `ustring`, quy ước biến đổi một từ:

    + Ký tự đầu tiên của `ustring` mô tả *ký tự sử dụng* để biến đổi.
    + Ký tự thứ hai của `ustring` mô tả đối tượng mà phép biến đổi đó tác động,
    nếu phép biến đổi này có thể tác động lên tất cả các đối tượng thì ký tự
    này là `*`.
    + Ký tự thứ ba của `ustring` mô tả phép biến đổi.

    Ví dụ: `"aa+"` mô tả phép biển đổi: nhấn ký tự *'a'* để thêm dấu mũ cho ký
    tự *'a'*; `"f*\\"` mô tả phép biến đổi: nhấn ký tự _'f'_ để thêm dấu
    huyền.
