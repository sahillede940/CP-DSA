def find_liars(n, statements):
    for L in range(n+1):
        true_count = sum(1 for statement in statements if statement >= L)
        false_count = n - true_count
        if L <= true_count and L > false_count:
            print(L)
    print(-1)
