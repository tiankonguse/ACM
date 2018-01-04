struct Rectangle {
    int min[2], max[2];

    Rectangle() {
        min[0] = min[1] = INT_MAX;
        max[0] = max[1] = INT_MIN;
    }

    void add(const Point &p) {
        for (int i = 0; i < 2; ++ i) {
            min[i] = std::min(min[i], p[i]);
            max[i] = std::max(max[i], p[i]);
        }
    }
};

long long Point::to(const Rectangle &r) const {
    const Point &p = *this;
    long long ret = 0;
    for (int i = 0; i < 2; ++ i) {
        ret += sqr(std::min(std::max(p[i], r.min[i]), r.max[i]) - p[i]);
    }
    return ret;
}

std::vector <int> order;
int seperator[N << 1];
Rectangle rectangles[N << 1];

int get_id(int l, int r) {
    return l + r | l != r;
}

int pivot;

bool compare(int i, int j) {
    if (points[i][pivot] != points[j][pivot]) {
        return points[i][pivot] < points[j][pivot];
    }
    return i < j;
}

void build(int l, int r, int type) {
    int id = get_id(l, r);
    rectangles[id] = Rectangle();
    for (int i = l; i <= r; ++ i) {
        rectangles[id].add(points[order[i]]);
    }
    if (l < r) {
        int m = l + r >> 1;
        pivot = type;
        std::nth_element(order.begin() + l, order.begin() + m, order.begin() + r + 1, compare);
        seperator[id] = order[m];
        build(l, m, type ^ 1);
        build(m + 1, r, type ^ 1);
    }
}

std::priority_queue <std::pair <long long, int> > answer;

void query(int l, int r, int type) {
    const Point &p = points[n];
    int id = get_id(l, r);
    if (SIZE(answer) == 2 && p.to(rectangles[id]) > answer.top().first) {
        return;
    }
    if (l == r) {
        answer.push(std::make_pair((p - points[order[l]]).norm2(), order[l]));
        if (SIZE(answer) > 2) {
            answer.pop();
        }
    } else {
        int m = l + r >> 1;
        pivot = type;
        int dir = compare(seperator[id], n);
        if (dir) {
            query(l, m, type ^ 1);
        } 
        query(m + 1, r, type ^ 1);
        if (!dir) {
            query(l, m, type ^ 1);
        } 
    }
}
