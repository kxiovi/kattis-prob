/*
References: 
kactl - Treap
https://nordic.icpc.io/ncpc2012/

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


struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1;
	Node(int val) : val(val), y(rand()) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (n->val >= k) { // "n->val >= k" for lower_bound(k)
		auto [L,R] = split(n->l, k);
		n->l = R;
		n->recalc();
		return {L, n};
	} else {
		auto [L,R] = split(n->r,k); // and just "k"
		n->r = L;
		n->recalc();
		return {n, R};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		return l->recalc(), l;
	} else {
		r->l = merge(l, r->l);
		return r->recalc(), r;
	}
}

Node* ins(Node* t, Node* n, int pos) {
	auto [l,r] = split(t, pos);
	return merge(merge(l, n), r);
}

ll inversions(vi& v) {
    Node* root = nullptr;
    ll ans = 0;
    for (int i : v) {
        auto[g, r] = split(root, i);
        ans = ans + cnt(r);
        root = merge(merge(g, new Node(i)), r);
    }
    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(0);

    int n;
	cin >> n;

    vi curr(n);
    vi boss(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        curr[i] = a;
    }

    for (int i = 0; i < n; ++i) {
        int a; 
        cin >> a;
        boss[i] = a;
    }

    vi temp = boss;
    reverse(temp.begin(), temp.end());

    if (curr == temp) {
        cout << "Impossible";
        return 0;
    }

    ll q = inversions(curr);
    ll w = inversions(boss);
    if (abs(q-w) % 2 == 0) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

    
}
