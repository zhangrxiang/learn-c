/*
 * 练习题 2.65
 *
 * Return 1 when x contains an even number of 1s; 0 otherwise.
 * Assume w=32
 *
 * 解决这个问题的关键是，我们利用了异或运算的一个属性：相同的位异或结果为 0。异或
 * 可以看作没有进位的加法。
 *
 * 我们现在可以假定 int 的宽度为 32 位。如果我们把高 16 位和底 16 位取异或，那么
 * 相同的的位会变为 0。也就是说，两个有 1 的相同的位变为 0 了。所有余下来的位都是
 * 取异或时两个位级表示不相同的。依次类推，最终我们将会在第 0 位得到一个数。如果
 * 这个数是 0 的话，那么就说明这个整数具有偶数个 1（0 也是偶数）；如果是 1 的话，
 * 说明这个整数具有奇数个 1。
 *
 * 我们只需要将最终的结果和 1 进行与运算，就可以判断这个整数是有奇数个 1 还是偶数
 * 个 1 了。
 *
 * 在解决这个问题之前，我曾经想过把 x 变为 00...0011...11 这样的形式。还有将 x 左
 * 移和右移，然后进行与运算。
 *
 * 最终想到的这个解决方法，是我在想对两个数进行或运算和与运算之后。或运算将所有有
 * 1 的位保存下来，而与运算将所有有相同的 1 的位保存下来。如果将或运算和与运算的
 * 结果保存下来，我们就得到了唯一具有 1 的所有位。消去的 1 都是成对消去的，而保留
 * 下来的，都是不成对的。而我们如果能够这样进行运算知道只剩下一位的话，那么就可以
 * 判断奇偶数了。然后，我们会发现这样的运算性质正好是异或运算所具有的。
 */
int even_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    /* 注意：在第 0 位之外的位，值不一定为 0 */
    return !(x & 1);
}
