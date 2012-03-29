# Bắt đầu với BoGoEngine

## Cấu hình kỹ thuật

**BoGoEngine** sử dụng:

* CMake 2.6+
* gcc 4.2+
* gtkmm 2.4
* GoogleTest

## Lưu ý

### Lưu ý chung

* **BoGoEngine** sử dụng C++.  Lý do: tiết kiệm công sức cho việc mở rộng và
  bảo trì mã nguồn mà vẫn đạt được hiệu suất rất cao.

* **BoGoEngine** dùng thư viện **gtkmm** (wrapper của GTK+ cho ngôn ngữ C++).
  Lý do: GTK+ nhẹ, nhanh, API rõ ràng, trong sáng, có convention, tương đối dễ
  sử dụng, khả năng bảo trì và mở rộng tốt; đặc biệt GTK+ có mặt mặc định trên
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

      void helloWorld (const gchar *names[], guint nNames) {
          for (guint iName = 0; iName < nNames; i++) {
              sayHelloTo (names[i]);
          }
      }

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

## Cách thức xử lý tiếng Việt của chương trình

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

  Do đó, 4 hàm biến đổi *chữ cái* tương ứng với 4 trường hợp trên là:
  `addHatToChar`, `addHornToChar`, `addBreveToChar`, và `addBarToChar`.

* Mở rộng ý trên, 4 hàm biến đổi *từ* tương ứng là: `addHatToWord`,
  `addHornToWord`, `addBreveToWord`, và `addBarToWord`.

* Thêm/bỏ dấu cho một chữ cái.  Tên các dấu theo quy ước quốc tế:

  - Không dấu (no accent/plain).
  - Dấu huyền: grave.
  - Dấu sắc: acute.
  - Dấu hỏi: hook.
  - Dấu ngã: tilde.
  - Dấu nặng: dot.

  Do đó, 6 hàm thêm dấu tương ứng cho *một chữ cái* là:
  `removeAccentFromChar`, `addGraveToChar`, `addAcuteToChar`, `addHookToChar`,
  `addTildeToChar`, `addDotToChar`.

* Mở rộng ý trên, 6 hàm thêm dấu tương ứng cho *một từ* là:
  `removeAccentFromWord`, `addGraveToWord`, `addAcuteToWord`, `addHookToWord`,
  `addTildeToWord`, `addDotToWord`.

Ngoài công việc xử lý tiếng Việt, **BoGoEngine** còn làm công việc của một bộ
gõ:

* Xử lý một ký tự khi ký tự đó được đưa vào một string, thay đổi string theo
  cách gõ: `processKey`.

* Cho phép người dùng tự định nghĩa cách gõ của riêng mình.
