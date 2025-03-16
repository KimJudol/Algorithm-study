#include <stdio.h>
#include <stdlib.h>

// Backjoon https://www.acmicpc.net/problem/1389

#define INF 1000000

int n, m;
int relation[101][101] = {0,};
int bridge[101][101] = {0,};

void floyd_warshall() {
    // initialize bakon
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                bridge[i][j] = 0;
            }
            else if(relation[i][j]) {
                bridge[i][j] = 1;
            }
            else {
                bridge[i][j] = INF;
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(bridge[i][j] > bridge[i][k] + bridge[k][j]) {
                    bridge[i][j] = bridge[i][k] + bridge[k][j];
                }
            }
        }
    }
}

void print_min() {
    int min_index = 0;
    int min = INF;
    for(int i = 1; i <= n; i++) {
		int kevin = 0;
        for(int j = 1; j <= n; j++) {
            kevin += bridge[i][j];
        }

        if(min > kevin) {
            min = kevin;
            min_index = i;
        }
    }

    printf("%d\n", min_index);
}

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        relation[u][v] = 1;
        relation[v][u] = 1;
    }

    floyd_warshall();
    print_min();

    return 0;
}