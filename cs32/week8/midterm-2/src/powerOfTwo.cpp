int powerOfTwo(int x){
    if (x == 0) {
        return 1;
    }

    // 2^(x-1) + 2^(x-1) = 2^1 * 2^(x-1) = 2^(x)
    return powerOfTwo(x-1) + powerOfTwo(x-1);
}
