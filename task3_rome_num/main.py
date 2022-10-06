def to_roman(inp: int) -> str:
    rom_nums = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }
    res = ''
    for num, rom_num in rom_nums.items():
        while inp >= num:
            res += rom_num
            inp -= num
    return res


if __name__ == '__main__':
    assert to_roman(3) == 'III'
    assert to_roman(9) == 'IX'
    assert to_roman(1945) == 'MCMXLV'
    print("OK")
