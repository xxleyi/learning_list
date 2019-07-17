# -*- coding: utf-8 -*-


class Entry:
    def __init__(self, key, data=None):
        assert isinstance(key, (str, int)), "key of Entry must be str or int type."
        self.key = key
        self.data = data

    def __eq__(self, e):
        return self.key == e.key

    def __ne__(self, e):
        return not self.__eq__(e)

    def __lt__(self, e):
        return self.key < e.key

    def __gt__(self, e):
        return self.key > e.key

    def __le__(self, e):
        return self.__lt__(e) or self.__eq__(e)

    def __ge__(self, e):
        return self.__gt__(e) or self.__eq__(e)