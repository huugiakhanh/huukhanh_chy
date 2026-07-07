(\*) Khi nào thì có thể lazy-update

Segment tree là cấu trúc dữ liệu dùng để xử lý các truy vấn, mà mỗi truy vấn tác dụng lên một đoạn liên tiếp.

Các truy vấn chia làm hai loại: truy vấn hỏi và truy vấn cập nhật

\+ Nếu chỉ có truy vấn hỏi trên đoạn liên tiếp, còn mỗi truy vấn cập nhật chỉ tác động lên một điểm thì ta không cần lazy-update

\+ Ta chỉ cần lazy-update khi một truy vấn cập nhật tác động lên một đoạn liên tiếp các phần tử.

Điều kiện cần đầu tiên

Điều kiện cần: Để có thể lazy-update được thì truy vấn cập nhật phải có tính chất: ta có thể "ghép" hai truy vấn cập nhật lại để được một truy vấn cập nhật đồng dạn





(\*) Xác định thông tin được lưu ở mỗi nút

Sau khi đã thỏa mãn điều kiện cần trên, ta phải xác định các thông tin được lưu trong mỗi nút của Segment Tree. Nhắc lại, mỗi nút i trên Segment Tree quản lý các phần tử trong đoạn \[l, r] nào đó. Bao gồm:

Nút gốc: chỉ số 1, quản lý toàn bộ (đoạn \[1, n])

Với mỗi nút i quản lý đoạn \[l, r]:

&#x09;Nếu l = r (vùng quản lý chỉ có 1 phần tử): i là nút lá

&#x09;Nếu l < r (vùng quảnl ý có > 1 phần tử: i có hai con

&#x09;	Con trái: chỉ số 2 \* i, quản lý vùng \[l, m]

&#x09;	Con phải: chỉ số 2 \* i + 1, quản lý vùng \[m + 1, r]

&#x09;(m = (l + r) / 2)



Thông tin được lưu ở mỗi nút trên Segment Tree được chia làm 3 loại:

\- Loại 1: Thông tin dùng để tính các kết quả trong các truy vấn hỏi

\- Loại 2: Thông tin dùng để lazy-update

\- Loại 3: Thông tin cố định ở mỗi nút (thông tin này được tính trước ngay từ đầu, không bao giờ bị thay đổi)



Các nguyên tắc xác định thông tin được lưu ở mỗi nút:

\- Truy vấn hỏi hỏi cái gì, trên cây phải thông tin loại 1 về cái đó.

\- Ngoài ra, có thể phải bổ sung thêm các thông tin loại 1 khác. Các thông tin loại 1 này đảm bảo thao tác push-up có thể thực hiện được (có thể tính được thông tin của nút cha dựa trên hai nút con)

\- Thông tin loại 2 có dạng giống như thao tác cập nhật

\- Thông tin loại 1 phải đảm bảo, khi mọi phần tử trong vùng quản lý cùng bị thay đổi bởi thao tác cập nhật, ta có thể tính nhanh lại thông tin loại 1 này.

&#x09;Nói cách khác, khi xét nút i trên SegmentTree \[l, r]; ta cần giải quyết vấn đề: Nếu cả đoạn \[l, r] đều bị thay đổi bởi thao tác cập nhật, thì ta có thể tính nhanh lại được các thông tin loại 1 ở nút i hay không?



Chú ý:

\- Thao tác push-up chỉ liên quan đến các thông tin loại 1, không liên quan đến thông tin loại 2. Cụ thể, ta sử dụng thông tin loại 1 ở nút chỉ số 2\*i và 2\*i+1 để tính thông tin loại 1 của nút i

\- Thao tác push-down: Sử dụng thông tin loại 2 của nút cha (nút i) cập nhật cho thông tin loại 1 và thông tin loại 2 ở hai nút con (2 \* i và 2 \* i + 1). Khi kết thúc hàm push-down, ta xóa thông tin loại 2 ở nút cha.



