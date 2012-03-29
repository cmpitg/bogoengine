# BoGoEngine

## Giới thiệu

**BoGoEngine** là một thư viện sử dụng cho việc gõ tiếng Việt.  **BoGoEngine**
được viết bằng ngôn ngữ C++, với paradigm gần functional programming nhất có
thể.

## Lịch sử

Vào khoảng tháng 02 năm 2012, phong trào và văn hóa Phần mềm Tự do Nguồn mở
(Free and Open Source - FOSS) ở Việt Nam phát triển có nhiều bước phát triển
rất mạnh mẽ, đánh dấu bằng sự ra đời của *Câu lạc bộ Phần mềm Tự do Nguồn mở
Việt Nam* (Vietnam Free and Open Source Association - VFOSSA) vào tháng
01/2012, cùng sự gia tăng số lượng người sử dụng các bản phân phối GNU/Linux.
Nhu cầu sử dụng tiếng Việt trên GNU/Linux cũng vì vậy mà khắt khe hơn.  Tại
thời điểm đó, Việt Nam có 3 bộ gõ tiếng Việt trên GNU/Linux được biết đến
nhiều nhất:

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
  vẫn đang được phát triển.

## Nguyên nhân ra đời

### Yêu cầu của việc gõ tiếng Việt trên GNU/Linux

Bộ gõ tiếng Việt trên GNU/Linux cần đảm bảo các yếu tố sau:

* (1) Là FOSS.
* (2) Sẵn có trên mọi bản phân phối GNU/Linux.
* (3) Có IM cho các IM platform/framework mặc định phổ biến nhất hiện nay:
  SCIM và IBus.
* (4) Tài liệu cho **người sử dụng** và **người phát triển** phải rõ ràng, chăm
  sóc cẩn thận.
* (5) Mã nguồn trong sáng, có convention, guideline rõ ràng.
* (6) Chạy ổn định, dễ dùng.
* (7) Hỗ trợ các bảng mã (UTF-8, UTF-16, TCVN 3, VNI, VIQR) và cách gõ phổ
  biến nhât (Telex, Simple Telex, VNI).

FIXME: Which one fails which?

## So sánh với Unikey Engine

## Yêu cầu

### Cho việc biên dịch

* CMake 2.6+
* GoogleTest
* gtkmm 2.4

### Cho việc sử dụng

## Giấy phép xuất bản (License)

Toàn bộ mã nguồn của *BoGoEngine* cùng tất cả các tài nguyên đi kèm đều được
phát hành dưới các quy định ghi trong Giấy phép Công cộng GNU, phiên bản 3.0
(GNU General Public License v3.0).  Xem tệp *COPYING* để biết thêm chi tiết.
