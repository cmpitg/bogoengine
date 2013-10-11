# bogoengine

**Chú ý**: Nhánh phát triển sử dụng Chicken Scheme bị đình lại do tồn tại
  [vấn đề chưa giải quyết được](https://github.com/cmpitg/bogoengine/issues/7)
  trong quá trình hỗ trợ
  [Firefox OS](http://www.mozilla.org/en-US/firefox/os/).  Nhánh này có thể
  được quay lại trong tương lai khi
  [Emscripten](https://github.com/kripken/emscripten) và quá trình sinh code
  của Chicken Scheme tốt hơn.

Đây là nhánh phát triển thí nghiệm, sử dụng
[Chicken Scheme](http://call-cc.org).

## Giới thiệu

*bogoengine* là một thư viện gõ tiếng Việt.

Mục đích của *bogoengine* là được sử dụng bởi *lập trình viên*, nhằm
tích hợp với các chương trình cung cấp input method (như
[Ibus](http://code.google.com/p/ibus/),
[SCIM](http://sourceforge.net/projects/scim/), ...)

## Kênh thông tin

* Trang chủ: <http://reference-error.org/projects/bogoengine>

* Mail group **phát triển** *bogoengine*:
  <bogoengine-dev@googlegroups.com>, subscribe tại giao diện web
  [Google Group](http://groups.google.com/group/bogoengine-dev/).

## Tài liệu

Tài liệu cho người sử dụng và người phát triển nằm trên
[wiki của dự án](https://github.com/cmpitg/bogoengine/wiki) tại
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

## Yêu cầu biên dịch

* [Chicken Scheme](http://call-cc.org/) 4.7.0+ phục vụ nhu cầu biên dịch.

* [GCC](http://gcc.gnu.org) 4+ biên dịch các file nguồn C, sản phẩm của trình
  biên dịch Chicken.

* [Ruby](http://ruby-lang.org) 1.9+ chạy các script.

* Ruby gems:
  - [Maruku](https://github.com/bhollis/maruku) 0.7+ để biên dịch Markdown
  - erb để biên dịch template thành Markdown

## Chú ý

* Nhánh `Chicken` vừa là nhánh thử nghiệm *bogoengine* trên Scheme, vừa là
  nhánh thử nghiệm
  [literate programming](http://en.wikipedia.org/wiki/Literate_programming).

* Tất cả mọi thay đổi và quy trình xử lý đều được mô tả thành tài liệu.

## Giấy phép xuất bản

*bogoengine* được xuất bản dưới các điều khoản của Giấy phép Công cộng
GNU phiên bản 3 (GNU General Public License v3).  Văn bản của giấy
phép nằm trong tệp `COPYING`.

## Bản quyền

Bản quyền 2013 © thuộc về Nguyễn Hà Dương <cmpitgATgmaildotcom>
