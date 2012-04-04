## Thêm phần hỗ trợ các bảng mã

?

## Thêm phần hỗ trợ định nghĩa các kiểu gõ

### Dự kiến

* Mỗi kiểu gõ được mô tả trong một file plain text.

* Cú pháp:

      ```
      Key1 Transformation1
      Key2 Transformation2
      ...
      ```

  Trong đó `Key` là phím người sử dụng nhấn để có được phép biến đổi
  `Transformation`.  File mô tả có thể có dòng trắng.  Mỗi cặp `Key` và
  `Transformation` ngăn cách với nhau ít nhất một dấu cách.

  `Key` là ký tự trong bảng chữ cái tiếng Anh, hoặc chữ số, hoặc một trong số
  các ký tự đặc biệt: ``( ) [ ] { } < > / | \ ! + = ? # . , ; : ~ @ ^ ` & %
  $``.

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

      ```
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
      ```

* Mặc định, **BoGoEngine** đi kèm với 4 kiểu gõ: *Telex*, *Simple Telex*,
  *VNI*, và *VIQR*
