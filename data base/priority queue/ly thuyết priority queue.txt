int main() {

    priority_queue<int> pq; // khai báo cơ bản
    // theo do pq sẽ ưu tiên phần tử to đến bé luôn ưu tiên kiểu max heap
    // nếu muốn ưu tiên phần tử bé đến lơn tức min heap ta khai bao
    priority_queue<int, vector<int>, greater<int>> pq0;; // theo kieu min heap
    // lệnh push phần tử như bth
    pq.push(5);
    pq.push(1);
    pq.push(-1);
    // vẫn có các lệnh
    pq.top(); // lấy đầu
    pq.pop(); // xóa đầu
    pq.size(); // kịch thước
    pq.empty(); // kiểm tra rỗng
    cout << pq.top() << '\n';
    // hành đợi ưu tiên, dùng trong Dijkstra
    priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
    // theo cấu túc (distance, node), ưu tiên khoảng cách min trc
    // vd nhập cơ bản
    pq1.push({0, 1});
    auto [d, u] = pq1.top();
    pq1.pop();

    while(!pq1.empty()) {
        auto [d, u] = pq1.top();
        pq.pop();
        // xử lí Dijkstra
    }
    // priority queue nâng cao
    
    // theo kiểu min heap
    struct Node{
        int x;
        bool operator < (const Node &other) const {
            return x > other.x; // min heap
        }
    };
    priority_queue<Node> pq2;

    return 0;
}