# -*- coding: utf-8 -*-


class Tag(object):
    def __new__(cls, typ: str = "div"):
        if cls is not Tag:
            raise Exception("all sub tag type objects must be created by Tag class.")
        cls = globals()[typ.capitalize()]
        assert hasattr(cls, "tag")
        return object.__new__(cls)

    def get_tag(self):
        return self.tag


class Image(Tag):
    tag = "<img></img>"


class Input(Tag):
    tag = "<input></input>"


class Li(Tag):
    tag = "<li></li>"


class Br(Tag):
    tag = "<br />"


class Div(Tag):
    tag = "<div></div>"


if __name__ == "__main__":
    print(Tag().get_tag())
    tags = ["image", "input", "li", "div", "br"]
    for t in tags:
        print(Tag(t).get_tag())
