# bogoengine

## Giới thiệu:

*bogoengine* là một thư viện gõ tiếng Việt, phát triển bằng ngôn ngữ
C, tuân theo chuẩn [C99](http://en.wikipedia.org/wiki/C99).

Mục đích của *bogoengine* là được sử dụng bởi *lập trình viên*, nhằm
tích hợp với các chương trình cung cấp input method (như
[Ibus](http://code.google.com/p/ibus/),
[SCIM](http://sourceforge.net/projects/scim/), ...)

## Kênh thông tin

* Trang chủ: <http://bogoengine.reference-error.org/>

* Mail group **phát triển** *bogoengine*:
  <bogoengine-dev@googlegroups.com>, subscribe tại giao diện web
  [Google Group](http://groups.google.com/group/bogoengine-dev/).

## Hoàn cảnh ra đời

Tính đến thời điểm tháng 03 năm 2012, Việt Nam có 04 bộ gõ tiếng Việt
trên GNU/Linux được biết đến và sử dụng phổ biến nhất:

* [x-unikey](http://unikey.org/linux.php) của tác giả *Phạm Kim Long*,
  lần phát hành cuối cùng là vào năm 2006, giấy phép GPL v2.

* [xvnkb](http://xvnkb.sourceforge.net/) của tác giả *Dao Hai Lam*
  <lam [at] visc-network [dot] com>, lần phát hành cuối cùng vào năm
  2004, giấy phép GPL v2.

* [scim-unikey](http://code.google.com/p/scim-unikey/) và
  [ibus-unikey](http://code.google.com/p/ibus-unikey/) là 2 input
  method (IM) dùng cho SCIM và IBus, phát triển bởi *Lê Quốc Tuấn* <mr
  [dot] lequoctuan [at] gmail [dot] com> và *Lê Kiến Trúc*
  <afterlastangel [at] ubuntu-vn [dot] org>, với engine Unikey trích
  xuất từ *x-unikey*, giấy phép GPL v2.  *ibus-unikey* được sử dụng
  phổ biến nhất, có mặt mặc định trên hầu hết tất cả các bản phân phối
  GNU/Linux.  *scim-unikey* phát hành lần cuối cùng vào tháng 08/2009.
  *ibus-unikey* phát hành bản 0.6 vào tháng 01/2012 và hiện nay vẫn
  đang tiếp tục được phát triển.

Tất cả 4 bộ gõ nói trên đều còn nhiều hạn chế, gây khó khăn cho người
sử dụng, đặc biệt với người sử dụng phổ thông. Cụ thể, bộ gõ tiếng
Việt trên GNU/Linux cần đảm bảo các yếu tố sau:

* Là Phần mềm Tự do Nguồn mở
  ([FOSS](http://en.wikipedia.org/wiki/Free_and_open_source_software)).

* Sẵn có trên các bản phân phối GNU/Linux, đặc biệt là các bản phân
  phối phổ biến: Ubuntu, Fedora, Debian, ...

* Có input method (IM) cho các IM platform/framework mặc định phổ biến
  nhất hiện nay: [SCIM](http://sourceforge.net/projects/scim/) và
  [IBus](http://code.google.com/p/ibus/).

* Tài liệu cho người sử dụng và người phát triển rõ ràng, chăm sóc cẩn thận.

* Mã nguồn trong sáng, có chuẩn nhất quán, có ghi chú nếu cần.

* Chạy ổn định.

* Dễ sử dụng với người phổ thông.
    
* Hỗ trợ các bảng mã (UTF-8, UTF-16, TCVN 3, VNI, VIQR, ...) và cách
  gõ phổ biến nhât (Telex, Simple Telex, VNI).

* Hỗ trợ tính năng chuyển mã.

* Khả năng **mở rộng**, **bảo trì**, **tái sử dụng** cao.

Không có một bộ gõ tiếng Việt nào trong số 4 bộ gõ nói trên đáp ứng
được đầy đủ cả 9 yêu cầu này tính đến thời điểm tháng 03 năm 2012. Bên
cạnh đó, *ibus-unikey* có tính năng preedit rất bất tiện cho người sử
dụng nhưng không được tác giả engine điều chỉnh. Trong quá trình tìm
hiểu khắc phục các hạn chế này,
[tác giả BoGoEngine](http://reference-error.org/)
([@cmpitg](https://github.com/CMPITG)) gặp phải hàng loạt các vấn đề:

* Mã nguồn của *Unikey engine* và *ibus-unikey* không có chuẩn nhất
  quán, phần lớn không được ghi chú hoặc ghi chú sơ sài, tối nghĩa,
  rất khó chỉnh sửa và bảo trì.

* Cách thức xử lý tiếng Việt của *Unikey engine* *không tự nhiên* và
  *không được mô tả* trong bất kỳ tài liệu nào tìm được.

* Unikey engine kết hợp
  [object oriented programming](http://en.wikipedia.org/wiki/Object-oriented_programming)
  và
  [imperative programming](http://en.wikipedia.org/wiki/Imperative_programming)
  rối rắm, không nhất quá, lạm dụng state, hạn chế rất lớn khả năng mở
  rộng và bảo trì, dễ phát sinh lỗi.

Tác giả cố gắng refactor và document mã nguồn của *Unikey engine* cùng
*ibus-unikey*, thành công trong việc loại bỏ preedit text nhưng chương
trình phát sinh lỗi không kiểm soát được khi người sử dụng gõ phím
nhanh.

So sánh việc công sức tương đối giữa việc đào sâu tìm hiểu mã nguồn,
sửa lỗi, đáp ứng thêm các yêu cầu nói trên với việc xây dựng một
engine mới, tác giả quyết định chọn phương án thứ hai: viết lại hoàn
toàn engine xử lý nhập liệu tiếng Việt và cho ra đời dự án bogoengine
vào tháng 04 năm 2012.

### Phiên bản 1

Phiên bản đầu tiên được viết vào tháng 03 năm 2012 cùng sự giúp đỡ của
[@fuzzysource](https://github.com/fuzzysource), Chin
([@lewtds](https://github.com/lewtds)),
[@phaikawl](https://github.com/phaikawl) và liên tiếp ra đời các phiên
bản unstable và testing trong vòng 6 tháng.  Tuy nhiên phiên bản này
có rất nhiều hạn chế:

* Sử dụng ngôn ngữ C++.

* Lệ thuộc quá nhiều công cụ bên ngoài một cách không cần thiết trong
  cả quá trình biên dịch lẫn sử dụng, dẫn đến việc hỗ trợ các nền tảng
  khác ngoài *nix như Android, ... tương đối khó khăn:

  - [cmake](http://www.cmake.org/)

  - Thư viện [glibmm](http://developer.gnome.org/glibmm/stable/)

  - [GoogleTest](http://code.google.com/p/googletest/)

* Cách thức xử lý tiếng Việt chưa thực sự tốt.

### Phiên bản 2

Phiên bản 2 ra đời nhằm khắc phục những hạn chế của phiên bản 1:

* Sử dụng C thay vì C++.

* Không phụ thuộc vào bất kỳ công cụ phụ nào ngoại trừ trình biên dịch
  C và thư viện libc chuẩn.
  
* Dễ port, dễ bảo trì, dễ mở rộng hơn phiên bản 1.

* Đi kèm cùng thư viện UTF-8 và unittest nhỏ gọn, dễ chỉnh sửa và sử
  dụng.

## Tài liệu

Tài liệu cho người sử dụng và người phát triển nằm trên
[wiki của dự án](https://github.com/CMPITG/bogoengine/wiki) tại
Github.

Một vài tài liệu hữu ích:

* [Hướng dẫn sử dụng](TODO)

* [Hướng dẫn tham gia dự án](TODO)

## Nguyên tắc phát triển

* Các commit thử nghiệm, tính năng mới nằm trong nhánh *experimental*.

* Chỉ commit vào nhánh *master* phiên bản chạy được.

* Mỗi tính năng luôn có test.

* **Luôn** viết tài liệu trước khi viết code.

* Đóng góp mã nguồn thông qua pull request.

## Giấy phép xuất bản

*bogoengine* được xuất bản dưới các điều khoản của Giấy phép Công cộng
GNU phiên bản 3 (GNU General Public License v3).  Văn bản của giấy
phép nằm trong tệp `COPYING`.

## Bản quyền

Bản quyền 2012-2013 © thuộc về Nguyễn Hà Dương <cmpitgATgmaildotcom>
