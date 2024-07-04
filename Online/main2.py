def gen(dig, curr='', res=[]):
    if curr:
        res.append(int(curr))
    for i in range(len(dig)):
        new_curr = curr + str(dig[i])
        rem = dig[:i] + dig[i + 1:]
        gen(rem, new_curr, res)
    return res

input_num = input()
dig_list = [int(digit) for digit in input_num]
combinations = gen(dig_list)
combinations.sort()
for combination in combinations:
    print(combination)
