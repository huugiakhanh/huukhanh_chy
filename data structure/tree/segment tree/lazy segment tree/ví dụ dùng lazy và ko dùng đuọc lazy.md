Ví dụ 1: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:

(1) UPDATE l r c: Gán a\[i] += c với mọi i từ l đến r

(2) SUM l r: Tính tổng a\[l] + a\[l + 1] + ... + a\[r]



Bài này thỏa mãn điều kiện cần của lazy-update: Hai truy vấn có thể được "ghép" lại làm 1

\+ Truy vấn 1: tăng thêm 3 đơn vị

\+ Truy vấn 2: tăng thêm 5 đơn vị

=> ghép lại thành một truy vấn tăng thêm 8 đơn vị.



Ví dụ 2: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:

(1) SET l r c: Gán a\[l] = a\[l + 1] = ... = a\[r] = c

(2) MAX l r: Tìm max(a\[l], a\[l + 1], ..., a\[r])



Bài này thỏa mãn điều kiện cần của lazy-update: Hai truy vấn có thể được "ghép" lại làm 1

\+ Truy vấn 1: gán bằng 3

\+ Truy vấn 2: gán bằng 5

=> gộp hiệu ứng của hai truy vấn này lại, ta được một truy vấn là "gán bằng 5"



Ví dụ 3: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:

(1) UPDATE l r x y:

&#x09;Gán a\[l] += x, a\[l + 1] += x + y, a\[l + 2] += x + 2 \* y, ..., 

&#x09;Gán a\[r] += x + (r - l) \* y

&#x09;Tổng quát: Gán a\[i] += x + (i - l) \* y với mọi i từ l đến r





(2) SUM l r: Tính tổng a\[l] + a\[l + 1] + ... + a\[r]



Thao tác UPDATE này vẫn thỏa mãn điều kiện cần ở trên, bởi vì, tổng 2 cấp số cộng là một cấp số cộng.



Truy vấn 1: l r x1 y1: lượng tăng ở các vị trí là

&#x09;x1	x1 + y1	x1 + 2 \* y1		x1 + 3 \* y1		x1 + 4 \* y1 	...

Truy vấn 2: l r x2 y2: lượng tăng ở các vị trí

&#x09;x2	x2 + y2	x2 + 2 \* y2		x2 + 3 \* y2		x2 + 4 \* y2 	...



Tổng lượng tăng theo từng vị trí là:

&#x09;(x1 + x2)	(x1 + x2) + (y1 + y2)	(x1 + x2) + 2 \* (y1 + y2)

&#x09;(x1 + x2) + 3 \* (y1 + y2)



Như vậy, khi gộp hiệu ứng của 2 truy vấn (x1, y1) và (x2, y2) ta được một truy vấn cùng dạng với tham số (x1 + x2) và (y1 + y2)



Ví dụ 4: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:

(1) UPDATE l r x y:

&#x09;Gán a\[l] += x, a\[l + 1] += x \* y, a\[l + 2] += x \* y^2, a\[l + 3] += x \* y^3, ...

&#x09;Gán a\[r] += x \* y^(r - l)

&#x09;Tổng quát: Gán a\[i] += x \* y^(i - l) với mọi i từ l đến r





(2) SUM l r: Tính tổng a\[l] + a\[l + 1] + ... + a\[r]



Truy vấn 1: l r x1 y1, lượng tăng theo từng phần tử là

&#x09;x1	x1\*y1		x1\*y1^2	x1\*y1^3	...

Truy vấn 2: l r x2 y2, lượng tăng theo từng phần tử là

&#x09;x2	x2\*y2		x2\*y2^2	x2\*y2^3	...



Gộp "hiệu ứng" của hai thao tác cập nhật này lại, ta có tổng lượng tăng thêm theo từng vị trí là:

&#x09;x1+x2		x1\*y1+x2\*y2		x1\*y1^2+x2\*y2^2		x1\*y1^3+x2\*y2^3

Trong trường hợp này, ta không thể gộp hiệu ứng của hai thao tác cập nhật trở thành một thao tác đồng dạng, do đó, bài toán này không thể giải được bằng lazy-update.



Ví dụ 5: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:

(1) UPDATE l r x:

&#x09;Gán a\[l] += x, a\[l + 1] += x\*2, a\[l + 2] += x\*2^2, a\[l + 3] += x\*2^3, ... 

&#x09;Gán a\[r] += x\*2^(r - l)

&#x09;Tổng quát: Gán a\[i] += x \* 2^(i - l) với mọi i từ l đến r



(2) SUM l r: Tính tổng a\[l] + a\[l + 1] + ... + a\[r]



Thao tác UPDATE trong ví dụ 5 giống như ở ví dụ 4 nhưng y = 2 trong mọi thao tác



Truy vấn 1: l r x1, lượng tăng theo từng phần tử là

&#x09;x1	x1\*2		x1\*2^2	x1\*2^3	...

Truy vấn 2: l r x2, lượng tăng theo từng phần tử là

&#x09;x2	x2\*2		x2\*2^2	x2\*2^3	...



Tổng lượng tăng theo từng vị trí sau hai thao tác cập nhật là

&#x09;(x1 + x2)	(x1 + x2) \* 2	(x1 + x2) \* 2^2		(x1 + x2) \* 2^3



Như vậy, gộp hiệu ứng của 2 thao tác cập nhật trên, ta được một thao tác cập nhật với tham số là (x1 + x2)	

