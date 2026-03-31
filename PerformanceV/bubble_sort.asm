# bubble sort: a0 = dizi adresi, a1 = eleman sayisi
main:
    addi a1, zero, 5      # n = 5
    addi t0, zero, 0      # i = 0
outer:
    addi t1, a1, -1
    bge  t0, t1, done     # i >= n-1 ise bitir
    addi t2, zero, 0      # j = 0
inner:
    sub  t3, t1, t0
    bge  t2, t3, next     # j >= n-1-i ise dis donguye
    slli t4, t2, 2
    add  t4, a0, t4       # &arr[j]
    lw   t5, 0(t4)        # arr[j]
    lw   t6, 4(t4)        # arr[j+1]
    ble  t5, t6, skip     # arr[j] <= arr[j+1] ise atla
    sw   t6, 0(t4)        # swap
    sw   t5, 4(t4)
skip:
    addi t2, t2, 1        # j++
    j    inner
next:
    addi t0, t0, 1        # i++
    j    outer
done:
    ret
