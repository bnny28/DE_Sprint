import re


def is_palindrome(text: str) -> bool:
    text_without_space = re.sub(r"\s+", "", text)
    return text_without_space == text_without_space[::-1]


if __name__ == '__main__':
    assert is_palindrome('taco cat')
    assert is_palindrome('rotator')
    assert not is_palindrome('black cat')
    print("OK")
