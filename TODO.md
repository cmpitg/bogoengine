## `ustring addMarkToWord (ustring, Marks)`

## `ustring addAccentToWord (ustring, Accents)`

## Thêm phần hỗ trợ các bảng mã

### Dự kiến

* Xây dựng hàm chuyển xâu `str` từ bảng mã `charsetA` sang bảng mã `charsetB`:
  `Glib::ustring convertCharset (Glib::ustring str, CharSet charsetA, CharSet charsetB)`.

  - `CharSet` là alias của `guint`, mỗi bảng mã nhận một số nguyên dương duy
    nhất làm ID.

  - Tại hàm `processKey`, xâu và ký tự input (`str` và `ch` tương ứng) sẽ được
    xử lý thông qua trình tự:

    * Convert `str` sang UTF-8.
    * Convert ký tự `ch` sang UTF-8.
    * Xử lý `str` và `ch` sau khi đã convert, thu được kết quả.
    * Convert kết quả sang bảng mã output và trả kết quả về.

* **Nâng cao**: cân nhắc và đo đạc thêm về việc xử lý trực tiếp ký tự trong
  bảng mã mà người dùng sử dụng, không thông qua bước convert:

  - Khi đó các hằng liên quan đến ký tự sẽ có thêm một chỉ số ID của bảng mã,
  chẳng hạn: `Vowels[CHARSET_UTF8]` là danh sách nguyên âm trong bảng mã
  UTF-8, `Vowels[CHARSET_TCVN3]` là danh sách nguyên âm trong bảng mã TCVN 3,
  ...

  - Các hàm xử lý ký tự và từ cũng nhận thêm tham số ID của bảng mã.

## Thêm phần hỗ trợ định nghĩa các kiểu gõ

### Dự kiến

##### Mỗi kiểu gõ được mô tả trong một file plain text.

##### Cú pháp:

    Key1 Transformation1
    Key2 Transformation2
    ...

Trong đó `Key` là phím người sử dụng nhấn để có được phép biến đổi
`Transformation`.  File mô tả có thể có dòng trắng.  Mỗi cặp `Key` và
`Transformation` ngăn cách với nhau ít nhất một dấu cách.

`Key` là ký tự trong bảng chữ cái tiếng Anh, hoặc chữ số, hoặc một trong số
các ký tự đặc biệt: ``( ) [ ] { } < > / | \ ! + = ? # . , ; : ~ @ ^ ` & % $``.

Phép biến đổi `Transformation` được quy ước là một trong các ký tự sau:

- Thêm mũ (hat)
  + `a^`, biến *a* thành *â*, *A* thành *Â*.
  + `o^`, biến *o* thành *ô*, *O* thành *Ô*.
  + `e^`, biến *e* thành *ê*, *E* thành *Ê*.

- Thêm sừng (horn):
  + `o+`, biến *o* thành *ơ*, *O* thành *Ơ*.
  + `u+`, biến *u* thành *ư*, *U* thành *Ư*.

- Thêm dấu *ă* (breve): `v`, biến *a* thành *ă*, *A* thành *Ă*.

- Thêm thanh ngang (bar) cho chữ cái `d` và `D`: `-`, biến *d* thành
  *đ*, *D* thành *Đ*.

- Thêm dấu huyền (grave): `\\`

- Thêm dấu sắc (acute): `/`

- Thêm dấu hỏi (hook): `?`

- Thêm dấu ngã (tilde): `~`

- Thêm dấu nặng (dot): `.`

- Xóa dấu: `_`

Ví dụ: nội dung của file mô tả kiểu gõ *Simple Telex*:

    a a^
    o o^
    e e^
    w o+
    w u+
    w v
    d -

    f \
    s /
    r ?
    x ~
    j .
    z _

##### Mặc định, **BoGoEngine** đi kèm với 4 kiểu gõ: *Telex*, *Simple Telex*, *VNI*, và *VIQR*

##### Ghi chú: Để thêm dấu cho một đoạn text, cần tìm **từ cuối cùng** của text, chẳng hạn "nànố", "mèovàng", ...

## Thảo luận:

### Hỗ trợ việc thêm dấu
    "[kiểu mới](http://vi.wikipedia.org/wiki/Quy_tắc_đặt_dấu_thanh_trong_tiếng_Việt#Ki.E1.BB.83u_m.E1.BB.9Bi)"?

**cmpitg**: không hỗ trợ, không ủng hộ cách bỏ dấu "kiểu mới".  Để giữ gìn sự trong sáng của tiếng việt.

### Xử lý từ tiếng Việt: "mecf" (không thêm dấu khi nhấn "f") với "mèc" (thêm dấu khi nhấn "f")?

Ví dụ:

* "mecf" thành "mèc" hay "mecf"?
* "mecfwee" thành "mecfê" hay "mecfwee"?

Dam Tien Long

    Có thể coi vần như là 1 cách để biết rằng từ đang viết còn có thể mở rộng hay là đã kết thúc. (ac có thể mở rộng thành ach, ach thì ko thể mở rộng được nữa)

    