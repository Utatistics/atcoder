#include <iostream>
#include <priority_queue>

void dijkstra() {
    int i, j;
    int u, v;
    int min_d;

    // initialization
    for ( i = 0; i < n; i ++ ) {
        d[i] = INFTY;
        s[i] = TODO;
    }

    d[0] = 0; // set 0 to be the first node
    while ( 1 ) {
        min_d = INFTY;
        u =  -1;

        // find u
        for (i = 0; i < n; i++ ) {
            if ( d[i] < min_d && s[i] != DONE ) {
                min_d = d[i];
                u = i;
            }
        }

        if ( u == -1 ) break; // break loop if no valid u found

        s[u] = DONE;

        // visit v and update memory
        for (v = 0; v < n; v++) { // perform relaxation
            if ( d[u] + M[u][v] < d[v] && s[v] != DONE ) {
                d[v] = d[u] + M[u][v];
            }
        }
    }
}

int main () {
    
    return 0;
}
