int n, m; // đồ thị n đỉnh, m cạnh
int dis[500][500]; // lưu khoảng cách từ i đến j
void floyd() {
    mset(dis, 0x3f);
    forr(i, 1, n) dis[i][i] = 0;
    forr(k, 1, n) { // đỉnh trung gian k
        forr(i, 1, n) {
            forr(j, 1, n) {
                if (dis[i][k] < __0x3f && dis[k][j] < __0x3f) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
                }
            }
        }
    }
}



int n, m; // đồ thị n đỉnh, m cạnh
int dis[500][500]; // lưu khoảng cách từ i đến j
int count_dis[500][500];
void floyd_count_dis() {
    mset(dis, 0x3f);
    forr(i, 1, n) dis[i][i] = 0;
    forr(k, 1, n) { // đỉnh trung gian k
        forr(i, 1, n) {
            forr(j, 1, n) {
                if (dis[i][k] != __0x3f && dis[k][j] != __0x3f) {
                    // TRƯỜNG HỢP 1: Tìm thấy đường đi NGẮN HƠN hoàn toàn
                    if (dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        // Ghi đè số lượng cách đi: Bằng (số cách i->k) x (số cách k->j)
                        count_dis[i][j] = count_dis[i][k] * count_dis[k][j];
                    } 
                    // TRƯỜNG HỢP 2: Tìm thấy đường đi BẰNG ĐÚNG đường đi ngắn nhất
                    else if (dis[i][k] + dis[k][j] == dis[i][j]) {
                        // Cộng dồn thêm số cách đi qua k
                        ll new_ways = count_dis[i][k] * count_dis[k][j];
                        count_dis[i][j] += new_ways;
                    }
                }
            }
        }
    }
}

