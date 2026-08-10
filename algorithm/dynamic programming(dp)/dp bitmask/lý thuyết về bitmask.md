\- Bitmask là kỹ thuật sử dụng biểu diễn nhị phân của một số nguyên để đại diện cho một tập hợp (set).

\- các thao tác bitmask cơ bản



|thao tác|code|Ý nghĩa|
|-|-|-|
|Kiểm tra bit thứ i có bật không|(mask \& (1 << i)) != 0|Trả về true nếu phần tử $i$ đang ở trong tập hợp.|
|Bật bit thứ i|mask \| (1 << i)|Thêm phần tử $i$ vào tập hợp.|
|Tắt bit thứ i|mask \& \~(1 << i)|Xóa phần tử $i$ khỏi tập hợp.|
|Đảo bit thứ i|mask ^ (1 << i)|Nếu đang có thì xóa, chưa có thì thêm.|
|Đếm số lượng bit 1Đếm số lượng bit 1|\_\_builtin\_popcount(mask)|Đếm xem tập hợp hiện tại đang có bao nhiêu phần tử (C++).|
|Lấy bit 1 thấp nhất|\_\_builtin\_ctz(mask) hoặc mask \& -mask|lấy bit 1 có giá trị bé nhất của (C++)|



