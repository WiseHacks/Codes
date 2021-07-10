/*
	question : Given a string, and k - flip bits of subarray of size k,
	is it possible to turn all the bits off..
	solution - p is parrtial sum, which basically keeps track of number of flips done till now,
	so for example, if we find 1, then we increment i+1'th(saying we fliped the ith so no of flips for i+1 is incremented), and we decrement i+k'th because,
	flip is done upto next k indices, so we need to decrement that index so that we can have exact number of flips done
	it is obvious that if number of flips done which is p[i]+p[i-1] = (till before i + the next)
	is even and si is '1' then we need an flip, and if odd and si = '0';we need a flip;

	Learned : 
	Whenever for any index you have to flip next few index, we can use partial sum and build prefix sum
*/
void solve() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	vi p(n + 1);
	int cnt = 0;
	FOR(i, 1, n + 1) {
		p[i] += p[i - 1];
		if (i + k <= n) {
			cout << "Not Possible\n";
			rt;
		}
		if (p[i] % 2 == 0) {
			if (s[i - 1] == '1') {
				p[i + 1]++;
				p[i + k]--;
				cnt++;
			}
		}
		else {
			if (s[i - 1] == '0') {
				p[i + 1]++;
				p[i + k]--;
				cnt++;
			}
		}
	}
	vecout(p, n + 1, 1);

}
