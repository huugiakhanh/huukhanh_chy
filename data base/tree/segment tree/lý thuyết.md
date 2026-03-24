\- Segment Tree là cấu trúc dữ liệu dạng cây nhị phân, mỗi node lưu thông tin của một đoạn của mảng. Node gốc quản lý toàn bộ mảng \[1..n], mỗi node chia đôi đoạn cho hai con — trái quản lý nửa trái, phải quản lý nửa phải.



\- Mỗi node lưu tổng của đoạn con. Node v quản lý đoạn \[l,r], hai con là 2v (trái, \[l,mid]) và 2v+1 (phải, \[mid+1,r]). Cây có tối đa 4n node nên mảng tree\[] cần kích thước 4\*MAXN.



\- Độ phức tạp không gian là O(4n)



\- Độ phức tạp khi ứng dụng với các thuân toán đồ thị

|Bài toán|Kỹ thuật|Độ phức tạp|
|-|-|-|
|Sum/min/max trên đường đi u→v<br />Update/query cả cây con<br />LCA nhiều truy vấn<br />Thêm/xóa cạnh offline, hỏi liên thông<br />Cạnh tồn tại trong đoạn thời gian|HLD + Seg tree<br />Euler tour + Seg tree<br />Euler tour + RMQ<br />Seg tree theo thời gian + DSU rollback<br />Seg tree of graphs|O(log²n)<br />O(log n)<br />O(1) hoặc O(log n)<br />O(n log²n)<br />O(n log n)|



