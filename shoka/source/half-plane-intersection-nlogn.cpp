bool check(const Plane &u, const Plane &v, const Plane &w) {
    return intersect(u, v).in(w);
}

void build(vector <Plane> planes) {
    int head = 0;
    int tail = 0;
    for (int i = 0; i < (int)planes.size(); ++ i) {
        while (tail - head > 1 && !check(queue[tail - 2], queue[tail - 1], planes[i])) {
            tail --;
        }
        while (tail - head > 1 && !check(queue[head + 1], queue[head], planes[i])) {
            head ++;
        }
        queue[tail ++] = planes[i];
    }
    while (tail - head > 2 && !check(queue[tail - 2], queue[tail - 1], queue[head])) {
        tail --;
    }
    while (tail - head > 2 && !check(queue[head + 1], queue[head], queue[tail - 1])) {
        head ++;
    }
}
