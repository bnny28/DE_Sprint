import roman

if __name__ == '__main__':
    assert roman.toRoman(3) == 'III'
    assert roman.toRoman(9) == 'IX'
    assert roman.toRoman(1945) == 'MCMXLV'
    print("OK")
