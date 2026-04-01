# linear search: a0 = dizi adresi, a1 = eleman sayisi, a2 = aranan
main:
    addi a1, zero, 8      # n = 8
    addi a2, zero, 42     # aranan = 42
    addi t0, zero, 0      # i = 0
loop:
    bge  t0, a1, notfound # i >= n ise bulunamadi
    slli t1, t0, 2
    add  t1, a0, t1       # &arr[i]
    lw   t2, 0(t1)        # arr[i]
    beq  t2, a2, found    # arr[i] == aranan ise bulundu
    addi t0, t0, 1        # i++
    j    loop
found:
    mv   a0, t0           # indeksi dondur
    ret
notfound:
    addi a0, zero, -1     # -1 dondur
    ret
