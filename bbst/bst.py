# -*- coding: utf-8 -*-

from bbst.bt import Entry, BinNode, BinTree


class BST(BinTree):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        # 命中节点的父亲
        self._hot = None

    @staticmethod
    def _connect34(b1, b2, b3, bb1, bb2, bb3, bb4):
        pass

    @staticmethod
    def _rotate_at(x):
        pass

    def _search_in(self, v, e):
        if not v or e == v.data:
            return v
        self._hot = v
        return self._search_in(e.lc if e < v.data else e.rc, e)

    def search(self, e):
        self._hot = None
        return self._search_in(self._root, e)

    def insert(self, e):
        raise NotImplementedError("You should implement this method in subclass.")

    def remove(self, e):
        raise NotImplementedError("You should implement this method in subclass.")


if __name__ == "__main__":
    pass
