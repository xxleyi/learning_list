# -*- coding: utf-8 -*-


class BST(object):
    def __init__(self, *args, **kwargs):
        return super().__init__(*args, **kwargs)


if __name__ == "__main__":
    from pprint import pprint

    pprint(Entry(3, 4) >= Entry(3, 5))
