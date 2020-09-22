---
title: 素集合データ構造(UnionFind Tree)
documentation_of: ./data_structure/unionfind.cpp
---

## UnionFind木が出題された問題
- [D-Decayed Bridges](https://beta.atcoder.jp/contests/abc120)
UnionFind木は繋がりを断つことはできないが、構成することはできるので、逆からやるやつ。
- [D-Equals](https://beta.atcoder.jp/contests/abc097)
swapすればそれらは行き来可能になるので、実質パイプ。
- [B-Union Find](https://beta.atcoder.jp/contests/atc001)
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
- [B-道路工事](https://beta.atcoder.jp/contests/arc032/)
すべての点に対して根を考えることで、グループが幾つに分かれているかを知ることができる
- [D-連結](https://beta.atcoder.jp/contests/abc049)
[解説](http://drken1215.hatenablog.com/entry/2019/06/29/182300)
二つのUnionFind木を管理して、同時に繋がっていることを根のPairを持ってmapで管理すると良い
- [D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)
[提出](https://atcoder.jp/contests/abc157/submissions/10460043)
友達関係のグルーピングに使う。sizeも用いた。
- [E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)
[提出](https://atcoder.jp/contests/abc126/submissions/10649376)
集合の数を管理するgroup_numを実装した
