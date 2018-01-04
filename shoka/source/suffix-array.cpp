int n, m, count[N], rank[N], array[N], new_rank[N][2], new_array[N], height[N];

void construct(char* string, int n) {
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; ++ i) {
        count[(int)string[i]] ++;
    }
    for (int i = 0; i < 256; ++ i) {
        count[i + 1] += count[i];
    }
    for (int i = 0; i < n; ++ i) {
        rank[i] = count[(int)string[i]] - 1;
    }
    for (int length = 1; length < n; length <<= 1) {
        for (int i = 0; i < n; ++ i) {
            new_rank[i][0] = rank[i];
            new_rank[i][1] = i + length < n ? rank[i + length] + 1 : 0;
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++ i) {
            count[new_rank[i][1]] ++;
        }
        for (int i = 0; i < n; ++ i) {
            count[i + 1] += count[i];
        }
        for (int i = n - 1; i >= 0; -- i) {
            new_array[-- count[new_rank[i][1]]] = i;
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++ i) {
            count[new_rank[i][0]] ++;
        }
        for (int i = 0; i < n; ++ i) {
            count[i + 1] += count[i];
        }
        for (int i = n - 1; i >= 0; -- i) {
            array[-- count[new_rank[new_array[i]][0]]] = new_array[i];
        }
        rank[array[0]] = 0;
        for (int i = 0; i + 1 < n; ++ i) {
            rank[array[i + 1]] = rank[array[i]] + 
                (new_rank[array[i]][0] != new_rank[array[i + 1]][0] 
              || new_rank[array[i]][1] != new_rank[array[i + 1]][1]);
        }
    }
    for (int i = 0, length = 0; i < n; ++ i) {
        if (rank[i]) {
            int j = array[rank[i] - 1];
            while (i + length < n && j + length < n 
                    && string[i + length] == string[j + length]) {
                length ++;
            }
            height[rank[i]] = length;
            if (length) {
                length --;
            }
        }
    }
}
