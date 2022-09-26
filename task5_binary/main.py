def multiplication_binary(x: str, y: str) -> str:
    return '{0:b}'.format(int(x, 2) * int(y, 2))


if __name__ == '__main__':
    assert multiplication_binary("111", "101") == "100011"
    print("OK")
