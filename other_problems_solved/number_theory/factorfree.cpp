/*
References: 
https://archive.algo.is/icpc/nwerc/2017/nwerc2017slides.pdf 
*/

#include <bits/stdc++.h>
using namespace std;

using ulll = __uint128_t;
using ull = uint64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int inf = 1 << 30;

const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

// get all primes up to 1e6
vi factors = eratosthenes();

// get prime factors of a value
vi getFactors(int val) {
	vi f;
	for (auto a : factors) {
		if (a * a > val) break;
		if (val % a == 0) {
			f.push_back(a);
			while (val % a == 0) {
				val /= a;
			}
		}
	} 
	if (val > 1) {
		f.push_back(val);
	}
	return f;
}

// find conflicts nearest to the left and right
// e.g. position x and y have a coprime greater than 1
unordered_map<int, set<int>> factoridx;
pii getConflicts(int factor, int index) {
	pii conflicts;
	auto it = factoridx[factor].find(index);
	if (it == factoridx[factor].begin()) {
		conflicts.first = -inf;
	} else 
	{
		conflicts.first = *prev(it);
	}

	it = next(it);
	if (it == factoridx[factor].end()) {
		conflicts.second = inf;
	} else 
	{
		conflicts.second = *it;
	}
	return conflicts;
}

vector<int> parent;
vector<int> v;
vector<vector<int>> divisors;
bool solve(int start, int end, int prev) {
	if (start > end) {
		return true;
	}
	if (start == end) {
		parent[start] = prev;
		return true;
	}
	int iter = end - start;
	for (int i = 0; i <= iter; ++i) {
		int curr;
		if (i % 2 == 0) {
			curr = start + (i / 2);
		} else {
			curr = end - (i / 2);
		}
		bool flag = true;
		for (auto& a : divisors[curr]) {
			pii p = getConflicts(a, curr);
			if (p.first >= start) {
				flag = false;
				break;
			}
			if (p.second <= end) {
				flag = false;
				break;
			}
		}
		if (flag) {
			parent[curr] = prev;
			return solve(start, curr-1, curr) && solve(curr+1, end, curr);
		}
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n; 
    cin >> n;

    // since each parent or ancestor must be coprime to it's children
    // recursively that means that the root must be coprime to all the vertices
    // factorize all the numbers in the input using modified sieve of Eratosthenes
    v.resize(n); parent.resize(n); divisors.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
		vi f = getFactors(v[i]);
		divisors[i] = f;
		for (auto& a : f) {
			factoridx[a].insert(i);
		}
    }

    
	if (solve(0, n-1, -1)) {
		for (int i = 0; i < n; ++i) {
			cout << parent[i]+1 << " ";
		}
	} else 
	{
		cout << "impossible";
	}

    
    
}
