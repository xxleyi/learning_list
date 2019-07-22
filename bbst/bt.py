# -*- coding: utf-8 -*-

from bbst.entry import Entry

RB_RED = 0
RB_BLACK = 1


stature = lambda x: x.height if x else -1
is_root = lambda x: not x.parent
is_lchild = lambda x: not is_root(x) and x is x.parent.lc
is_rchild = lambda x: not is_root(x) and x is x.parent.rc
has_parent = lambda x: not is_root(x)
has_lchild = lambda x: x.lc
has_rchild = lambda x: x.rc
has_child = lambda x: has_lchild(x) or has_rchild(x)
has_both_child = lambda x: has_lchild(x) and has_rchild(x)
is_leaf = lambda x: not has_child(x)
sibling = lambda x: x.parent.rc if is_lchild(x) else x.parent.lc
uncle = lambda x: sibling(x.parent)
visit = lambda x: print((x.e.key, x.e.data, x.height))


class Stack(list):
    def __init__(self, *args, **kwargs):
        return super().__init__(*args, **kwargs)

    def top(self):
        if self:
            return self[-1]


class BinNode(object):
    def __init__(self, e, parent=None, lc=None, rc=None, height=0, npl=1, color=RB_RED):
        assert isinstance(e, Entry), "e must be Entry type."
        self.e = e
        self.parent = parent
        self.lc = lc
        self.rc = rc
        self.height = height
        self.npl = npl
        self.color = color

    def __repr__(self):
        return str(self.e)

    def __eq__(self, value):
        return self.e == value.e

    def __ne__(self, value):
        return self.e != value.e

    def __lt__(self, value):
        return self.e < value.e

    def __gt__(self, value):
        return self.e > value.e

    def __le__(self, value):
        return self.e <= value.e

    def __ge__(self, value):
        return self.e >= value.e

    @property
    def size(self):
        if not self:
            return 0
        return 1 + (self.lc.size if self.lc else 0) + (self.rc.size if self.rc else 0)

    def insert_as_lc(self, e):
        b = BinNode(e, self)
        self.lc = b
        return b

    def insert_as_rc(self, e):
        b = BinNode(e, self)
        self.rc = b
        return b

    @property
    def succ(self):
        s = self
        if self.rc:
            s = rc
            while has_lchild(s):
                s = s.lc
        else:
            while is_rchild(s):
                s = s.parent
            s = s.parent
        return s

    @staticmethod
    def _visit_along_left_branch(x, s, vst):
        while x:
            vst(x)
            s.append(x.rc)
            x = x.lc

    @staticmethod
    def _go_along_left_branch(x, s):
        while x:
            s.append(x)
            x = x.lc

    @staticmethod
    def _goto_HLVFL(s):

        while x := s.top():
            if lc := x.lc:
                if rc := x.rc:
                    s.append(rc)
                s.append(lc)
            else:
                s.append(x.rc)

        s.pop()

    def trav_pre(self, vst):
        # create one stack
        s = Stack()
        x = self
        while True:
            self._visit_along_left_branch(x, s, vst)
            if not s:
                break
            x = s.pop()

    def trav_in(self, vst):
        # create one stack
        s = Stack()
        x = self
        while True:
            self._go_along_left_branch(x, s)
            if not s:
                break
            x = s.pop()
            vst(x)
            x = x.rc

    def trav_post(self, vst):
        # create one stack
        s = Stack()
        x = self
        s.append(x)
        while s:
            if s.top() is not x.parent:
                self._goto_HLVFL(s)
            x = s.pop()
            vst(x)

    def trav_level(self, vst):
        for i in range(self.height + 1):
            self._visit_tree_at_level(self, i, vst)

    def _visit_tree_at_level(self, tree, level, vst):
        if level == 0:
            vst(tree)
        if lc := tree.lc:
            self._visit_tree_at_level(lc, level - 1, vst)
        if rc := tree.rc:
            self._visit_tree_at_level(rc, level - 1, vst)


class BinTree(object):
    def __init__(self):
        self._size = 0
        self._root = None

    def __str__(self):
        s_list = []

        def visit(x):
            s_list.append(" " * 4 * self.depth(x) + str(x.e))

        self.trav_pre(visit)
        return "\n".join(s_list)

    @property
    def size(self):
        return self._size

    def depth(self, x):
        level = 0
        root = self._root
        while x is not root:
            level += 1
            x = x.parent
        return level

    @property
    def empty(self):
        return not self._root

    @property
    def root(self):
        return self._root

    def insert_as_root(self, e: Entry) -> BinNode:
        self._root = BinNode(e)
        self.update_height_above(self._root)
        self._size += 1
        return self._root

    def insert_as_lc(self, x: BinNode, e: Entry) -> BinNode:
        x.lc = BinNode(e, x)
        self.update_height_above(x.lc)
        self._size += 1
        return x.lc

    def insert_as_rc(self, x: BinNode, e: Entry) -> BinNode:
        x.rc = BinNode(e, x)
        self.update_height_above(x.rc)
        self._size += 1
        return x.lc

    def attach_as_lc(self, x: BinNode, S) -> BinNode:
        x.lc = S.root
        if x.lc:
            x.lc.parent = x
        self._size += S.size
        self.update_height_above(x)
        del S._root

    def attach_as_rc(self, x: BinNode, S) -> BinNode:
        x.rc = S.root
        if x.rc:
            x.rc.parent = x
        self._size += S.size
        self.update_height_above(x)
        del S._root

    def remove(self, x: BinNode) -> int:
        self._set_from_parent_to_here_to_be_none(x)
        self.update_height_above(x.parent)
        n = self._remove_at(x)
        self._size -= n
        return n

    def _remove_at(self, x: BinNode) -> int:
        if not x:
            return 0
        n = 1 + self._remove_at(x.lc) + self._remove_at(x.rc)
        return n

    def secede(self, x: BinNode):
        self._set_from_parent_to_here_to_be_none(x)
        self.update_height_above(x.parent)
        S = BinTree()
        S._root = x
        x.parent = None
        S._size = x.size
        self._size -= S._size
        return S

    def _set_from_parent_to_here_to_be_none(self, x):
        if is_root(x):
            self._root = None
        elif is_lchild(x):
            x.parent.lc = None
        else:
            x.parent.rc = None

    def trav_pre(self, vst):
        if self._root:
            self._root.trav_pre(vst)

    def trav_in(self, vst):
        if self._root:
            self._root.trav_in(vst)

    def trav_post(self, vst):
        if self._root:
            self._root.trav_post(vst)

    def trav_level(self, vst):
        if self._root:
            self._root.trav_level(vst)

    def update_height(self, x: BinNode) -> int:
        x.height = 1 + max(stature(x.lc), stature(x.rc))
        return x.height

    def update_height_above(self, x: BinNode) -> None:
        while x:
            self.update_height(x)
            x = x.parent


def main():

    from copy import deepcopy

    t = BinTree()
    t.insert_as_root(Entry(1, "I am one"))
    t.insert_as_lc(t.root, Entry(2, "I am two"))
    t.insert_as_rc(t.root, Entry(3, "I am three"))
    t.insert_as_lc(t.root.lc, Entry(4, "I am four"))
    temp_lc = deepcopy(t)
    temp_rc = deepcopy(t)
    t.attach_as_lc(t.root.lc.lc, temp_lc)
    t.attach_as_rc(t.root.lc.lc, temp_rc)
    t.remove(t.root.lc.lc.rc)
    subtree = t.secede(t.root.lc.lc.lc)

    assert is_root(t.root)
    assert is_lchild(t.root.lc)
    assert is_rchild(t.root.rc)
    assert not isinstance(subtree, BinNode)
    assert isinstance(subtree, BinTree)

    print("tree size is", t.size)

    print("mind node format:\n", t)

    print("\npre order trav:")
    t.trav_pre(visit)

    print("\nin order trav:")
    t.trav_in(visit)

    print("\npost order trav:")
    t.trav_post(visit)

    print("\nlevel order trav:")
    t.trav_level(visit)


if __name__ == "__main__":

    main()
