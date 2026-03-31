# fibonacci: n'inci fibonacci sayisini hesapla
# a0 = n girdi
main:
    addi a0, zero, 10     # n = 10
    addi t0, zero, 0      # fib(0) = 0
    addi t1, zero, 1      # fib(1) = 1
    addi t2, zero, 2      # i = 2
loop:
    bge  t2, a0, done     # i >= n ise bitir
    add  t3, t0, t1       # t3 = fib(i-2) + fib(i-1)
    mv   t0, t1           # t0 = t1
    mv   t1, t3           # t1 = t3
    addi t2, t2, 1        # i++
    j    loop
done:
    mv   a0, t1           # sonucu a0'a koy
    ret
