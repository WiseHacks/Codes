int INF = 1e10;
vec<ii> ad[20]; vec<vi> d(20, vi(20, INF));
int n, m;
void fun() {
	FOR(i, 1, n + 1) {
		d[i][i] = 0;
		for (auto k : ad[i]) {
			d[i][k.FF] = k.SS;
		}
	}
	FOR(k, 1, n + 1) {
		FOR(i, 1, n + 1) {
			FOR(j, 1, n + 1) {
				if (d[i][k] < INF && d[k][j] < INF) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	FOR(i, 1, n + 1) {
		FOR(j, 1, n + 1)cout << d[i][j] << " ";
		cout << endl;
	}
}
