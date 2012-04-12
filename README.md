# BoGoEngine

## Giới thiệu

**BoGoEngine** là một thư viện sử dụng cho việc gõ tiếng Việt.  **BoGoEngine**
được viết bằng ngôn ngữ C++, với functional programming paradigm.

Mail group thảo luận các vấn đề liên quan đến việc *phát triển*
**BoGoEngine**: <bogoengine-dev@googlegroups.com>, subscribe tại giao diện web
[Google Group](http://groups.google.com/group/bogoengine-dev/).

## Lịch sử và nguyên nhân ra đời

Tại thời điểm tháng 03 năm 2012, Việt Nam có 04 bộ gõ tiếng Việt trên GNU/Linux
được biết đến nhiều nhất:

* **x-unikey** của tác giả Phạm Kim Long, lần phát hành cuối cùng là vào năm
  2006, giấy phép GPL.

* **xvnkb** của tác giả Dao Hai Lam <lam@visc-network.com>, lần phát hành cuối
  cùng vào năm 2004, giấy phép ?.

* **scim-unikey** và **ibus-unikey** là 2 input method (IM) dùng cho SCIM và
  IBus, phát triển bởi Lê Quốc Tuấn <mr.lequoctuan@gmail.com> và Lê Kiến Trúc
  <afterlastangel@ubuntu-vn.org>, với engine Unikey trích xuất từ
  **x-unikey**, giấy phép GPL.  **ibus-unikey** được sử dụng phổ biến nhất, có
  mặt mặc định trên hầu hết tất cả các bản phân phối GNU/Linux.
  **scim-unikey** phát hành lần cuối cùng vào tháng 08/2009.  **ibus-unikey**
  phát hành bản 0.6 vào tháng 01/2012 và hiện nay vẫn đang tiếp tục được phát
  triển.

Tuy nhiên cả 4 bộ gõ này đều có nhiều hạn chế, gây khó khăn cho người sử dụng,
đặc biệt với người sử dụng phổ thông.

Thông thường, bộ gõ tiếng Việt trên GNU/Linux cần đảm bảo các yếu tố sau:

* (1) Là FOSS.
* (2) Sẵn có trên mọi bản phân phối GNU/Linux.
* (3) Có IM cho các IM platform/framework mặc định phổ biến nhất hiện nay:
  SCIM và IBus.
* (4) Tài liệu cho **người sử dụng** và **người phát triển** rõ ràng, chăm sóc
  cẩn thận.
* (5) Mã nguồn trong sáng, có convention, guideline.
* (6) Chạy ổn định, dễ dùng.
* (7) Hỗ trợ các bảng mã (UTF-8, UTF-16, TCVN 3, VNI, VIQR) và cách gõ phổ
  biến nhât (Telex, Simple Telex, VNI).
* (8) Khả năng mở rộng, bảo trì, tái sử dụng cao.

**x-unikey** chỉ đáp ứng được *(1)* (với người sử dụng) và *(7)* (với người
phát triển).

**xvnkb** đáp ứng được *(1)* và *(7)*.

**scim-unikey** và **ibus-unikey** đáp ứng được *(1)*, *(2)*, *(7)* nhưng thất
bại rất lớn ở tất cả các yêu cầu còn lại.

FIXME: Thêm phân tích và dẫn chứng cụ thể với người sử dụng + người phát
triển.

**BoGoEngine** ra đời nhằm đáp ứng đầy đủ cả 8 yêu cầu này.

## Yêu cầu

### Cho việc biên dịch

* CMake 2.6+
* glibmm 2.4
* gcc 4.2+

### Cho việc sử dụng

FIXME

## Giấy phép xuất bản (License)

Toàn bộ mã nguồn của *BoGoEngine* cùng tất cả các tài nguyên đi kèm đều được
phát hành dưới các quy định ghi trong Giấy phép Công cộng GNU, phiên bản 3.0
(GNU General Public License v3.0).  Xem tệp *COPYING* để biết thêm chi tiết.

## Credit

Bản quyền (C) năm 2012 bởi:

* Dương "Yang" ヤン Nguyễn <cmpitg@gmail.com>
* Nguyễn Thành Hải <phaikawl@gmail.com>

Xin chân thành gửi lời cảm ơn đặc biệt đến:

* Ngô Trung <ndtrung4419@gmail.com>
* Hoàng Minh Thắng <hoangminhthang@xaydunghoanglong.com>
* Đàm Tiến Long <longdt90@gmail.com>
* Nguyễn Thành Hải <phaikawl@gmail.com>
