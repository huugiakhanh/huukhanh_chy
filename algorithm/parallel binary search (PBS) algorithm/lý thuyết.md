\-PBS: là một kỹ thuật phân tích thuật toán nâng cao trong CP. Nó được dùng để giải quyết các bài toán có nhiều truy vấn (Queries), trong đó mỗi truy vấn đều có thể giải bằng Tìm kiếm nhị phân, nhưng việc mô phỏng để kiểm tra điều kiện cho một truy vấn lại mất quá nhiều thời gian.

\-Đấu hiện nhận dạng: 

&#x09;(+) Bài toán yêu cầu trả lời Q truy vấn độc lập thường Q lên tới 1e5

&#x09;(+) Trạng thái của hệ thống thay đổi theo thời gian/bước một cách đơn điệu (monotonically)

&#x09;ví dụ: số lượng đồ vật tăng dần, lượng nước dâng lên dần.

&#x09;(+) Bạn cần tìm thời điểm nhỏ nhất (hoặc lớn nhất) để mỗi truy vấn thỏa mãn một điều kiện nào đó.



|                     Binary Search|                   Parallel Binary Search|
|-|-|
|                  O(Q \* N \* log(R\_MAX))|                      O(N \* log(R\_MAX))|



