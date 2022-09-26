def check_brackets(text: str) -> bool:
    pair = []
    for char in text:
        if char in ["(", "{", "["]:
            pair.append(char)
        elif (char == ")" and "(" not in pair) \
                or (char == "}" and "{" not in pair) \
                or (char == "]" and "[" not in pair):
            return False
        elif char == ")":
            pair.remove("(")
        elif char == "}":
            pair.remove("{")
        elif char == "]":
            pair.remove("[")
    return False if pair else True


if __name__ == '__main__':
    assert check_brackets("[{}({})]")
    assert not check_brackets("{]")
    assert not check_brackets("{")
    assert not check_brackets("}{")
    print("OK")
